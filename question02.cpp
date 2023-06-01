//Question 2 - threads & synchronization

//Task: Improve execution time by using multi-threading instead of calling operation1 and operation2 serially, make sure that sum=EXPECTED_SUM after using threads
// please explain the changes you made and what new aspects you had to deal with when shifting from serial execution to parallel execution

// Make sure you compile the code in "Release" configuration (e.g O2 optimization level).
// Do not modify the constexpr variables

/*I have created 2 threads so that each one of them runs one of the 2 given functions.
 * Because the gSum variable is shared between the 2 threads I also had to create a mutex lock so that this variable won't be overridden when
 * executing the 2 threads.
 * Using Serial execution it takes about 15s for the script to run, and with multithreading it takes 10s. We can notice that 33% improvement is significant!
 */


#include <chrono>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

constexpr size_t ITERATIONS = 1000*1000ULL;
constexpr size_t OP1_PARAM = 2ULL;
constexpr size_t OP2_PARAM = 1ULL;
constexpr size_t EXPECTED_SUM = 1000001000000ULL;

size_t gSum = 0;
std::mutex mutex;

void operation1(size_t arg) {
	std::cout << "Performing operation1" << std::endl;
	for (size_t i = 0; i < ITERATIONS; i++) {
        mutex.lock();
		gSum += (arg + i);
        mutex.unlock();
	}
	std::this_thread::sleep_for(std::chrono::seconds(5)); //Simulate some heavy work
	std::cout << "Operation1 Performed" << std::endl;
}


void operation2(size_t arg) {
	std::cout << "Performing operation2" << std::endl;
	for (size_t i = 0; i < ITERATIONS; i++) {
        mutex.lock();
		gSum += (arg*i);
        mutex.unlock();
	}
	std::this_thread::sleep_for(std::chrono::seconds(10));  //Simulate some heavy work
	std::cout << "Operation2 Performed" << std::endl;
}


int main(int argc, char** argv)
{
	auto start = std::chrono::steady_clock::now();

    std::thread thread1(&operation1, OP1_PARAM);
    std::thread thread2(&operation2, OP2_PARAM);

    thread1.join();
    thread2.join();
	auto end = std::chrono::steady_clock::now();

	std::cout << "Total execution duration in milliseconds: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;
	std::cout << "Result:  " << gSum <<  ", " <<(gSum == EXPECTED_SUM ? "success" : "failure!")<< std::endl;
	std::cout << "Press enter to exit" << std::endl;
	getchar();
	return 0;
}