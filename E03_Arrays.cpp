//
//  E03_Arrays.cpp
//  Unit03_Exercise03_Understanding_Arrays
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E03_ArraysSpec.cpp file.
 
 */

#include "E03_Arrays.h"




/*
 OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
 Input is array of structures of type student (each student has name and score).
 E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
 return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]
 
 INPUTS: array of structures of type student, length of the array, integer K.
 
 OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.
 
 NOTES:
 Problem Code :TK
 */


struct student ** topKStudents(struct student *students, int size, int K) {
	struct student **stu=(student**)malloc(sizeof(student*)*K);
	struct student *stu1;
	
	int p = 0;
	int *fmax =(int *)malloc(sizeof(int)*1000);
	int l = 0;
	while (p < K){
		stu1 = students;
		int max = 0,c=0;
		for (int i = 0; i < size; i++){
			int h = 0;
			for (int j = 0; j < l; j++){
				if ((stu1->score) == fmax[j]){
					h = 1;
					break;
				}
			}
			if (((stu1->score)>max)&&(h==0)){
				max = stu1->score;
				c = i;
			}
			stu1++;
		}
		fmax[l] = max;
		l++;
		stu1 = students;
		for (int i = 0; i <=c; i++){
			if (i==c){
				stu[p] = (student *)malloc(sizeof(student));
				stu[p]->name = stu1->name;
				stu[p]->score = stu1->score;
				p++;
				break;
			}
			stu1++;
		}
	}
    return stu;
}



/*
 OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
 -- find the count of numbers greater than a given number in a sorted array.
 E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
 date = "19-10-2004"
 Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })
 
 INPUTS: One bank statement (array of transactions) and date.
 
 OUTPUT: Return the number of transactions in that statement after a given date.

 NOTES:
 Problem Code: CGT
 
 */
int convertdate(char *date){
	int d1=0, w1=0, y1=0;
	int c = 0;
	for (int i = 0; date[i] != '\0'; i++){
		if (c < 2){
			d1 = (d1)*  10 + date[i] - '0';
			c++;
		}
		else if (c == 2){
			c++;
		}
		else if (c < 5){
			w1 = (w1) * 10 + date[i] - '0';
			c++;
		}
		else if (c == 5){
			c++;
		}
		else{
			y1 = (y1) * 10 + date[i] - '0';
			c++;
		}

	}
	int sum = d1 + w1*10+ y1*100;
	return sum;
}
int countGreaterTransactions(struct transaction *transactions, int len, char *date) {

	int c = 0;
	int k = 0;
	k=convertdate(date);
	for (int i = 0; i < len; i++){
		int l=convertdate(transactions->date);
		if (l > k){
			c++;
		}
		
		transactions++;
	}
    return c;
}



/*
 OVERVIEW: You are given 2 bank statements that are ordered by date -
 Write a function that produces a single merged statement ordered by dates.
 E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
 B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
 Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }
 
 INPUTS: Two bank statements (array of transactions).
 
 OUTPUT: Combined statement ordered by transaction date.
 
 NOTES:
 */

struct transaction *mergeSortedTransactions(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *result = (transaction *)malloc(sizeof(transaction)*(ALen+BLen));
	int i, j,k=0;
	struct transaction *A1 = (transaction *)malloc(sizeof(transaction)*(ALen));
	struct transaction *B1 = (transaction *)malloc(sizeof(transaction)*(BLen));
	A1 = A;
	B1 = B;
	for ( i = 0, j = 0; (i < ALen) && (j < BLen);){
		int da = convertdate(A1->date);
		int db = convertdate(B1->date);
		if (da < db){
			result[k] = A[i];
			A1++;
			k++;
			i++;
		}
		else if (db < da){
			result[k] = B[j];
			B1++;
			k++;
			j++;
		}
		else if(db==da){
			result[k] = A[i];
			k++;
			result[k] = B[j];
			k++;
			A1++;
			B1++;
			i++;
			j++;
		}
	}
	if (j < BLen){
		while (j < BLen){
			result[k] = B[j];
			k++;
			j++;
		}
	}
	if (i < ALen){
		while (i < ALen){
			result[k] = A[i];
			k++;
			i++;
		}
	}
	return result;
}


/*
 OVERVIEW: You are given 2 bank statements that are ordered by date.
 Write a function that returns dates common to both statements
 (ie both statements have transactions in these dates).
 E.g.: Input:
 A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
 B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
 Output: { { 10, "09-10-2003", "First" } }
 
 INPUTS: Two bank statements (array of transactions).
 
 OUTPUT: Transactions having same dates.
 
 
 ERROR CASES: Return NULL for invalid inputs.
 
 NOTES:
 */

struct transaction *sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *result = (transaction *)malloc(sizeof(transaction)*(ALen + BLen));
	int i, j, k = 0;

	struct transaction *A1 = (transaction *)malloc(sizeof(transaction)*(ALen));
	struct transaction *B1 = (transaction *)malloc(sizeof(transaction)*(BLen));
	A1 = A;
	B1 = B;
	for (i = 0, j = 0; (i < ALen) && (j < BLen);){
		int da = convertdate(A1->date);
		int db = convertdate(B1->date);
		if (da < db){

			A1++;
		
			i++;
		}
		else if (db < da){

			B1++;
			
			j++;
		}
		else if (db == da){
			result[k] = B[j];
			k++;
			A1++;
			B1++;
			i++;
			j++;
		}
	}
	if (k == 0){
		result = NULL;
	}
	return result;
}
