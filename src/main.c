// XtremeAutoClicker
// Made by KelTRM (AKA KelTCM)

#include<stdio.h>
#include"../headers/data.h"

// Declare currently not clicking (1 if not clicking, 0 if clicking)
int currentlyNotClicking = 1;
// Declare the total thread count
int clickerThreadCount;
double cps;

int main(int argc, char **argv) {
	SetConsoleTitle("Xtreme Auto Clicker "VERSION);
	HWND consoleHandle = GetConsoleHandle();

	disableQuickEdit();

	// Get the total thread count and put it into the clicker thread count variable
	int logicalProcesserCount;
	int maxRecommendedCPS = getRecomendedSpeed(&logicalProcesserCount);

	// Define a local variable for the CPS count
	int localCPS;

	// Clear the screen, give an init message, and ask how much CPS the user wants
	system("cls");
	printf("XtremeAutoClicker "VERSION"\nInstructions:\n"
		    "\tStop: \"Ctrl + h\"\n"
			"\tStart: \"Ctrl + s\"\n"
			"\tChange CPS: \"Ctrl + c\"\n"
			"\tQuit: \"Ctrl + q\"\n");

	askCpsCount(maxRecommendedCPS);

	// Give a message stating preperation of the autoclicker
	printf("Preparing autoclicker...\n");

	// Prepare the autoclicker
	prepareAutoClicker();

	// Tell the user the autoclicker is ready
	printf("Autoclicker ready, use commands above to control the autoclicker\n");
	char ch;

	handleHotkeys(maxRecommendedCPS, consoleHandle);
}