#include "Threads.h"

using namespace std;

static const int num_threads = 10;

void testFunctionOne()
{
	int num = 1000000;
	while (num)
		--num;
}

void testFuctionTwo(int num)
{
	num += 100000;
	while (num)
		--num;
}

void threadExampleOne()
{
	thread first(testFunctionOne);
	thread second(testFuctionTwo, 0);

	cout << "main, foo and bar now execute concurrently...\n";

	// synchronize threads:
	first.join();                // pauses until first finishes
	second.join();               // pauses until second finishes

	std::cout << "foo and bar completed.\n";
}

void call_from_thread() {
	cout << "Hello, World" << endl;
}

void threadExampleTwo()
{
	thread t[num_threads];

	// Launch a group of threads
	for (int i = 0; i < num_threads; ++i)
		t[i] = thread(call_from_thread);

	cout << "Launched from the main\n";

	// Join the threads with the main thread
	for (int i = 0; i < num_threads; ++i)
		t[i].detach();	// t[i] will run freely on its own - daemon process
		//t[i].join();	// threadExampleTwo thread waits for t[i] to finish
}