#include "bitwise.h"

#define BIT_LIMIT 8

int mult_by_pow_2(int number, int power)
{
	return number << power;
}

TEMPLATED void printBitWise(T num)
{
	std::bitset<BIT_LIMIT> x(num);
	std::cout << num << " = " << x << "\n";
}

void bitShiftRight(int shiftee, int shifter)
{
	printBitWise(shiftee >> shifter);
}

void bitShiftLeft(int shiftee, int shifter)
{
	printBitWise(shiftee << shifter);
}

void bitNegate(int num)
{
	printBitWise(~num);
}

void bitShiftOr(int num1, int num2)
{
	printBitWise(num1);
	printBitWise(num2);
	printBitWise(num1 | num2);
}

void bitShiftAnd(int num1, int num2)
{
	printBitWise(num1);
	printBitWise(num2);
	printBitWise(num1 & num2);
}

void bitShiftXor(int num1, int num2)
{
	printBitWise(num1);
	printBitWise(num2);
	printBitWise(num1 ^ num2);
}

// (1 << place) - shift a 1 over by the place amount : ex 1 << 3 = 00000100
int singlePlace(int place)
{
	return 1 << place;
}

// Makes sure that the number 
// specified is within the range of bits
bool checkPlace(int place)
{
	if (place < BIT_LIMIT && place >= 0)
		return true;
	else
		return false;
}

// Returns bit in number passed in
int getBit(int num, int place)
{
	//printBitWise(num);

	if (checkPlace(place))
		// (num & (1 << place)) - combine the two and only if both places are 1 keep bit
		// ((num & (1 << place)) != 0) - if new number != 0 return true (1), if it does return false (0)
		return ((num & singlePlace(place)) != 0);
	else
		return -1;
}

// Sets bit in place to 1 and returns new number
int setBit(int num, int place)
{
	printBitWise(num);

	if (checkPlace(place))
		// num | (1 << place) -  wherever a 1 is in either number set variable to 1
		return num | singlePlace(place);
	else
		return -1;
}

// Sets bit in place to 0 and returns new number
int clearBit(int num, int place)
{
	printBitWise(num);

	if (checkPlace(place))
		// ~singlePlace(place) - reverse all bits : ex 00010000 = 11101111
		// so if bit exists in original number it will 
		// guarantee be gone while preserving other bits
		return num & ~singlePlace(place);
	else
		return -1;
}

int returnBitsUpToPlace(int num, int place)
{
	printBitWise(num);

	if (checkPlace(place))
		// singlePlace(place) - 1 - returns value of all 1 up to place
		// ex: 16 (00010000) - 1 = 15 (00001111)
		return num & (singlePlace(place) - 1);
	else
		return -1;
}

int returnBitsPastPlace(int num, int place)
{
	printBitWise(num);

	if (checkPlace(place))
		return num & ~(singlePlace(place) - 1);
	else
		return -1;
}

int myInsertNumber(int destination, int source, int place1, int place2)
{
	printBitWise(destination);
	printBitWise(source);

	int num = 0;
	int length = place2 - place1;

	while (length > 0)
	{
		num = num << 1;
		num += 1;
		--length;
	}

	num = num << place1;
	destination = destination & ~num;
	destination = destination | (source << place1);

	printBitWise(destination);
	return destination;
}

int bookInsertNumber(int destination, int source, int place1, int place2)
{
	// Get a number of all ones
	int allOnes = ~0;

	// Get a number of all 1s passed place2
	int left = allOnes << (place2 + 1);

	// Get a number of 1s before place1
	int right = (allOnes << place1) - 1;

	// Create a new clear number combining the number above
	int mask = left | right;

	// Use the new clear number to free up space in the destination
	int dest_cleared = destination & mask;

	// Add the new number into the correct place
	int source_shifted = dest_cleared | (source << place1);

	// Print out and return new number
	printBitWise(source_shifted);
	return source_shifted;
}

int countBits(int source)
{
	int counter = 0;
	// x = x & (x - 1) - remove last significant bit
	for (int x = source; x != 0; x = x & (x - 1))
		++counter;

	return counter;
}

int liamCountBits(int source)
{
	int counter = 0;

	while (source)
	{
		counter += 1 & source;
		source = source >> 1;
	}

	return counter;
}

int maxXor(int l, int r) {
	return (l ^ r | (1 << countBits(l ^ r)) - 1);
}

int maxXor2(int l, int r) {
	int counter = 0;
	for (int i = l; i <= r; ++i) {
		for (int j = l + 1; j <= r; ++j) {
			if (j != i && int(j ^ i) > counter) {
				counter = int(j ^ i);
			}
		}
	}

	return counter;
}

void bitOddEvenSwap(int num)
{
	printBitWise(num);
	for (int i = 0; i < BIT_LIMIT; i += 2)
	{
		int holder1 = getBit(num, i);
		int holder2 = getBit(num, i + 1);
		if (getBit(num, i) != getBit(num, i + 1))
		{
			num = num ^ (1 << i);
			num = num ^ (1 << i + 1);
		}
	}
	printBitWise(num);
}

int bookSwapOddEvenBits(int num)
{
	printBitWise(num);

	// (num & 0xaaaaaaaa) - mask all odd bits
	// ((num & 0xaaaaaaaa) >> 1) - shift all even bits right 1
	// (num & 0x55555555) - mask all even bits
	// ((num & 0x55555555) << 1) - shift all odd bits left 1
	// Then combine
	int holder = (((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1));

	printBitWise(holder);
	return holder;
}

int numFlipConverts(int A, int B)
{
	printBitWise(A);
	printBitWise(B);
	// XOR to find all bits that will flip
	int newNum = A ^ B, counter = 0;
	printBitWise(newNum);

	while (newNum)
	{
		// Add whether or not a bit exists at 1
		// Then shift over and check
		counter += newNum & 1;
		newNum = newNum >> 1;
	}

	return counter;
}

int bookBitSwapRequired(int a, int b)
{
	int count = 0;
	// c = c & (c - 1) - gets rid of the last significant bit
	// Ex: 13 (1101) & 12 (1100) = 12 (1100)
	// 12 (1100) & 11 (1011) = 8 (1000)
	// 8 (1000) & 7 (0111) = 0
	// Total - 3 times
	for (int c = a ^ b; c != 0; c = c & (c - 1))
		++count;
	return count;
}