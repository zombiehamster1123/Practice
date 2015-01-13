#include "PracticeMethods.h"

using namespace std;

void MemoryReverseString(string& stringToReverse)
{
	char charFromString;
	int lengthOfStringToIndex = stringToReverse.length() - 1;

	// Go up to the middle point of the string
	// As we're swapping with the last
	// (1 & lengthOfStringToIndex) - if odd goes to middle number
	for (int i = 0; i < lengthOfStringToIndex / 2 + (1 & lengthOfStringToIndex); ++i)
	{
		// Store char i away from the back, replace char with i positioned char
		// And then replace i positioned char with the stored char
		charFromString = stringToReverse[lengthOfStringToIndex - i];
		stringToReverse[lengthOfStringToIndex - i] = stringToReverse[i];
		stringToReverse[i] = charFromString;
	}
};

string RecurssionReverseString(string stringToReverse)
{
	if (stringToReverse != "")
	{
		char s = stringToReverse[0];
		stringToReverse.erase(0, 1);

		return RecurssionReverseString(stringToReverse) + s;
	}
	else
		return stringToReverse;
};

void BubbleSort(int listToSort[], int lengthOfList)
{
	bool swapped;
	int i, holder, newLength = 0;

	do
	{
		swapped = false;

		for (i = 0; i < lengthOfList - 1; ++i)
		{
			if (listToSort[i] > listToSort[i + 1])
			{
				holder = listToSort[i];
				listToSort[i] = listToSort[i + 1];
				listToSort[i + 1] = holder;
				swapped = true;
			}
		}
		--lengthOfList;
	} while (swapped);
}

void HeapSort(int listToSort[], int lengthOfList)
{

}

void MyMergeIntoArray(int* a, int* b, int aLength, int bLength)
{
	int totalLength = aLength + bLength;
	for (int i = aLength; i < totalLength; ++i)
		a[i] = b[i - bLength - 1];

	for (int i = aLength; i < totalLength; ++i)
	{
		int holder = i;
		while (a[holder] < a[holder - 1])
		{
			swap(a[holder], a[holder - 1]);
			--holder;
		}
	}

	for (int i = 0; i < totalLength; ++i)
		cout << a[i] << ", ";
}

void BookMergeIntoArray(int* a, int* b, int lastA, int lastB)
{
	int indexA = lastA - 1;
	int indexB = lastB - 1;
	int indexMerged = lastB + lastA - 1;

	while (indexB >= 0)
	{
		if (indexA >= 0 && a[indexA] > b[indexB])
		{
			a[indexMerged] = a[indexA];
			--indexA;
		}
		else
		{
			a[indexMerged] = b[indexB];
			--indexB;
		}
		--indexMerged;
	}

	for (int i = 0; i < lastA + lastB; ++i)
		cout << a[i] << ", ";
}

string SortAnagram(string s)
{
	for (int i = 1; i < s.length(); ++i)
	{
		int holder = i;
		if (s[holder] < s[holder - 1] && holder >= 1)
		{
			swap(s[holder], s[holder - 1]);
			--holder;
		}
	}

	return s;
}

void AnagramAlgorithm(string anagrams[])
{

}