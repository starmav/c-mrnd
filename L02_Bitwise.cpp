//
//  L02_Bitwise.h
//  Unit1_lesson2_understanding_bitwise
//

//
// Bitwise operations
//

/*
 
 Note:
 Bitwise operations are necessary particularly in lower-level
 programming such as device drivers, low-level graphics,
 communications protocol packet assembly, and decoding.
 
 In this lesson we will understand how bitwise operators work.
 - primarily how bitwise XOR, AND, OR, and SHIFT works.
 - Understand everything in this wiki page:
   https://en.wikipedia.org/wiki/Bitwise_operations_in_C
 
 You read the code in this file and understand the behaviour.
 And fill the blanks in corresponding file: L02_BitwiseSpec.cpp under spec project.
 
 *****important******
 And DO NOT modify any functions in the lesson files in src project
 except the comments in three_things_i_learnt() function.
 */


//
// Note#1:
// XOR is used in multiple applications in Computer Science.
// for e.g:
// XOR is sometimes used as a simple mixing function in cryptography.
//
// for more examples check this wiki page
// https://en.wikipedia.org/wiki/Exclusive_or#Bitwise_operation
//
int xorAB(int a, int b) {
	return (a^b);
}

int xorBA(int a, int b) {
	return (b^a);
}

int xorAA(int a) {
	return (a^a);
}

int xorAZero(int a) {
	return (a ^ 0);
}

int xorABA(int a, int b) {
	return (a^b^a);
}

int xorAAB(int a, int b) {
	return (a^a^b);
}

int xorNumbers(int numbers[], int size) {
    int xorOfAll = numbers[0];
    for (int i = 1; i < size; i++) {
        xorOfAll = xorOfAll ^ numbers[i];
    }
    return xorOfAll;
}

//
// Range of n is
//  0 <= n <= 31
//
int turnOnNthBit(int bitFlags, int n) {
    int res = bitFlags;
	res = res | (1 << n);
	return res;
}

//
// Return
//  2 power n.
//
int twoPowerN(int n) {
	return (1 << n);
}

//
// Returns
//  1 - odd
//  0 - even
//
int isOdd(int n) {
	return (n & 0x1);
}

//
// Returns
//  1 - even
//  0 - odd
//
int isEven(int n) {
	if (isOdd(n)) {
		return 0;
	}
	return 1;
}


int leastSignificantByte(int n) {
    return n & 0xFF;
}

int mostSignificantByte(int n) {
    n = n >> 24;
    return leastSignificantByte(n);
}

int reverseOfNumberByByte(int n) {
    int byte3 = mostSignificantByte(n);
    int byte2 = mostSignificantByte(n << 8);
    int byte1 = leastSignificantByte(n >> 8);
    int byte0 = leastSignificantByte(n);
    
    int reverse = (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | byte3;
    
    return reverse;
}

static void three_things_i_learnt() {
    /*
     -right shift means divide by 2
     -left shift means multiply by 2
     -using xor if both inputs are same that is 1,1 or 0,0 then output is 0 and if 1,0 or 0,1 then output is 1.
     */
}
