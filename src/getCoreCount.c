#include<stdio.h>
#include<sysinfoapi.h>

DWORD WINAPI getMaxThreadCount() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    return sysInfo.dwNumberOfProcessors;
}