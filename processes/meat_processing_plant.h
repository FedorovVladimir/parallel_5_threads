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

int meatProcessingPlantMeat = 0; // запас мяса
int maxMeatProcessingPlantMeat = 5; // максимальная вместимость запаса мяса

int cutlet = 0; // запас котлет
int maxCutlet = 10; //  максимальная вместимость запаса котлет

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


        // делаем котлеты
        if (meatProcessingPlantMeat >= 2) {
            int b = meatProcessingPlantMeat / 2;
            if (b) {
                if (cutlet < maxCutlet) {
                    meatProcessingPlantMeat -= b * 2;
                    cutlet += b;
                    printf("Bakery: create %d cutlet\n", b);
                    if (cutlet > maxCutlet) {
                        cutlet = maxCutlet;
                    }
                }
            }
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
