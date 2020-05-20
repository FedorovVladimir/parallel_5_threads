#include <iostream>
#include <windows.h>

using namespace std;


DWORD WINAPI ThreadProc(PVOID arg) {
    cout << "hello 2\n";
    ExitThread(0);
}

int main() {
    cout << "Start program!\n";

    HANDLE thread1 = CreateThread(nullptr, 0, ThreadProc, (PVOID) 1, 0, nullptr);

    cout << "End program!\n";
    WaitForSingleObject(thread1, INFINITE);
    return 0;
}
