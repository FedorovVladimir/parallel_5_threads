//
// Created by vladimir on 20.05.2020.
//

#ifndef PARALLEL_5_THREADS_BAKERY_H
#define PARALLEL_5_THREADS_BAKERY_H

#include <iostream>
#include <windows.h>
#include "../lib/IntegerChannel.h"
#include "../lib/IntegerSemaphore.h"

using namespace std;

DWORD WINAPI BakeryThreadProc(PVOID arg) {
    cout << "Bakery start!\n";
    IntegerSemaphore endSemaphore("end_game");

    while (true) {
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "Bakery end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_BAKERY_H
