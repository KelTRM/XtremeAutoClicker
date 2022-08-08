#include<stdio.h>
#include<sysinfoapi.h>

DWORD WINAPI getLogicalProcesserCount() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    return sysInfo.dwNumberOfProcessors;
}

DWORD WINAPI getBaseClock() {
    LARGE_INTEGER freqency;
    QueryPerformanceFrequency(&freqency);
    return freqency.LowPart;
}