//
// Created by vladimir on 20.05.2020.
//

#ifndef PARALLEL_5_THREADS_MARKET_H
#define PARALLEL_5_THREADS_MARKET_H

#include <iostream>
#include <windows.h>

using namespace std;

DWORD WINAPI MarketThreadProc(PVOID arg) {
    cout << "Market start!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_MARKET_H
