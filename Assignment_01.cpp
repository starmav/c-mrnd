/*
Note:
1. Read instructions for each function carefully.
2. Feel free to create new functions if needed. Give good names!
3. Check the reference links when ever given.
4. After solving the question and making corresponding test cases pass
   - reflect on where is the gap in your understanding, while solving the problem.
   - if you have to create a similar problem, how would you do/tweek it?
   - when your friends seek help, instead of explaining your logic,
     give hints to solve. Always.
*/

//
// butterfly number for the given integer
//
// e.g:
// 20  => "2002"
// -2  => "-22-"
//
// To get butterfly number for the given number 20,
// take its reversal 02 and join them to form "2002".
//
#include<string.h>
void butterflyNumber(int n, char butterfly[23]) {
	int i, j = 0, k = 0;
	if (n == 0){
		butterfly[0] = '0';
		butterfly[1] = '0';
		butterfly[2] = '\0';
	}
	else{
		for (i = 0; i<23; i++){
			butterfly[i] = ' ';
		}
		if (n<0){
			i = n*(-1);

		}
		else{
			i = n;
		}
		for (; i > 0;){
			j = i % 10;
			butterfly[k] = j + '0';
			k++;
			i = i / 10;
		}
		int h = k - 1;
		i = k - 1;

		while (i >= 0){
			butterfly[k] = butterfly[i];
			i--;
			k++;

		}
		butterfly[k] = '\0';
		int o = k + 1;
		k = k - 1;
		while (h >= 0){
			char l = butterfly[h];
			butterfly[h] = butterfly[k];
			butterfly[k] = l;
			k--;
			h--;
		}
		if (n<0){
			butterfly[o + 1] = '\0';
			butterfly[o] = '-';
			for (i = o - 1; i >= 0; i--){
				butterfly[i] = butterfly[i - 1];
			}
			butterfly[0] = '-';
		}
	}
}
//
// Write a function that finds the positive integers up to 100
// that are palindromes in base b
//
// b > 1
//
// saves a list of base–10 numbers less than or equal to 100
// that are palindromic in base b.
// and return the count.
//
// e.g:
// 10 => { 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99}, 18 palindromes
// 2  => { 1, 3, 5, 7, 9, 15, 17, 21, 27, 31, 33, 45, 51, 63, 65, 73, 85, 93, 99}, 19 palindromes
//
// Once you have completed this function, check this reference.
// Ref: http://www.worldofnumbers.com/nobase10.htm
//

char reVal(int num)
{
	if (num >= 0 && num <= 9)
		return (char)(num + '0');
	else
		return (char)(num - 10 + 'A');
}

void strev(char *str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}
char* fromDeci(char res[], int base, int inputNum)
{
	int index = 0;  
	while (inputNum > 0)
	{
		res[index++] = reVal(inputNum % base);
		inputNum /= base;
	}
	res[index] = '\0';
	strev(res);

	return res;
}
int isPalindrome(char num[]){
	for (int i = 0, j = strlen(num)-1; i <= j; i++, j--){
		if (num[i] != num[j]){
			return 0;
		}
	}
	return 1;
}
int palindromeNumbers(int b, int numbers[]) {
	int count = 0;
	char res[100];
	for (int i = 1; i <= 100; i++){
		 fromDeci(res,b,i);
		if (1==isPalindrome(res)){
			numbers[count] = i;
			count++;
		}
	}
    return count;
}

//
// Write a function that finds the closest (to n) 5 positive integers
// that are even
//
// return a sorted list of assending order even numbers (greater than zero).
//
// Note:
// In case of conflict return the smallest number.
// let us say for the 5th element, 2 numbers are at same distance from n.
// then include the smallest of the 2 numbers.
//
// e.g:
// 14  => { 8, 10, 12, 16, 18}; // 8 and 20 are at equal distance from 14, we pick 8.
// 15  => { 10, 12, 14, 16, 18}; // 10 and 20 are at equal distance from 15, we pick 10.
//
// Ref: https://en.wikipedia.org/wiki/Parity_of_zero
//
// Note: You must return only numbers which are greater than zero.
//
void closest5EvenNumbers(int n, int evens[5]) {
	if ((n % 2) == 0){
		int i = n - 6;
		int j = 0;
		for (; (j < 5);){
			if (i == n){
				i++;
			}
			else if (i <= 0){
				i++;
			}
			else{
				if ((i % 2) == 0){
					evens[j] = i;
					j++;

				}
				i++;
			}
		}
	}
	else{
		int i = n - 5;
		int j = 0;
		for (; (j < 5);){
			if (i == n){
				i++;
			}
			else if (i <= 0){
				i++;
			}
			else{
				if ((i % 2) == 0){
					evens[j] = i;
					j++;

				}
				i++;
			}
		}
	}
}
//
// Write a function that finds the closest 5 positive integers
// that are palindromes in base b.
//
// b > 1
//
// return a sorted list of assending order.
//
// Note:
// 1. In case of conflict return the smallest number.
//    let us say for the 5th element, 2 numbers are at same distance from n.
//    then include the smallest of the 2 numbers.
// 2. Palindromes must be greater than zero.
//    for i = 0 to 4, palindromes[i] > 0.
//
int isPalin(char res[], int base, int inputNum)
{
	int index = 0;
	while (inputNum > 0)
	{
		int rem = inputNum%base;
		if (rem < 10){
			res[index] = rem + 48;
			index++;
		}
		else{
			if (rem > 128){
				return -1;
			}
			res[index] = rem + 55;
			index++;
		}
		inputNum = inputNum / base;
	}

	int i = 0, found = 0;
	for (int k = index - 1; k >= 0; k--){
		if (res[i] == res[k]){
			i++;
		}
		else{
			found = 1;
			break;
		}
	}
	if (found == 0){
		return 1;
	}
	return -1;
}
void closest5PalindromeNumbers(int n, int b, int palindromes[5]) {
	
		int c = 0, u = 0;
		for (int i = n - 1, k = n, j = 0; j < 5;){
			if ((c == 0) && (i > 0)){ u = i; i = i - 1; }
			else{
				k = k + 1;
				u = k;
			}

			char p[100];
			
			int l = isPalin(p, b, u);
			if (l == 1){
				palindromes[j] = u;
				j++;

			}
			if (c == 0){ c = 1; }
			else{
				c = 0;
			}
		}
		for (int i = 0; i < 5; ++i)
		{

			for (int j = i + 1; j < 5; ++j)
			{

				if (palindromes[i] > palindromes[j])
				{

					int a = palindromes[i];
					palindromes[i] = palindromes[j];
					palindromes[j] = a;

				}

			}

		}
	
	
}
