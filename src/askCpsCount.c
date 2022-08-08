#include<stdio.h>
#include<conio.h>

extern double cps;

// Ask the user how much CPS they want
int askCpsCount(float maxRecommendedCPS) {
	int localCPS;
	
ask_cps_count:
	// Ask how much CPS the user wants
	printf("How much CPS do you want? (Based on your computers hardware, a maximum of %d is recommended) ", (int)maxRecommendedCPS);
	scanf(" %d", &localCPS);
	fflush(stdin);

double_check:
	// Double check if this info is correct
	printf("Ok, using %d cps, correct? <Y: yes, N: no> ", localCPS);

	// Get keyboard input, show it to the user
	char goBack = tolower(getchar());
	fflush(stdin);

	// If it's Y (or y) go to the start
	if (goBack == 'y') {
		cps = (double)localCPS;
		goto check_if_less_then_max;
	};
	// If it's N (or n) go back to asking for the CPS count
	if (goBack == 'n') goto ask_cps_count;
	// Otherwise, go back to the beginning of this statement
	goto double_check;

check_if_less_then_max:
	if (localCPS > maxRecommendedCPS) {
		printf("[WARNING] Given CPS count is greater then the maximum recommended CPS, are you sure you'd like to continue? <Y/n> ");
		char ch = getchar();
		while (ch != 'y' && ch != 'n') {
			fflush(stdin);
			printf("\nSorry, could you say that again? <Y/n> ");
			ch = getchar();
		}
		printf("\n");

		switch (tolower(ch)) {
			case 'y':
				printf("Alright, be warned if you experience any preformance issues\n");
			break;
			case 'n':
				goto ask_cps_count;
			break;
		}
	}
}