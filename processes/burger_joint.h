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

int burgerJointMeat = 0; // запас котлет
int maxBurgerJointMeat = 0; // максимальная вместимость запаса котлет

int burgerJointBuns = 0; // запас булочек
int maxBurgerJointBuns = 0; // максимальная вместимость запаса булочек

int burger = 0; // сейчас
int maxBurger = 5; // цель игры

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

        if (burger == maxBurger) {
             endGame(endSemaphore);
        }
    }
    cout << "BurgerJoint end!\n";
    ExitThread(0);
}

void endGame(IntegerSemaphore &endSemaphore) {
    endSemaphore.Up(6);
}

#endif //PARALLEL_5_THREADS_BURGER_JOINT_H
