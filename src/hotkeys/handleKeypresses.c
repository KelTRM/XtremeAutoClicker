#include<Windows.h>
#include<stdbool.h>

extern int currentlyNotClicking;
extern double cps;

extern int askCpsCount(float maxRecommendedCPS);

// Handles hotkeys
int handleHotkeys(float maxRecommendedCPS, HWND consoleHandle) {
	// Register hotkeys for H, S, C, then Q
	RegisterHotKey( consoleHandle, 1, MOD_CONTROL, 'C' );
	RegisterHotKey( consoleHandle, 2, MOD_CONTROL, 'H' );
	RegisterHotKey( consoleHandle, 3, MOD_CONTROL, 'Q' );
	RegisterHotKey( consoleHandle, 4, MOD_CONTROL, 'S' );

	MSG key;
	while(GetMessage(&key, consoleHandle, 0, 0) != 0) {
		TranslateMessage(&key);
		DispatchMessage(&key);

		if (key.message == WM_HOTKEY) {
			bool keyIsC = !!(GetAsyncKeyState('C') & 0x01);
			bool keyIsH = !!(GetAsyncKeyState('H') & 0x01);
			bool keyIsQ = !!(GetAsyncKeyState('Q') & 0x01);
			bool keyIsS = !!(GetAsyncKeyState('S') & 0x01);

			if (keyIsC && currentlyNotClicking == 1) {
				askCpsCount(maxRecommendedCPS);
			} else if (keyIsH) {
				printf("Stopping...\n");
				currentlyNotClicking = true;
			} else if (keyIsS) {
				printf("Starting...\n");
				currentlyNotClicking = false;
			} else if (keyIsQ) {
				bool temp = currentlyNotClicking;
				currentlyNotClicking = true;
				int Quit = MessageBoxA(NULL, "Are you sure you want to quit?", "Are you sure", MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2);
				switch (Quit) {
					case IDYES:
						exit(0);
					break;
					case IDNO:
						printf("Ok, not quitting\n");
						currentlyNotClicking = temp;
					break;
				}
			}
		}
	}
}