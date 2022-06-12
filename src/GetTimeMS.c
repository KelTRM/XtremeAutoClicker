#include<time.h>

time_t getTimeMS() {
    struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_nsec;
}