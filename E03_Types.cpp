//
//  E03_Types.cpp
//  Unit02_Exercise03_Understanding_Types
//

#include "E03_Types.h"
#include "L02_Strings.h"

//
// Note: The digits in the Base256Number are saved in reverse order.
//

// Note:
// In this file you should not modify 3 functions,
// for which implementation is already given in this file
// The 3 functions are:
// - Base256Number *newNumberInBase256(int n);
// - Base256Number *multiplyInBase256(Base256Number *pNumber1, Base256Number *pNumber2)
// - Base256Number *integerDivisionInBase256(Base256Number *pNumber, Base256Number *pDiv)


//
// creates a new structure for base 256 number
// and initialize with n in base-256
//
// DON'T MODIFY THE CODE OF THIS FUNCTION
//
Base256Number *newNumberInBase256(int n) {
	int base = 256;

	int numberOfDigits = 0;
	int number = n;
	do {
		numberOfDigits++;
		number /= base;
	} while (number > 0);

	Base256Number* base256Number = (Base256Number*)malloc(sizeof(Base256Number));
	base256Number->numberOfDigits = numberOfDigits;
	base256Number->digits = (UInt8*)malloc(numberOfDigits * sizeof(UInt8));

	for (int digitPos = 0; digitPos < numberOfDigits; digitPos++) {
		base256Number->digits[digitPos] = n % base;
		n /= base;
	}

	return base256Number;
}

// Implement the function to
// print the given base 256 number using the format sepcifiers
// %D and %H
//
// For example for 4 digits base 256 number with format specifier
// %D - print digits in the format - 15.0.254.11
// %H - print digits in the format - 0f:00:0a:0b
//
// e.g: like (format, pNumber) => output string
// ("Number (base 256): %D", {4, [11, 254, 0, 15]) => "Number (base 256): 15.0.254.11"
// ("Number (base 256): %H", {4, [11, 254, 0, 15]) => "Number (base 256): 0f:00:fe:0b"
//
// Note: Each digit in base 256 is saved in reverse order
//
char *printBase256Number(char *format, Base256Number *pNumber) {
	char *result = (char *)malloc(sizeof(char) * 100000);
	int i = 0, j, i1;
	while (((format[i] != '%') && (format[i + 1] != 'D')) || ((format[i] != '%') && (format[i + 1] != 'H'))){
		result[i] = format[i];
		i++;
	}
	i1 = i;
	if ((format[i] == '%') && (format[i + 1] == 'D')){
		for (j = pNumber->numberOfDigits - 1; j >= 0; j--){
			int k = pNumber->digits[j];
			int l = k;
			char s[100];
			int h = 0;
			if (l == 0){
				s[h] = '0';
				h++;
			}
			else{
				while (l > 0){
					s[h] = (l % 10) + '0';
					h++;
					l = l / 10;
				}
			}
			s[h] = '\0';
			for (h = h - 1; h >= 0; h--){
				result[i] = s[h];
				i++;
			}
			result[i] = '.';
			i++;
		}
	}
	else{
		for (j = pNumber->numberOfDigits - 1; j >= 0; j--){
			int k = pNumber->digits[j];
			int l = k;
			char s[100];
			int h = 0;
			if (l < 16){
				k = 1;
			}
			if (l == 0){
				s[h] = '0';
				h++;

			}

			else{
				while (l != 0) {
					int k;
					k = l % 16;

					if (k < 10)
						k = k + 48;
					else
						k = k + 55 + 32;
					s[h] = k;
					h++;
					l = l / 16;
				}
			}
			if (k == 1){
				s[h] = '0';
				h++;
			}
			s[h] = '\0';
			for (h = h - 1; h >= 0; h--){
				result[i] = s[h];
				i++;
			}
			result[i] = ':';
			i++;

		}
	}
	i = i - 1;


	for (i1 = i1 + 2; format[i1] != '\0'; i1++){
		result[i] = format[i1];
		i++;
	}
	result[i] = '\0';
	return result;
}

//
// Returns
//  1 - yes
//  0 - no
//
// check if the base 256 number is palindrome or not
//
int isPalindrome(Base256Number *number) {
	int i, j;
	for (i = 0, j = number->numberOfDigits - 1; i <= j; i++, j--){
		int k = number->digits[i];
		int l = number->digits[j];
		if (k != l){
			return 0;
		}
	}
	return 1;
}

//
// add in base 256
//
// implement the function to add 2 base 256 numbers
//
/*
Base256Number *addInBase2561(Base256Number *pNumber1, Base256Number *pNumber2) {
int min, max, k = 0;
unsigned int numberOfDigitssum;
if (pNumber1->numberOfDigits<pNumber2->numberOfDigits){
min = pNumber1->numberOfDigits;
max = pNumber2->numberOfDigits;
}
else{
min = pNumber2->numberOfDigits;
max = pNumber1->numberOfDigits;
}
UInt8 *digitsSum = (UInt8 *)malloc(1000 * sizeof(UInt8));
unsigned int carry = 0;
for (int i = 0; i<min; i++){
int sum = pNumber1->digits[i] + pNumber2->digits[i] + carry;
carry = 0;
if (sum>256){
sum = sum - 256;
carry = 1;
}
digitsSum[k++] = sum;
}
for (int i = min; i<pNumber1->numberOfDigits; i++){
digitsSum[k++] = pNumber1->digits[i] + carry;
carry = 0;
}
for (int j = min; j<pNumber2->numberOfDigits; j++){
digitsSum[k] = pNumber2->digits[j] + carry;
k = k + 1;
carry = 0;
}
numberOfDigitssum = max;
if (carry == 1){
digitsSum[k++] = carry;
numberOfDigitssum += 1;
}
Base256Number *pNumberSum = (Base256Number*)malloc(sizeof(Base256Number));
pNumberSum->numberOfDigits = numberOfDigitssum;
pNumberSum->digits = digitsSum;
return pNumberSum;

//return newNumberInBase256();

}
*/
Base256Number *addInBase256(Base256Number *pNumber1, Base256Number *pNumber2) {
	int len1 = pNumber1->numberOfDigits;
	int len2 = pNumber2->numberOfDigits;
	Base256Number *result = (Base256Number *)malloc(sizeof(Base256Number));
	result->digits = (UInt8 *)malloc(10000 * sizeof(UInt8));
	result->numberOfDigits = 0;
	int i = 0, j = 0, k = 0, carry = 0;
	for (i = 0, j = 0, k = 0; (i < len1) && (j < len2); i++, j++, k++){
		result->numberOfDigits++;
		int k1 = pNumber1->digits[i];
		int k2 = pNumber2->digits[j];
		result->digits[k] = 0;
		result->digits[k] = (UInt8)(((k1 + k2) % 256) + carry);
		carry = (k1 + k2) / 256;
	}

	if (len1 > len2){
		while (i < len1){
			result->numberOfDigits++;
			int k1 = pNumber1->digits[i];
			if (carry != 0){
				result->digits[i] = carry + k1;
				carry = 0;
			}
			else{
				result->digits[i] = k1;
			}
			i++;
		}
	}
	else if (len1 < len2){
		while (j < len2){
			result->numberOfDigits++;
			int k1 = pNumber2->digits[j];
			if (carry != 0){
				result->digits[j] = carry + k1;
				carry = 0;
			}
			else{
				result->digits[j] = k1;
			}
			j++;
		}
	}
	else{
		if (carry != 0){
			result->digits[k] = carry;
			result->numberOfDigits++;
		}
	}
	return result;
}


//
// Return
//  1 - when pNumber1 > pNumber2
//  0 - otherwise
//
int isGreater(Base256Number *pNumber1, Base256Number *pNumber2) {
	int i;

	if ((pNumber1->numberOfDigits) > (pNumber2->numberOfDigits)){
		return 1;
	}
	else if ((pNumber1->numberOfDigits) < (pNumber2->numberOfDigits)){
		return 0;
	}
	else{
		i = pNumber1->numberOfDigits - 1;
	Hello:
		if (i >= 0){
			if ((pNumber1->digits[i]) >(pNumber2->digits[i])){
				return 1;
			}
			else if ((pNumber1->digits[i]) < (pNumber2->digits[i])){
				return 0;
			}
			else{
				i--;
				goto Hello;
			}
		}
	}
	return 0;

}
/*int isGreater2(Base256Number *pNumber1, Base256Number *pNumber2) {
int count = 0;
if (pNumber1->numberOfDigits > (pNumber2->numberOfDigits))
return 1;
else if (pNumber1->numberOfDigits < (pNumber2->numberOfDigits))
return 0;
else if (pNumber1->numberOfDigits == (pNumber2->numberOfDigits)){
for (int i = 0; i < pNumber1->numberOfDigits; i++){
if (pNumber1->digits[i] > pNumber2->digits[i])
count++;
}
}
if (count >= 1)
return 1;

return 0;
}
*/
int isGreater1(Base256Number *pNumber1, Base256Number *pNumber2) {
	//if ((pNumber1->numberOfDigits<10) && (pNumber1->digits[pNumber1->numberOfDigits - 1] != 1) && (pNumber1->digits[pNumber1->numberOfDigits - 1] != 255)){
	unsigned long long int num1 = 0, num2 = 0;
	unsigned long long int pow = 1;
	for (int i = pNumber1->numberOfDigits - 1; i >= 0; i--){
		num1 = num1 + pNumber1->digits[i] * pow;
		pow = pow * 256;
	}
	pow = 1;
	for (int i = pNumber2->numberOfDigits - 1; i >= 0; i--){
		num2 = num2 + pNumber2->digits[i] * pow;
		pow = pow * 256;
	}
	if (num1 > num2){
		return 1;
	}
	return 0;
}

//int k = isGreater1(pNumber1, pNumber2);
//return k;
//}


//
// Return
//  1 - are equal
//  0 - not equal
//
int areEqual(Base256Number *pNumber1, Base256Number *pNumber2) {
	int i, j;
	for (i = pNumber1->numberOfDigits - 1, j = pNumber2->numberOfDigits - 1; (i >= 0) && (j >= 0); i--, j--){
		int k = pNumber1->digits[i];
		int l = pNumber2->digits[j];
		if (k != l){
			return 0;
		}
	}
	return 1;
}

//
// increments the given number by 1
//
// Note: Need to reallocate memory for pNumber->digits when needed
//
void incrementInBase256(Base256Number *pNumber) {
	unsigned long long int a = 0, pow = 1;
	for (int i = 0; i < pNumber->numberOfDigits; i++){
		a = a + (pNumber->digits[i] * pow);
		pow = pow * 256;
	}
	a = a + 1;
	int base = 256;

	int numberOfDigits = 0;
	unsigned long long int number = a;
	do {
		numberOfDigits++;
		number /= base;
	} while (number > 0);


	pNumber->numberOfDigits = numberOfDigits;
	pNumber->digits = (UInt8*)malloc(numberOfDigits * sizeof(UInt8));

	for (int digitPos = 0; digitPos < numberOfDigits; digitPos++) {
		pNumber->digits[digitPos] = a % base;
		a /= base;
	}
}

//
// you need make the test cases for these last 2 functions
// pass by implementing the above functions
// - multiplyInBase256
// - integerDivisionInBase256
//
//
// DON'T MODIFY THE CODE OF THIS FUNCTION
//
Base256Number *multiplyInBase256(Base256Number *pNumber1, Base256Number *pNumber2) {
	Base256Number* result = newNumberInBase256(0);
	Base256Number* count = newNumberInBase256(1);
	Base256Number *pOne = newNumberInBase256(1);

	while (!isGreater(count, pNumber2)) {
		result = addInBase256(result, pNumber1);
		count = addInBase256(count, pOne);
	}
	return result;
}

//
// integer division
//
//
// DON'T MODIFY THE CODE OF THIS FUNCTION
//
Base256Number *integerDivisionInBase256(Base256Number *pNumber, Base256Number *pDiv) {

	Base256Number *pQuotient = newNumberInBase256(0);
	Base256Number *pTempNumber = newNumberInBase256(0);
	Base256Number *pOne = newNumberInBase256(1);

	if (isGreater(pDiv, pNumber)) {
		return pQuotient;
	}

	pTempNumber = addInBase256(pTempNumber, pDiv);
	while (isGreater(pNumber, pTempNumber)) {
		pQuotient = addInBase256(pQuotient, pOne);
		pTempNumber = addInBase256(pTempNumber, pDiv);
	}

	if (areEqual(pNumber, pTempNumber)) {
		pQuotient = addInBase256(pQuotient, pOne);
	}

	return pQuotient;
}
