//
// Created by vladimir on 20.05.2020.
// Мясокомбинат
//

#ifndef PARALLEL_5_THREADS_MEAT_PROCESSING_PLANT_H
#define PARALLEL_5_THREADS_MEAT_PROCESSING_PLANT_H

#include <iostream>
#include <windows.h>
#include "../lib/IntegerChannel.h"
#include "../lib/IntegerSemaphore.h"

using namespace std;

int meatProcessingPlantMeat = 0;
int maxMeatProcessingPlantMeat = 5;

DWORD WINAPI MeatProcessingPlantThreadProc(PVOID arg) {
    int ping = 1000; // время одного цикла работ
    cout << "MeatProcessingPlant start!\n";
    IntegerSemaphore endSemaphore("end_game");

    IntegerChannel howManyMeatToBakery("hManyMeatF2B");
    IntegerChannel sendMeatToBakery("sendMeatF2B");

    while (true) {
        Sleep(ping);

        // просим мясо у фермы
        if (meatProcessingPlantMeat < maxMeatProcessingPlantMeat) {
            int k = (maxMeatProcessingPlantMeat - meatProcessingPlantMeat);
            howManyMeatToBakery.setData(k);
            printf("MeatProcessingPlant: need %d meat from Farm\n", k);
        }

        // забираем мясо у фермы
        int k = sendMeatToBakery.getData();
        if (k) {
            meatProcessingPlantMeat += k;
            if (meatProcessingPlantMeat > maxMeatProcessingPlantMeat) {
                meatProcessingPlantMeat = maxMeatProcessingPlantMeat;
            }
            printf("MeatProcessingPlant: get %d meat from Farm\n", k);
        }


        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "MeatProcessingPlant end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_MEAT_PROCESSING_PLANT_H
