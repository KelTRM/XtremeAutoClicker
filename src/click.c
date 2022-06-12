#include<Windows.h>

int click() {
    INPUT input1;
    input1.type = INPUT_MOUSE;
    input1.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input1, sizeof(input1));

    INPUT input2;
    input2.type = INPUT_MOUSE;
    input2.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input2, sizeof(input2));
}