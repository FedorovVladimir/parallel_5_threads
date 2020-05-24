//
// Created by vladimir on 20.05.2020.
// Рынок
//

#ifndef PARALLEL_5_THREADS_MARKET_H
#define PARALLEL_5_THREADS_MARKET_H

#include <iostream>
#include <windows.h>
#include "../lib/IntegerChannel.h"
#include "../lib/IntegerSemaphore.h"

using namespace std;

DWORD WINAPI MarketThreadProc(PVOID arg) {
    int ping = 1000; // время одного цикла работ
    cout << "Market start!\n";
    IntegerSemaphore endSemaphore("end_game");

    while (true) {
        Sleep(ping);

        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "Market end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_MARKET_H
