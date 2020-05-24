//
// Created by vladimir on 20.05.2020.
// Склад
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

DWORD WINAPI WarehouseThreadProc(PVOID arg) {
    int ping = 1000; // время одного цикла работ
    cout << "Warehouse start!\n";
    IntegerSemaphore endSemaphore("end_game");
    BinarySemaphore warehouseHasPlaceForFlour("warehouse_has_place_for_flour", 1);

    while (true) {
        Sleep(ping);


        // если место под муку есть
        if (flour < flourMax) {
            if (warehouseHasPlaceForFlour.Up()) {
                flour += 1;
                cout << "Warehouse: Get flour\n";
            }
        } else {
            warehouseHasPlaceForFlour.Down(100);
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
