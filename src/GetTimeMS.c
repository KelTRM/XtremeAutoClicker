#include<time.h>

time_t getTimeMS() {
    // struct timespec ts;
	// clock_gettime(CLOCK_MONOTONIC, &ts);
    // return ts.tv_sec;
    struct timeval tv;
    mingw_gettimeofday(&tv, NULL);
    return (tv.tv_sec + tv.tv_usec) / 1000;
}