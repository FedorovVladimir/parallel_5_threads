//
// Created by vladimir on 20.05.2020.
// Бургерная
//

#ifndef PARALLEL_5_THREADS_BURGER_JOINT_H
#define PARALLEL_5_THREADS_BURGER_JOINT_H

#include <iostream>
#include <windows.h>
#include "../lib/IntegerChannel.h"
#include "../lib/IntegerSemaphore.h"

using namespace std;

void endGame(IntegerSemaphore &endSemaphore);

DWORD WINAPI BurgerJointThreadProc(PVOID arg) {
    int ping = 1000; // время одного цикла работ
    cout << "BurgerJoint start!\n";
    IntegerSemaphore endSemaphore("end_game");

    while (true) {
        Sleep(ping);

        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
        // todo разкомментировать конец игры
        // endGame(endSemaphore);
    }
    cout << "BurgerJoint end!\n";
    ExitThread(0);
}

void endGame(IntegerSemaphore &endSemaphore) {
    endSemaphore.Up(6);
}

#endif //PARALLEL_5_THREADS_BURGER_JOINT_H
