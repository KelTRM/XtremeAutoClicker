#include<stdio.h>
#include<Windows.h>

int disableQuickEdit() {
	HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prevMode;
	GetConsoleMode(hInput, &prevMode);
	SetConsoleMode(hInput, prevMode & ENABLE_EXTENDED_FLAGS);
	// HANDLE hInput;
    // DWORD prev_mode;
    // hInput = GetStdHandle(STD_INPUT_HANDLE);
    // GetConsoleMode(hInput, &prev_mode); 
    // SetConsoleMode(hInput, prev_mode & ENABLE_EXTENDED_FLAGS);
	return 0;
}