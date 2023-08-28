#include <stdio.h>	/* for printf */
#include <stdint.h>	/* for uint64 definition */
#include <stdlib.h>	/* for exit() definition */
#include <time.h>	/* for clock_gettime */
#include <math.h>
int main()
{
	uint64_t diff_n;
	struct timespec start, end;
	int i;

	/* measure monotonic time */
	clock_gettime(CLOCK_MONOTONIC, &start);	/* mark start time */
	sleep(2);	/* do stuff */
	clock_gettime(CLOCK_MONOTONIC, &end);	/* mark the end time */

	// diff =(end.tv_sec - start.tv_sec) + end.tv_nsec - start.tv_nsec;
	// printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff);

	diff_n = ((end.tv_sec)*pow(10,9) + end.tv_nsec) - ((start.tv_sec)*pow(10,9)-start.tv_nsec);
	// printf("elapsed time = %llu nanoseconds\n", (long long unsigned int) diff_n);
	printf("elapsed time = %f seconds\n", (diff_n)*pow(10,-9));

}