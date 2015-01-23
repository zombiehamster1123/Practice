#ifndef BITWISE_H
#define BITWISE_H

#include <iostream>
#include <bitset>

#define TEMPLATED template<typename T>

int mult_by_pow_2(int, int);
TEMPLATED void printBitWise(T);
void bitShiftRight(int, int);
void bitShiftLeft(int, int);
void bitNegate(int);
void bitShiftOr(int, int);
void bitShiftAnd(int, int);
void bitShiftXor(int, int);
int singlePlace(int);
bool checkPlace(int);
int getBit(int, int);
int setBit(int, int);
int clearBit(int, int);
int returnBitsUpToPlace(int, int);
int returnBitsPastPlace(int, int);
int myInsertNumber(int, int, int, int);
int bookInsertNumber(int, int, int, int);
int countBits(int);
int liamCountBits(int);
int maxXor(int, int);
int maxXor2(int, int);
void bitOddEvenSwap(int);
int bookSwapOddEvenBits(int);
int numFlipConverts(int, int);
int bookBitSwapRequired(int, int);

#endif