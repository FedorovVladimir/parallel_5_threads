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

int main() {
    cout << "Start program!\n";

    HANDLE marketThread = CreateThread(nullptr, 0, MarketThreadProc, (PVOID) 1, 0, nullptr);
    HANDLE farmThread = CreateThread(nullptr, 0, FarmThreadProc, (PVOID) 1, 0, nullptr);

    cout << "End program!\n";
    WaitForSingleObject(marketThread, INFINITE);
    WaitForSingleObject(farmThread, INFINITE);
    return 0;
}
