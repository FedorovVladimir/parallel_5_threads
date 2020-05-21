//
// Created by vladimir on 20.05.2020.
//

#ifndef PARALLEL_5_THREADS_BAKERY_H
#define PARALLEL_5_THREADS_BAKERY_H

#include <iostream>
#include <windows.h>
#include "../lib/BinarySemaphore.h"
#include "../lib/IntegerChannel.h"

using namespace std;

DWORD WINAPI BakeryThreadProc(PVOID arg) {
    cout << "Bakery start!\n";
    while (true) {

    }
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_BAKERY_H
