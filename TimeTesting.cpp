/*
 *  TimeTesting.cpp
 *
 *  Author: Mattia Cacciatore <cacciatore1995@hotmail.it>
 *
 *  TimeTesing is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with ubash. If not, see <http://www.gnu.org/licenses/>.
 */
// C++
// g++ -std=c++17
#include <iostream>
#include <chrono>

using namespace std::chrono;

// C
// gcc -std=c17 -D_POSIX_SOURCE -D_GNU_SOURCE -D_POSIX_C_SOURCE=199309L
#define _POSIX_C_SOURCE 199309L

#include <stdio.h>
#include <time.h>
#include <errno.h>
// second - nanoseconds conversion.
#define SEC_NSEC_CONV 1000000000
// For those systems which don't support recent versions of glibc
// CLOCK_MONOTONIC is an alternative (not guaranteed).
#define CLOCK_TYPE CLOCK_MONOTONIC_RAW

void dotest_cpp(){
	high_resolution_clock::time_point start, end;
	double sec = 0, ms_sec = 0;

	start = high_resolution_clock::now();
	//
	// Insert functions/programs here.
	//
	end = high_resolution_clock::now();
	// Seconds, milliseconds, microseconds, nanoseconds.
	sec    = duration_cast<seconds>(end - start).count();
	ms_sec = duration_cast<milliseconds>(end - start).count();

	std::cout << "[C++ time] The operation required: " << sec << "." << ms_sec << " seconds\n";
}

int dotest_c(){
	struct timespec start, end, delta;
	double sec = 0;

	if(clock_gettime(CLOCK_TYPE, &start) == -1){
		perror("Error clock_gettime(CLOCK_TYPE, &start)\n");
		return -1;
	}
	//
	// Insert functions/programs here.
	//
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
int main(){
	dotest_cpp();
	int code = dotest_c();
	return code;
}
