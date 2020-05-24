//
// Created by vladimir on 20.05.2020.
// Склад
//
// Забирает излишки муки с фермы
//
// Забирает излишки овощей с фермы
//

#ifndef PARALLEL_5_THREADS_WAREHOUSE_H
#define PARALLEL_5_THREADS_WAREHOUSE_H

#include <iostream>
#include <windows.h>
#include "../lib/IntegerChannel.h"
#include "../lib/IntegerSemaphore.h"

using namespace std;


int flour = 0; // мука на складе
int flourMax = 5; // максимальное количество муки на складе


int vegetables = 0; // овощи на складе
int vegetablesMax = 3; // максимальное количество овощей на складе


DWORD WINAPI WarehouseThreadProc(PVOID arg) {
    int ping = 1000; // время одного цикла работ
    cout << "Warehouse start!\n";
    IntegerSemaphore endSemaphore("end_game");
    BinarySemaphore warehouseHasPlaceForFlour("warehouse_has_place_for_flour", 1);
    BinarySemaphore warehouseHasPlaceForVegetables("warehouse_has_place_for_vegetables", 1);

    while (true) {
        Sleep(ping);


        // если место под муку есть
        if (flour < flourMax) {
            if (warehouseHasPlaceForFlour.Up()) {
                flour += 1;
                cout << "Warehouse: Get flour\n";
            }
        } else {
            warehouseHasPlaceForFlour.Down(1);
        }


        // если место под овощи есть
        if (vegetables < vegetablesMax) {
            if (warehouseHasPlaceForVegetables.Up()) {
                vegetables += 1;
                cout << "Warehouse: Get vegetables\n";
            }
        } else {
            warehouseHasPlaceForVegetables.Down(1);
        }


        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "Warehouse end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_WAREHOUSE_H
