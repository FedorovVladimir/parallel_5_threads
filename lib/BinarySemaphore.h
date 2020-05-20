//
// Created by vladimir on 20.05.2020.
//

#ifndef PARALLEL_5_THREADS_BINARYSEMAPHORE_H
#define PARALLEL_5_THREADS_BINARYSEMAPHORE_H

#include <windows.h>

class BinarySemaphore {
private:
    HANDLE sem;
public:
    BinarySemaphore(const char *name, int startState);

    ~BinarySemaphore();

    void Up();

    void Down();
};


#endif //PARALLEL_5_THREADS_BINARYSEMAPHORE_H
