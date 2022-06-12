#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include"../headers/data.h"

int currentlyNotClicking = 1;
double clickerThreadCount = 1;
double cps = 10;

int main(int argc, char **argv) {
    // Get the total thread count and put it into the clicker thread count variable
    int logicalProcesserCount = getMaxThreadCount();
    clickerThreadCount = (double)logicalProcesserCount;

    // Define a local variable for the CPS count
    int localCPS;

    // Clear the screen, give an init message, and ask how much CPS the user wants
    system("cls");
    printf("XtremeAutoClicker v1\nInstructions:\n\tStop: \"h\"\n\tStart: \"s\"\n\tQuit: \"q\"\n");
ask_cps_count:
    printf("How much CPS do you want? ");
    scanf("%d", &localCPS);

double_check:
    // Double check if this info is correct
    printf("Ok, using %d cps, correct? <Y: yes, N: no> ", localCPS);
    char goBack = getch();
    printf("%c\n", goBack);
    if (goBack == 'Y' || goBack == 'y') goto start;
    if (goBack == 'N' || goBack == 'n') goto ask_cps_count;
    goto double_check;
start:
    printf("starting...\n");
    for (int i = 0; i < clickerThreadCount; i++) {
        createClickerThread();
        Sleep((1000 / (cps / clickerThreadCount)) / clickerThreadCount);
    }
    localCPS += localCPS / 5;
    cps = (double)localCPS;

    char ch;
    while (ch != 'q' && ch != 'Q') {
        ch = getch();
        if (ch == 'h' || ch == 'H') {
            printf("Stopping...\n");
            currentlyNotClicking = 1;
            continue;
        }
        if (ch == 's' || ch == 'S') {
            printf("Starting...\n");
            currentlyNotClicking = 0;
            continue;
        }
    };
}