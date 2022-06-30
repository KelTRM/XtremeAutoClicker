#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<stdbool.h>
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
	printf("XtremeAutoClicker v1\nInstructions:\n\tStop: \"Ctrl + h\"\n\tStart: \"Ctrl + s\"\n\tChange CPS: \"Ctrl + c\"\n\tQuit: \"Ctrl + q\"\n");

	askCpsCount();

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

	handleHotkeys();
}