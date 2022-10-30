// C++
// g++ -std=c++17
//(C++11 or newer)

#include <iostream>
#include <chrono>

using namespace std::chrono;

#include <stdlib.h> // C/C++ mandatory library.

// C
// gcc -std=c17 -D_POSIX_SOURCE -D_GNU_SOURCE -D_POSIX_C_SOURCE=199309L

#include <stdio.h>
#include <time.h>
#include <errno.h>
// second - nanoseconds conversion.
#define SEC_NSEC_CONV 1000000000
// For those systems which don't support recent versions of glibc
// CLOCK_MONOTONIC is an alternative (not guaranteed).
#define CLOCK_TYPE CLOCK_MONOTONIC_RAW

int dotest_cpp(const char* const p){
	high_resolution_clock::time_point start, end;
	double sec = 0, ms_sec = 0;

	start = high_resolution_clock::now();
	// Exec the program.
	if(system(p) == -1){
		perror("Error system(p)\n");
		return -1;
	}

	end = high_resolution_clock::now();
	// Seconds, milliseconds, microseconds, nanoseconds.
	sec    = duration_cast<seconds>(end - start).count();
	ms_sec = duration_cast<milliseconds>(end - start).count();

	std::cout << "[C++ time] The operation required: " << sec << "." << ms_sec << " seconds\n";
	return 0;
}

int dotest_c(const char* const p){
	struct timespec start, end, delta;
	double sec = 0;

	if(clock_gettime(CLOCK_TYPE, &start) == -1){
		perror("Error clock_gettime(CLOCK_TYPE, &start)\n");
		return -1;
	}
	// Exec the program.
	if(system(p) == -1){
		perror("Error system(p)\n");
		return -1;
	}

	if(clock_gettime(CLOCK_TYPE, &end) == -1){
		perror("Error clock_gettime(CLOCK_TYPE, &end)\n");
		return -1;
	}

	delta.tv_sec  = end.tv_sec  - start.tv_sec;
	delta.tv_nsec = end.tv_nsec - start.tv_nsec;

	sec = ((double)(delta.tv_sec * SEC_NSEC_CONV) + (double)(delta.tv_nsec)) / (SEC_NSEC_CONV * 1.0);

	printf("[C   time] The operation required: %f seconds\n", sec);

	return 0;
}
//--------------------------------TEST---------------------------------
int main(int argc, char** argv){
	int code = 0;
	if(argc != 2){
		printf("--- You should pass a single program ---\n");
		printf("--- e.g. ./TimeTesting ./a.out       ---\n");
	}
	else{
		code = dotest_cpp(argv[1]);
		if(code != -1)
			code = dotest_c(argv[1]);
	}
	return code;
}
