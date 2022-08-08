#include<Windows.h>

extern int currentlyNotClicking;
extern int clickerThreadCount;
extern double cps;

extern time_t getTimeMS();

// Prototypes for click() and clickerThread()
extern int click();
DWORD WINAPI clickerThread();

// Define the clicker thread creator
HANDLE createClickerThread() {
    unsigned int counter = 0;
    DWORD threadID;
    HANDLE thread = CreateThread(0, 0, clickerThread, &counter, 0, &threadID);
    return thread;
}

// Define the body of the clicker thread
DWORD WINAPI clickerThread() {
    DWORD threadID = GetCurrentThreadId();

    // Start an infinite loop
    for (;;) {
        time_t timeAtStart = getTimeMS();
        // If currentlyNotClicking, go to start of loop
        if (currentlyNotClicking) {
            continue;
        }

        // Otherwise, generate an amount of time to sleep for, first by generating a random amount of time between 0 and 10ms
        double randomAdd = rand() % 10;
        // Then get the amount of times per second the current thread has to click
        double preDiv = cps / clickerThreadCount;
        // Then divide that by 1000 to get the time in ms, and add the random time
        double sleepTime = (1000 / preDiv) + randomAdd;
        
        // Sleep for the generated amount of time
        // Sleep(1000 / (cps / clickerThreadCount));
        time_t currentTime = getTimeMS();
        while (currentTime < timeAtStart + (1000.0f / (cps / (double)clickerThreadCount))) {
            currentTime = getTimeMS();
        }
        // printf("click on thread %lu\n", threadID);
        // Send a mouse click
        click();
    }
}