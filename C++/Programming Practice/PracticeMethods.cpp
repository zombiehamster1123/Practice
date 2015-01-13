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