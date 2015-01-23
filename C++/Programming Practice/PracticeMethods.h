#ifndef PRACTICEMETHODS_H
#define PRACTICEMETHODS_H

#include <string>
#include <iostream>
#include <chrono>
#include <thread>

void MemoryReverseString(std::string& stringToReverse);
std::string RecurssionReverseString(std::string stringToReverse);
void BubbleSort(int[], int);
void HeapSort(int[], int);
void MyMergeIntoArray(int*, int*, int, int);
void BookMergeIntoArray(int*, int*, int, int);
std::string SortAnagram(std::string);

template<typename TimeT = std::chrono::milliseconds>
struct measure
{
	template<typename F, typename ...Args>
	static typename TimeT::rep execution(F func, Args&&... args)
	{
		auto start = std::chrono::steady_clock::now();

		// Now call the function with all the parameters you need.
		func(std::forward<Args>(args)...);

		auto duration = std::chrono::duration_cast< TimeT>(std::chrono::steady_clock::now() - start);

		return duration.count();
	}
};

#endif