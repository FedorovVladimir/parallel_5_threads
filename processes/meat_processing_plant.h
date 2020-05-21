//
// Created by vladimir on 20.05.2020.
//

#ifndef PARALLEL_5_THREADS_MEAT_PROCESSING_PLANT_H
#define PARALLEL_5_THREADS_MEAT_PROCESSING_PLANT_H

#include <iostream>
#include <windows.h>
#include "../lib/BinarySemaphore.h"
#include "../lib/IntegerChannel.h"

using namespace std;

DWORD WINAPI MeatProcessingPlantThreadProc(PVOID arg) {
    cout << "MeatProcessingPlant start!\n";
    while (true) {

    }
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_MEAT_PROCESSING_PLANT_H
