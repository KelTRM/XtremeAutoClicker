extern int clickerThreadCount;

// Gets the recommended CPS count
int getRecomendedSpeed(int *logicalProcesserCount) {
	// Get the total thread count and put it into the clicker thread count variable
	*logicalProcesserCount = getLogicalProcesserCount();
	clickerThreadCount = (double)*logicalProcesserCount;

	// Get the preformance of the CPU to determine a recomended maximum CPS for the system (From some math and experience, I decided this should be 9.375 * locicalProcesserCount * baseClock
	// But will not go into detail why here)
	float baseClock = getBaseClock() / 3000000.0f;
	float maxRecommendedCps = 9.375f * *logicalProcesserCount * baseClock;

	return (int)maxRecommendedCps;
}