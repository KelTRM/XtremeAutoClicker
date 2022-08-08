extern int clickerThreadCount;
extern double cps;

extern void* createClickerThread();

// Handle preparing the autoclicker
int prepareAutoClicker() {
	// Create the threads in use for clicking
	for (int i = 0; i < clickerThreadCount; i++) {
		createClickerThread();
	}
	// Take the CPS given by the user, increase it by 1/5, and set it to the total CPS
	cps += cps / 5;
}