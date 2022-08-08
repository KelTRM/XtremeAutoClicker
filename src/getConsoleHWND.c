#include<Windows.h>

HWND GetConsoleHandle() {
	#define BUF_SIZE 1024
	char OldName[BUF_SIZE];
	char NewName[BUF_SIZE];

	HWND consoleHwnd;

	wsprintf(NewName, "%d/%d", GetTickCount(), GetCurrentProcessId());

	GetConsoleTitle(OldName, BUF_SIZE);
	Sleep(40);
	SetConsoleTitle(NewName);
	consoleHwnd = FindWindow(NULL, OldName);
	SetConsoleTitle(OldName);
}