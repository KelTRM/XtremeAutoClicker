#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include"../headers/data.h"

// Declare currently not clicking (1 if not clicking, 0 if clicking)
int currentlyNotClicking = 1;
// Declare the total thread count
int clickerThreadCount;
double cps;

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
    // Ask ho much CPS the user wants
    printf("How much CPS do you want? ");
    scanf("%d", &localCPS);

double_check:
    // Double check if this info is correct
    printf("Ok, using %d cps, correct? <Y: yes, N: no> ", localCPS);

    // Get keyboard input, show it to the user
    char goBack = getch();
    printf("%c\n", goBack);

    // If it's Y (or y) go to the start
    if (goBack == 'Y' || goBack == 'y') goto start;
    // If it's N (or n) go back to asking for the CPS count
    if (goBack == 'N' || goBack == 'n') goto ask_cps_count;
    // Otherwise, go back to the beginning of this statement
    goto double_check;

    // Start segment
start:
    // Give a message stating preperation of the autoclicker
    printf("Preparing autoclicker...\n");

    // Create the threads in use for clicking
    for (int i = 0; i < clickerThreadCount; i++) {
        createClickerThread();
    }
    // Take the CPS given by the user, increase it by 1/5, and set it to the total CPS
    cps += cps / 5;

    // Tell the user the autoclicker is ready
    printf("Autoclicker ready, use commands above to control the autoclicker\n");
    char ch;
    while (ch != 'q' && ch != 'Q') {
        // Get the current keystroke
        ch = getch();

        // If it's H or h (for halt) stop the autoclicker
        if (ch == 'h' || ch == 'H') {
            // Tell the user it's stopping and set the autoclicker to stop
            printf("Stopping...\n");
            currentlyNotClicking = 1;
            // Go back to the beginning of the loop
            continue;
        }
        // Else if it's S or s (for start) start the autoclicker
        if (ch == 's' || ch == 'S') {
            // Tell the user it's starting and set the autoclicker to stop
            printf("Starting...\n");
            currentlyNotClicking = 0;
            // Go back to the beginning of the loop
            continue;
        }
    };
}