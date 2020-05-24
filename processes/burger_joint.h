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

void endGame(IntegerSemaphore &endSemaphore);

using namespace std;

DWORD WINAPI BurgerJointThreadProc(PVOID arg) {
    cout << "BurgerJoint start!\n";
    IntegerSemaphore endSemaphore("end_game");

    while (true) {

        // конец игры
        if (endSemaphore.Down(100)) {
            break;
        }
        endGame(endSemaphore);
    }
    cout << "BurgerJoint end!\n";
    ExitThread(0);
}

void endGame(IntegerSemaphore &endSemaphore) {
    endSemaphore.Up(6);
}

#endif //PARALLEL_5_THREADS_BURGER_JOINT_H
