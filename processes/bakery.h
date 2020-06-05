//
// Created by vladimir on 20.05.2020.
// Пекарня
//

#ifndef PARALLEL_5_THREADS_BAKERY_H
#define PARALLEL_5_THREADS_BAKERY_H

#include <iostream>
#include <windows.h>
#include "../lib/IntegerChannel.h"
#include "../lib/IntegerSemaphore.h"

using namespace std;

DWORD WINAPI BakeryThreadProc(PVOID arg) {
    int ping = 1000; // время одного цикла работ
    cout << "Bakery start!\n";
    IntegerSemaphore endSemaphore("end_game");

    IntegerChannel howManyFlourToBakery("hManyFlourF2B");
    IntegerChannel sendFlourToBakery("sendFlourF2B");

    while (true) {
        Sleep(ping);

        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "Bakery end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_BAKERY_H
