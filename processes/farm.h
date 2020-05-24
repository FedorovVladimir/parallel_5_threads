//
// Created by vladimir on 20.05.2020.
// Ферма
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

int flourOfCycle = 0; // произведенная за цикл мука

DWORD WINAPI FarmThreadProc(PVOID arg) {
    int ping = 1000; // время одного цикла работ
    cout << "Farm start!\n";
    IntegerSemaphore endSemaphore("end_game");
    BinarySemaphore farmHasFlour("farm_has_flour");
    BinarySemaphore warehouseHasPlaceForFlour("warehouse_has_place_for_flour");
    BinarySemaphore marketHasPlaceForFlour("market_has_place_for_flour");

    while (true) {
        Sleep(ping);

        // производство муки
        flourOfCycle = 1;
        string msg = "Farm: Create 1 floor.";
        // передаем муку в запас
        if (stockFlour < maxStockFlour) {
            stockFlour += 1;
            flourOfCycle = 0;
            msg += " Transfer floor on stock\n";
        }
        // передаем единицу муки на склад
        if (flourOfCycle && warehouseHasPlaceForFlour.Down(1)) {
            flourOfCycle = 0;
            msg += " Transfer floor on warehouse\n";
        }
        // продаем единицу муки
        if (flourOfCycle && marketHasPlaceForFlour.Down(1)) {
            flourOfCycle = 0;
            msg += " Transfer floor on market\n";
        }
        // выбрасываем муку
        if (flourOfCycle) {
            flourOfCycle = 0;
            msg += " Transfer floor on trash\n";
        }
        cout << msg;
        // Если есть мука
        if (stockFlour) {
            farmHasFlour.Up();
        } else {
            farmHasFlour.Down(100);
        }

        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "Farm end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_FARM_H
