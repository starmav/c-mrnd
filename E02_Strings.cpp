//
//  E02_Strings.cpp
//  Unit02_Exercise02_Understanding_Strings
//


/*

Note:
Implement the functions in this exercise file to make the tests
pass in E02_StringsSpec.cpp file.
*/

#include "E02_Strings.h"
//
// sum of most significant digits of non-negative integers.
//
int sumOfMSDs(char *pNumber1, char *pNumber2) {
	int sum = (pNumber1[0] - '0') + (pNumber2[0] - '0');
	return sum;
}

//
// sum of 2 non-negative numbers
// pNumber1 and pNumber2 are numbers in string format
// e.g:
// "4", "2" => "6"
// "84", "37" => "121"
// "999", "1" => "1000"
//
// 0 < number of digits < 100
//
char *sum(char *pNumber1, char *pNumber2) {
	char* sum = (char *)malloc(sizeof(char) * 100);

	int i, j, x, y, k = 0;
	for (i = 0; pNumber1[i] != '\0'; i++);
	for (j = 0; pNumber2[j] != '\0'; j++);
	int carry = 0;
	for (x = i - 1, y = j - 1; (x >= 0) && (y >= 0); x--, y--){
		int s = (pNumber1[x] - '0') + (pNumber2[y] - '0') + carry;
		sum[k] = (s % 10) + '0';
		k++;
		carry = s / 10;
	}
	if (x > 0){
		while (x >= 0){
			int s = (pNumber1[x] - '0') + carry;
			sum[k] = (s % 10) + '0';
			k++;
			carry = s / 10;
			x--;
		}
	}
	else{
		while (y >= 0){
			int s = (pNumber2[y] - '0') + carry;
			sum[k] = (s % 10) + '0';
			k++;
			carry = s / 10;
			y--;
		}
	}
	if (carry > 0){
		sum[k] = carry + '0';
		k++;
	}
	sum[k] = '\0';
	for (i = 0, j = k - 1; i <= j; i++, j--){
		char p = sum[i];
		sum[i] = sum[j];
		sum[j] = p;
	}
	return sum;
}

//
// replicate string n times
//
//e.g:
// "aum ", 3 => "aum aum aum "
// "-integrity-inspire-insight-", 3 => "integrity-inspire-insight--integrity-inspire-insight--integrity-inspire-insight-"
//
char *replicateNTimes(char *mantra, int n) {
	char *str = (char*)malloc(sizeof(char) * 10000);
	int i = 0, j, k;
	for (k = 0; k < n; k++){


		for (j = 0; mantra[j] != '\0'; j++, i++)
		{
			str[i] = mantra[j];
		}
	}
	str[i] = '\0';
	return str;
}

//
// repeat character, position times
//
// e.g:
// "mrd" => "mrrddd"
// "btech" => "btteeecccchhhhh"
//
char *repeatPositionTimes(char *word) {
	char *str = (char*)malloc(sizeof(char) * 10000);
	int i = 0, j;
	for (j = 0; word[j] != '\0'; j++){
		for (int k = 1; k <= (j + 1); k++){
			str[i] = word[j];
			i++;
		}
	}
	str[i] = '\0';
	return str;
}

//
// scanf integer implementation
//
int scanfInt(char *input) {
	int num = 0;
	for (int i = 0; input[i] != '\0'; i++){
		num = num * 10 + (input[i] - '0');
	}
	return num;
}

//
// scanf float implementation
//
float scanfFloat(char *input) {
	float num = 0.0;
	int c = 0;
	for (int i = 0; input[i] != '\0'; i++){
		if ((c == 0) && (input[i] != '.')){
			num = num * 10 + (input[i] - '0');
		}
		if (input[i] == '.'){
			c++;
		}
		else if (c >0){
			float k = 1;
			for (int j = 1; j <= c; j++){
				k = k * 10;
			}
			k = (input[i] - '0') / k;
			num = num + k;
			c++;
		}
	}
	return num;
}

//
// printf implementation
//
// e.g:
// ("%d", 234) => "234"
// ("%3d",  3)  => "  3"
// ("%03d", 7) => "007"
//
char *printfInt(char *format, int n) {
	char *str = (char*)malloc(sizeof(char) * 100000);
	//char str[100];
	int i = 0;
	if (format[1] == 'd'){
		while (n > 0){
			str[i] = (n % 10) + '0';
			i++;
			n = n / 10;
		}
		str[i] = '\0';
	}
	else if ((format[1] - '0') == 0){
		int k = (format[2] - '0');
		while (n > 0){
			str[i] = (n % 10) + '0';
			i++;
			n = n / 10;
		}
		int j = 1, o = i;;
		while (j < (k - o + 1)){
			str[i] = '0';
			i++;
			j++;
		}
		str[i] = '\0';
	}
	else if ((format[1] - '0') > 0){
		int k = (format[1] - '0');
		while (n > 0){
			str[i] = (n % 10) + '0';
			i++;
			n = n / 10;
		}
		int j = 1, o = i;
		while (j < (k - o + 1)){
			str[i] = ' ';
			i++;
			j++;
		}
		str[i] = '\0';
	}
	for (int k = 0, j = i - 1; k <= j; k++, j--){
		char p = str[k];
		str[k] = str[j];
		str[j] = p;
	}
	return str;
}

//
// float format print
// e.g:
// ("%.2f", 2.34455f) => "2.34"
// ("%f",0.123456f) => "0.123456"
char *printfFloat(char *format, float n) {
	char *str = (char*)malloc(sizeof(char) * 100000);
	//char str[100];
	int s = n, i = 0;
	float num = n - (float)s;
	if (format[1] == 'f'){
		int k = 1;
		while (s > 0){
			str[i] = (s % 10) + '0';
			i++;
			s = s / 10;
		}
		str[i] = '.';
		i++;
		while (k < 7){
			int mul = 10;

			s = num*mul;
			num = (num*mul) - (float)s;
			str[i] = s + '0';
			i++;
			k++;
		}
		str[i] = '\0';
	}
	else{
		int n1 = format[2] - '0';
		int k = 1;
		if (s == 0){
			str[i] = (s % 10) + '0';
			i++;
		}
		else{
			while (s > 0){
				str[i] = (s % 10) + '0';
				i++;
				s = s / 10;
			}
		}
		str[i] = '.';
		i++;
		while (k <= n1){
			int mul = 10;
			float d = num*mul;
			s = (int)(num*mul);
			num = (float)(num*mul) - (float)s;
			str[i] = s + '0';
			i++;
			k++;
		}
		str[i] = '\0';
	}
	return str;
}

//
// create command line
// Note:
//  - with single space between arguments
//  - no spaces at the end
//
char *getCommandLine(int argc, char *argv[]) {
	char *str = (char*)malloc(sizeof(char) * 100000);

	int i = 0;
	for (int j = 0; j < argc; j++){
		for (int k = 0; argv[j][k] != '\0'; k++){
			str[i] = argv[j][k];
			i++;
		}
		if (j != argc - 1){
			str[i] = ' ';
			i++;
		}
	}
	str[i] = '\0';
	return str;
}

char *getExecutableName(int argc, char *argv[]) {
	int i = 0, j, c = 0;
	for (j = 0; j < argc; j++){
		for (int k = 0; argv[j][k] != '\0'; k++){
			if (argv[j][k] == '.'){
				if (argv[j][k + 1] == 'e'){
					if (argv[j][k + 2] == 'x'){
						if (argv[j][k + 3] == 'e'){
							if (argv[j][k + 4] == '\0'){
								c = 1;
								break;
							}
						}
					}
				}
			}
		}
		if (c == 1){
			break;
		}
	}

	return argv[j];
}

//
// remove white spaces in program statement
//
// Note: the characters between double quotes must not change
//
// e.g:
// 'printf (   "compiler first removes unnessary spaces"  )  ;'  =>
// 'printf("compiler first removes unnessary spaces");'
//
void removeSpaces(char *statement) {
	int c = 0;
	for (int i = 0; statement[i] != '\0'; i++){
		if (statement[i] == '"'){
			c++;
			if (c == 2){
				c = 0;
			}
		}
		if ((c == 0) && (statement[i] == ' ')){
			int j;
			for (j = i; statement[j] != '\0'; j++){
				statement[j] = statement[j + 1];
			}
			i--;
		}
	}
}


// Return
// 1 - if string t is suffix of s.
// 0 - otherwise

// returns 1 if the string t occurs at the end of the string s, and zero otherwise
int strend(char *s, char *t) {
	int i, j, x, y;
	for (i = 0; s[i] != '\0'; i++);
	for (j = 0; t[j] != '\0'; j++);
	if (j > i){
		return 0;
	}
	int c = 0;
	for (x = i - 1, y = j - 1; y >= 0; x--, y--){
		if (s[x] == t[y]){
			c++;
		}
	}
	if (c == j){
		return 1;
	}
	return 0;
}
