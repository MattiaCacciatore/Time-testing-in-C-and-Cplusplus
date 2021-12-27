#include <iostream>
#include <chrono>

using namespace std::chrono;

void dotest(){
	high_resolution_clock::time_point t1, t2;
	double duration;

	t1 = high_resolution_clock::now();
	//
	// Insert functions/programs here.
	//
	t2 = high_resolution_clock::now();
	duration = duration_cast<seconds>( t2 - t1 ).count(); // seconds, milliseconds, microseconds, nanoseconds.

	std::cout << "\nThe operation required " << duration << " seconds\n";
}

//--------------------------------TEST---------------------------------
int main(){
    dotest();
	return 0;
}
