// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"

bool checkPrime(uint64_t value) 
{
	if (value < 2)  return false;
	if (value == 2)  return true;
	if (value % 2 == 0)  return false;
	uint64_t b = value / 2 + 1;
	for (uint64_t i = 3; i <= b; i = i + 2)
	{
		if (value % i == 0)  return false;
	}
	return true;
}

uint64_t nPrime(uint64_t n) 
{
	if (n == 2)  return 1;
	uint64_t n_i = 1;					//n_i счётчик простых чисел
	for (uint64_t x = 3;; x += 2)	
	{
		if (checkPrime(x) == true)  n_i++;
		if (n_i == n)  return x;
	}
}

uint64_t nextPrime(uint64_t value) 
{
	for (uint64_t i = value+1;; i++)
	{
		if (checkPrime(i) == true)  return i;
	}
}

uint64_t sumPrime(uint64_t hbound) 
{
	if (hbound < 3)  return 0;
	if (hbound == 3)  return 2;
	uint64_t sum = 2;
	for (uint64_t i = 3; i < hbound; i += 2) if (checkPrime(i) == true)
	{
		if (checkPrime(i) == true)  sum += i;
	}
	return sum;
}
