//
// Created by vladimir on 20.05.2020.
//

#ifndef PARALLEL_5_THREADS_MARKET_H
#define PARALLEL_5_THREADS_MARKET_H

#include <iostream>
#include <windows.h>
#include "../lib/BinarySemaphore.h"
#include "../lib/IntegerChannel.h"

using namespace std;

DWORD WINAPI MarketThreadProc(PVOID arg) {
    cout << "Market start!\n";
    while (true) {

    }
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_MARKET_H
