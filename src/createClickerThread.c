#include<Windows.h>

extern int currentlyNotClicking;
extern double clickerThreadCount;
extern double cps;

extern int click();
DWORD WINAPI clickerThread();

HANDLE createClickerThread() {
    unsigned int counter = 0;
    DWORD threadID;
    HANDLE thread = CreateThread(0, 0, clickerThread, &counter, 0, &threadID);
    return thread;
}

DWORD WINAPI clickerThread() {
    for (;;) {
        if (currentlyNotClicking) {
            continue;
        }

        double randomAdd = rand() % 10;
        double preDiv = cps / clickerThreadCount;
        double sleepTime = (1000 / preDiv) + randomAdd;
        Sleep(1000 / (cps / clickerThreadCount));
        click();
    }
}