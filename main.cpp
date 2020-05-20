#include <iostream>
#include <windows.h>

using namespace std;


DWORD WINAPI MarketThreadProc(PVOID arg) {
    cout << "Market start!\n";
    ExitThread(0);
}

DWORD WINAPI FarmThreadProc(PVOID arg) {
    cout << "Farm start!\n";
    ExitThread(0);
}

DWORD WINAPI WarehouseThreadProc(PVOID arg) {
    cout << "Warehouse start!\n";
    ExitThread(0);
}

DWORD WINAPI BakeryThreadProc(PVOID arg) {
    cout << "Bakery start!\n";
    ExitThread(0);
}

DWORD WINAPI MeatProcessingPlantThreadProc(PVOID arg) {
    cout << "MeatProcessingPlant start!\n";
    ExitThread(0);
}

DWORD WINAPI BurgerJointThreadProc(PVOID arg) {
    cout << "BurgerJoint start!\n";
    ExitThread(0);
}

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
