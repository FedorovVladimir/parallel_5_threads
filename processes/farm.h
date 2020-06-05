//
// Created by vladimir on 20.05.2020.
// Ферма
//
// Производит муку
// Передает муку на склад
// Продает муку на рынке
// Выбрасывает муку
//
// Выращивает овощи
// Передает овощи на склад
// Продает овощи на рынке
// Выбрасывает овощи
//

#ifndef PARALLEL_5_THREADS_FARM_H
#define PARALLEL_5_THREADS_FARM_H

#include <iostream>
#include <windows.h>
#include "../lib/IntegerChannel.h"
#include "../lib/IntegerSemaphore.h"

using namespace std;


int stockFlour = 0; // произведенная мука в запасе
int maxStockFlour = 10; // максимальная вместимость запаса муки

int flourOfCycle = 0; // произведенная мука за цикл мука


int stockVegetables = 0; // произведенные овощи в запасе
int maxStockVegetables = 10; // максимальная вместимость запаса овощей

int vegetablesOfCycle = 0; // произведенные за цикл овощи


DWORD WINAPI FarmThreadProc(PVOID arg) {
    int ping = 1000; // время одного цикла работ
    cout << "Farm start!\n";
    IntegerSemaphore endSemaphore("end_game");
    BinarySemaphore warehouseHasPlaceForFlour("warehouse_has_place_for_flour", 1);
    BinarySemaphore marketHasPlaceForFlour("market_has_place_for_flour", 1);
    BinarySemaphore warehouseHasPlaceForVegetables("warehouse_has_place_for_vegetables", 1);
    BinarySemaphore marketHasPlaceForVegetables("market_has_place_for_vegetables", 1);

    IntegerChannel howManyFlourToBakery("howManyFlourF2B");
    IntegerChannel sendFlourToBakery("sendFlourF2B");

    while (true) {
        Sleep(ping);


        // производство муки
        flourOfCycle = 1;
        string msg = "Farm: Create 1 floor. ";
        // передаем муку в запас
        if (stockFlour < maxStockFlour) {
            stockFlour += 1;
            flourOfCycle = 0;
            msg += "Transfer floor on stock.";
        }
        // передаем единицу муки на склад
        if (flourOfCycle && warehouseHasPlaceForFlour.Down(1)) {
            flourOfCycle = 0;
            msg += "Transfer floor on warehouse.";
        }
        // продаем единицу муки
        if (flourOfCycle && marketHasPlaceForFlour.Down(1)) {
            flourOfCycle = 0;
            msg += "Transfer floor on market.";
        }
        // выбрасываем муку
        if (flourOfCycle) {
            flourOfCycle = 0;
            msg += "Transfer floor on trash.";
        }


        // производство овощей
        vegetablesOfCycle = 1;
        msg += " | Create 1 vegetables. ";
        // передаем овощи в запас
        if (stockVegetables < maxStockVegetables) {
            stockVegetables += 1;
            vegetablesOfCycle = 0;
            msg += "Transfer floor on stock.";
        }
        // передаем единицу овощей на склад
        if (vegetablesOfCycle && warehouseHasPlaceForVegetables.Down(1)) {
            vegetablesOfCycle = 0;
            msg += "Transfer floor on warehouse.";
        }
        // продаем единицу овощей
        if (vegetablesOfCycle && marketHasPlaceForVegetables.Down(1)) {
            vegetablesOfCycle = 0;
            msg += "Transfer floor on market.";
        }
        // выбрасываем овощи
        if (vegetablesOfCycle) {
            vegetablesOfCycle = 0;
            msg += "Transfer floor on trash.";
        }


        cout << msg + "\n";


        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "Farm end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_FARM_H
