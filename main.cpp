#include <iostream>
#include <windows.h>
#include "processes/market.h"
#include "processes/farm.h"
#include "processes/warehouse.h"
#include "processes/bakery.h"
#include "processes/meat_processing_plant.h"
#include "processes/burger_joint.h"

using namespace std;

int main() {
    cout << "Start program!\n";

    HANDLE marketThread = CreateThread(nullptr, 0, MarketThreadProc, (PVOID) 1, 0, nullptr);
    HANDLE farmThread = CreateThread(nullptr, 0, FarmThreadProc, (PVOID) 1, 0, nullptr);
    HANDLE warehouseThread = CreateThread(nullptr, 0, WarehouseThreadProc, (PVOID) 1, 0, nullptr);
    HANDLE bakeryThread = CreateThread(nullptr, 0, BakeryThreadProc, (PVOID) 1, 0, nullptr);
    HANDLE meatProcessingPlantThread = CreateThread(nullptr, 0, MeatProcessingPlantThreadProc, (PVOID) 1, 0, nullptr);
    HANDLE burgerJointThread = CreateThread(nullptr, 0, BurgerJointThreadProc, (PVOID) 1, 0, nullptr);

    WaitForSingleObject(marketThread, INFINITE);
    WaitForSingleObject(farmThread, INFINITE);
    WaitForSingleObject(warehouseThread, INFINITE);
    WaitForSingleObject(bakeryThread, INFINITE);
    WaitForSingleObject(meatProcessingPlantThread, INFINITE);
    WaitForSingleObject(burgerJointThread, INFINITE);

    cout << "End program!\n";
    return 0;
}
