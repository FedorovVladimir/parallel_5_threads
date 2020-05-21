//
// Created by vladimir on 20.05.2020.
//

#ifndef PARALLEL_5_THREADS_MEAT_PROCESSING_PLANT_H
#define PARALLEL_5_THREADS_MEAT_PROCESSING_PLANT_H

#include <iostream>
#include <windows.h>
#include "../lib/IntegerChannel.h"
#include "../lib/IntegerSemaphore.h"

using namespace std;

DWORD WINAPI MeatProcessingPlantThreadProc(PVOID arg) {
    cout << "MeatProcessingPlant start!\n";
    IntegerSemaphore endSemaphore("end_game");

    while (true) {
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "MeatProcessingPlant end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_MEAT_PROCESSING_PLANT_H
