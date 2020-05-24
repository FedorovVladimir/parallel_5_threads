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

DWORD WINAPI WarehouseThreadProc(PVOID arg) {
    cout << "Warehouse start!\n";
    IntegerSemaphore endSemaphore("end_game");

    while (true) {

        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "Warehouse end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_WAREHOUSE_H
