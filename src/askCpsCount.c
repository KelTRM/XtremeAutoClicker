#include<stdio.h>
#include<conio.h>

extern double cps;

// Ask the user how much CPS they want
int askCpsCount() {
	int localCPS;
	
	ask_cps_count:
	// Ask how much CPS the user wants
	printf("How much CPS do you want? ");
	scanf("%d", &localCPS);

double_check:
	// Double check if this info is correct
	printf("Ok, using %d cps, correct? <Y: yes, N: no> ", localCPS);

	// Get keyboard input, show it to the user
	char goBack = getch();
	printf("%c\n", goBack);

	// If it's Y (or y) go to the start
	if (goBack == 'Y' || goBack == 'y') {
		cps = (double)localCPS;
		return 0;
	};
	// If it's N (or n) go back to asking for the CPS count
	if (goBack == 'N' || goBack == 'n') goto ask_cps_count;
	// Otherwise, go back to the beginning of this statement
	goto double_check;
}