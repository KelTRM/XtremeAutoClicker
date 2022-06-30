#include<Windows.h>
#include<stdbool.h>

extern int currentlyNotClicking;
extern double cps;

extern int askCpsCount();

// Handles hotkeys
int handleHotkeys() {
	// Register hotkeys for H, S, then Q
	RegisterHotKey( NULL, 1, MOD_CONTROL, 0x43 );
	RegisterHotKey( NULL, 2, MOD_CONTROL, 0x48 );
	RegisterHotKey( NULL, 3, MOD_CONTROL, 0x51 );
	RegisterHotKey( NULL, 4, MOD_CONTROL, 0x53 );

	MSG key;
	while(GetMessage(&key, NULL, 0, 0) != 0) {
		TranslateMessage(&key);
		DispatchMessage(&key);

		if (key.message == WM_HOTKEY) {
			bool keyIsC = !!(GetAsyncKeyState(0x43) & 0x01);
			bool keyIsH = !!(GetAsyncKeyState(0x48) & 0x01);
			bool keyIsQ = !!(GetAsyncKeyState(0x51) & 0x01);
			bool keyIsS = !!(GetAsyncKeyState(0x53) & 0x01);

			if (keyIsH && keyIsS) {
				continue;
			}

			if (keyIsC && currentlyNotClicking == 1) {
				askCpsCount();
			}else if (keyIsH) {
				printf("Stopping...\n");
				currentlyNotClicking = 1;
			} else if (keyIsS) {
				printf("Starting...\n");
				currentlyNotClicking = 0;
			} else if (keyIsQ) {
				int Quit = MessageBoxA(NULL, "Are you sure you want to quit?", "Are you sure", MB_ICONQUESTION | MB_YESNO | MB_DEFBUTTON2);
				switch (Quit) {
					case IDYES:
						goto quit;
					break;
					case IDNO:
						printf("Ok, not quitting\n");
					break;
				}
			}
			if (0) {
quit:
				break;
			}
		}
	}
}