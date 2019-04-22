//
//  E04_Memory.cpp
//  Unit02_Exercise04_Understanding_Memory
//

#include "E04_Memory.h"
#include <cmath>
//
// Prime factorization
//

// return an array of prime factors

DynamicList *primeFactors(int n) {
	DynamicList *result = (DynamicList *)malloc(sizeof(DynamicList));
	result->list = (int *)malloc(10000 * sizeof(int));
	result->count = 0;
	int j = 0;
	while (n % 2 == 0)
	{
		result->list[j] = 2;
		j++;
		result->count++;
		n = n / 2;
	}

	for (int i = 3; i <= sqrt(n); i = i + 2)
	{
		while (n%i == 0)
		{
			result->list[j] = i;
			result->count++;
			j++;
			n = n / i;
		}
	}


	if (n > 2){
		result->list[j] = n;
		result->count++;
	}
	return result;
}
