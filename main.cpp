#include <iostream>
#include <windows.h>

using namespace std;


DWORD WINAPI MarketThreadProc(PVOID arg) {
    cout << "Market start!";
    ExitThread(0);
}

int main() {
    cout << "Start program!\n";

    HANDLE marketThread = CreateThread(nullptr, 0, MarketThreadProc, (PVOID) 1, 0, nullptr);

    cout << "End program!\n";
    WaitForSingleObject(marketThread, INFINITE);
    return 0;
}
