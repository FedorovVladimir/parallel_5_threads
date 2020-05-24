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

DWORD WINAPI FarmThreadProc(PVOID arg) {
    cout << "Farm start!\n";
    IntegerSemaphore endSemaphore("end_game");

    while (true) {

        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "Farm end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_FARM_H
