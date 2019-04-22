//
//  E02_Bitwise.cpp
//  Unit1_exercise2_understanding_bitwise
//

/*

Note:
Implement the functions in this exercise file to make the tests
pass in E02_BitwiseSpec.cpp file.

Your primary goal is to implement all these functions by using
bitwise operators only.

*/

int andOfEachByte(int n) {
	int p = 0;
	int k = 0xFF;
	int m = n;
	for (p = 0; p<32;){
		m = n >> p;
		k = k&m;
		p = p + 8;
	}

	return k;
}

//
// Note1:
// implement the function using bitwise operators only
// should not use * and + operators.
int numberFromBits(int bits[32]) {
	int sum = 0;

	for (int i = 0, j = 31; i < 32, j >= 0; i++, j--){
		sum = sum | (bits[j] << i);

	}
	return sum;
}

//
// Note2:
// implement the function using bitwise operators only
// should not use % and / operators.
void bitsFromNumber(int n, int bits[32]) {
	for (int i = 0; i<32; i++){
		bits[i] = 0;
	}

	if (n<0){
		n = 0x7FFFFFFF - (n*-1) + 1;
		bits[0] = 1;
	}
	int k = 1, m = n;
	for (int i = n, j = 31; i>0 && j >= 0; j--){

		i = n >> k;
		bits[j] = m ^ (i << 1);
		m = i;
		k = k + 1;
	}
}

//
// Note3:
// Refer this to understand how numbers are represented in binary format
// https://www.youtube.com/watch?v=qrUjFtZZWf4
// mainly how negative number are represented.
//
// implement this function by calling above bitsFromNumber function only.
//
int numberOfOnesInBinary(int n) {
	int bits[32];
	bitsFromNumber(n,bits);
	int c = 0;
	for (int i = 0; i < 32; i++){
		if (bits[i] == 1){
			c++;
		}
	}
	return c;
}

//
// Returns
//  1 - yes
//  0 - no
//
int leastSignificantByte(unsigned long int n) {
	return n & 0xFF;
}

int mostSignificantByte(unsigned long int n) {
	n = n >> 24;
	return leastSignificantByte(n);
}

unsigned long int reverseOfNumberByByte(unsigned long int n) {
	int byte3 = mostSignificantByte(n);
	int byte2 = mostSignificantByte(n << 8);
	int byte1 = leastSignificantByte(n >> 8);
	int byte0 = leastSignificantByte(n);
	
	if (n < 0xFFFFFF){
		unsigned long int reverse = (byte0 << 16) | (byte1 << 8) | byte2;
		return reverse;
	}
	else{ unsigned long int reverse = (byte0 << 24) | (byte1 << 16) | (byte2 << 8) | byte3; 
	return reverse;
	}

	
}
int isPalindromeInBase256(unsigned long int n) {
	unsigned long int n1 = reverseOfNumberByByte(n);
	if (n < 256){
		return 1;
	}
	
	if (n1 != n){
		return 0;
	}
	return 1;
}