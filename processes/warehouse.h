//
// Created by vladimir on 20.05.2020.
//

#ifndef PARALLEL_5_THREADS_WAREHOUSE_H
#define PARALLEL_5_THREADS_WAREHOUSE_H

#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI WarehouseThreadProc(PVOID arg) {
    cout << "Warehouse start!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_WAREHOUSE_H
