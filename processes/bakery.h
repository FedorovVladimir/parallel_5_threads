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

int bakeryFlour = 0; // произведенная мука в запасе
int maxBakeryFlour = 5; // максимальная вместимость запаса муки

int buns = 0; // произведенные будочки
int maxBuns = 10; // максимальная вместимость запаса булочек

DWORD WINAPI BakeryThreadProc(PVOID arg) {
    int ping = 1000; // время одного цикла работ
    cout << "Bakery start!\n";
    IntegerSemaphore endSemaphore("end_game");

    IntegerChannel howManyFlourToBakery("hManyFlourF2B");
    IntegerChannel sendFlourToBakery("sendFlourF2B");

    IntegerChannel howManyBunsToBurger("hManyBunsB2B");
    IntegerChannel sendBunsToBurger("sendBunsB2B");

    while (true) {
        Sleep(ping);

        // просим муку у фермы
        if (bakeryFlour < maxBakeryFlour) {
            int k = (maxBakeryFlour - bakeryFlour);
            howManyFlourToBakery.setData(k);
            printf("Bakery: need %d flour from Farm\n", k);
        }

        // забираем муку у фермы
        int k = sendFlourToBakery.getData();
        if (k) {
            bakeryFlour += k;
            if (bakeryFlour > maxBakeryFlour) {
                bakeryFlour = maxBakeryFlour;
            }
            printf("Bakery: get %d flour from Farm\n", k);
        }

        // делаем булочки
        if (bakeryFlour >= 2) {
            int b = bakeryFlour / 2;
            if (b) {
                if (buns < maxBuns) {
                    bakeryFlour -= b * 2;
                    buns += b;
                    printf("Bakery: create %d buns\n", b);
                    if (buns > maxBuns) {
                        buns = maxBuns;
                    }
                }
            }
        }


        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
    }
    cout << "Bakery end!\n";
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_BAKERY_H
