//
// Created by vladimir on 20.05.2020.
//

#ifndef PARALLEL_5_THREADS_BURGER_JOINT_H
#define PARALLEL_5_THREADS_BURGER_JOINT_H

#include <iostream>
#include <windows.h>
#include "../lib/BinarySemaphore.h"
#include "../lib/IntegerChannel.h"

using namespace std;

DWORD WINAPI BurgerJointThreadProc(PVOID arg) {
    cout << "BurgerJoint start!\n";
    while (true) {

    }
    ExitThread(0);
}

#endif //PARALLEL_5_THREADS_BURGER_JOINT_H
