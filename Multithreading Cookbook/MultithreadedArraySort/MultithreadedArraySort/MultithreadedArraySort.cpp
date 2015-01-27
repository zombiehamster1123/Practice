// MultithreadedArraySort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <tchar.h>

using namespace std;

#define THREADS_NUMBER 2
#define ELEMENTS_NUMBER 200
#define BLOCK_SIZE ELEMENTS_NUMBER / THREADS_NUMBER
#define MAX_VALUE 1000

typedef struct _tagARRAYOBJECT
{
	int * iArray;
	int iSize;
	int iThreadID;
} ARRAYOBJECT, *PARRAYOBJECT;

DWORD WINAPI ThreadStart(LPVOID lpParamater);
void PrintArray(int* iArrray, int iSize);
void MergeArrays(int* leftArray, int leftArrayLength,
	int* rightArray, int rightArrayLength, int* mergedArray);

int _tmain(int argc, _TCHAR* argv[])
{
	int iArray1[BLOCK_SIZE];
	int iArray2[BLOCK_SIZE];
	int iArray[ELEMENTS_NUMBER];
	for (int iIndex = 0; iIndex < BLOCK_SIZE; iIndex++)
	{
		iArray1[iIndex] = rand() % MAX_VALUE;
		iArray2[iIndex] = rand() % MAX_VALUE;
	}

	HANDLE hThreads[THREADS_NUMBER];
	ARRAYOBJECT pObject1 = { &(iArray1[0]), BLOCK_SIZE, 0 };
	hThreads[0] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)
		ThreadStart, (LPVOID)&pObject1, 0, NULL);

	ARRAYOBJECT pObject2 = { &(iArray2[0]), BLOCK_SIZE, 1 };
	hThreads[1] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)
		ThreadStart, (LPVOID)&pObject2, 0, NULL);

	cout << "Waiting execution..." << endl;
	WaitForMultipleObjects(THREADS_NUMBER, hThreads, TRUE, 
		INFINITE);

	MergeArrays(&iArray1[0], BLOCK_SIZE, &iArray2[0], BLOCK_SIZE,
		&iArray[0]);
	PrintArray(iArray, ELEMENTS_NUMBER);

	CloseHandle(hThreads[0]);
	CloseHandle(hThreads[1]);

	cout << "Array sorted..." << endl;
	cin.get();
	return 0;
}

DWORD WINAPI ThreadStart(LPVOID lpParameter)
{
	PARRAYOBJECT pObject = (PARRAYOBJECT)lpParameter;
	int iTmp = 0;
	for (int iIndex = 0; iIndex < pObject->iSize; iIndex++)
	{
		for (int iEndIndex = pObject->iSize - 1; iEndIndex > iIndex;
			iEndIndex--)
		{
			if (pObject->iArray[iEndIndex] < pObject->iArray[iIndex])
			{
				iTmp = pObject->iArray[iEndIndex];
				pObject->iArray[iEndIndex] = pObject->iArray[iIndex];
				pObject->iArray[iIndex] = iTmp;
			}
		}
	}
	return 0;
}

void PrintArray(int* iArray, int iSize)
{
	for (int iIndex = 0; iIndex < iSize; iIndex++)
		cout << " " << iArray[iIndex];
	cout << endl;
}

void MergeArrays(int* leftArray, int leftArrayLength,
	int* rightArray, int rightArrayLength, int* mergedArray)
{
	int i = 0, j = 0, k = 0;

	while (i < leftArrayLength && j < rightArrayLength)
	{
		if (leftArray[i] < rightArray[j])
		{
			mergedArray[k] = leftArray[i];
			++i;
		}
		else
		{
			mergedArray[k] = rightArray[j];
			++j;
		}
		++k;
	}
	if (i >= leftArrayLength)
	{
		while (j < rightArrayLength)
		{
			mergedArray[k] = rightArray[j];
			++j;
			++k;
		}
	}
	if (j >= rightArrayLength)
	{
		while (i < leftArrayLength)
		{
			mergedArray[k] = leftArray[i];
			++i;
			++k;
		}
	}
}