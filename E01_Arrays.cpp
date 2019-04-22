//
//  E01_Arrays.cpp
//  Unit03_Exercise01_Understanding_Arrays
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E01_ArraysSpec.cpp file.
 
 */

#include "E01_Arrays.h"


/*
 OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
 integer in the array.
 Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1)
 
 INPUTS: An Integer array and the length of the array
 
 OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array
 
*/

int maxPosNegSum(int *numbers, int size) {
	int max = numbers[0], min = 999,c=0,p=0;
	for (int i = 0; i < size; i++){
		if ((max < numbers[i])&&(numbers[i]>=0)){
			c = 1;
			max = numbers[i];
		}
		else if ((min >= (numbers[i]*-1)) && (numbers[i]<0)){
			p = 1;
			min = numbers[i]*-1;
		}
	}
	if ((p == 0) || (c == 0)){
		return 0;
	}
	int k = max - min;
    return k;
}


/*
 OVERVIEW:  given an array that has duplicate values remove all duplicate values.
 E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]
 
 Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]
 
 INPUTS: Integer array and length of the array .
 
 OUTPUT: Update input array by removing duplicate values and return the final array length
 
 NOTES: Don't create new array, try to change the input array.
 */
#include<malloc.h>
int removeDuplicates(int *numbers, int size) {
//	int *index = (int *)malloc(sizeof(int) * 1000);
	int index[100];
	for (int i = 0; i < size; i++){
		index[numbers[i]] = 0;
		int l = index[numbers[i]];
	}
	for (int i = 0; i < size; i++){
		index[numbers[i]]++;
	}
	int c = 0;
	for (int i = 0,j=0; i < size; i++){
		if (index[numbers[i]] != 0){
			numbers[j] = numbers[i];
			index[numbers[i]] = 0;
			j++;
			c++;
		}
	}
    return c;
}
