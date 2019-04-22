/*

  Maximum Marks: 30
  
  Problem code: Sum of Digits
  
  Problem Statement:
  Find the sum of digits of the given number in base N.
  Repeat this process till the sum of the digits becomes a single digit.
  e.g:
  ("123456", 10) => '3'
 
  sum of all the digits in (123456) is 21,
  since it has more than one digit, we repeat the process.
  sum of all the digits in (21) is 3,
  so return '3'

  ("abc", 16) => a + b + c => 21 => '3'
  ("101", 2) => 1 + 0 + 1 => 10 => '1'
  ("xyz", 36) => x + y + z => 2u => 2 + u => 'w'

  Returns the single digit as character.

  2 <= base <= 36
  1 <= number of digits in 'number' <= 10000
*/
#include<string.h>
#include<math.h>
#include<stdlib.h>

int converttodeci(char input[], int base){
	int sum = 0;
	int val;
	strupr(input);
	int len = strlen(input);
	int power = len - 1;
	for (int x = 0; x<len; x++, power--)
	{
		val = input[x] - 48;
		if (val>9)
			val -= 7;
		for (int i = 0; i < power; i++){
			base = base*base;
		}
		sum += val*base;
	}
	return sum;
}

char sumOfDigits(char number[], int base) {

	int result = converttodeci(number, base);
	int res = 0;
	while (result > 10){
		res = 0;
		while (result > 0){
			res += result % 10;
			result /= 10;
		}
		result = res;
	}
	if (base == 2){
		result = result / 2;
	}
	return result + '0';
}
