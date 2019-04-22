/*

Bharath is genius reverse engineer, invented a world demanding machine and Kept in a secret building with many doors with each door having a passkey.
A Pass key is made up of some digits. Like a passkey can be 1234, 452 etc.
All doors will have passkeys of same digits, (formed from each other). like if number of doors are 3, 1223,2132,2321 can be passkeys for those doors. 
(Where as 3321 cannot as 3 is repeated 2 times where as in above sequence its repeated only 1 time)

Sam is very excited to see his wonderful creation. So, she went to the building. She knows the final passkey of last door but dont know
what is the exact passkey for each before door. As said before there are many doors with lock in a linear fashion such that
she can cross second door only after crossing first door. she can cross third door only after crossing 2nd door.

Lets say the final pass key she has is 758.
First door pass key is the largest number that can be formed by given final passkey -> 875
Second door pass key is the next largest number that can be formed -> 857
Third door opens for next largest number ->785
Finally fourth door has 758 as passkey and she can enter the room.

Find which Nth door's room contains the machine or How many doors should Sam cross to see the machine?

The final passkey Sam has will be given in the form of Doubly Linked List
eg: 7 <-> 5 <-> 8  o/p: 4

For the above Passkey ,output will be 4, as Sam needs to cross 4 doors which each door having below passkeys.
explanation: (1) 875 (2) 857 (3) 785 (4) 758

Ex 2 : 
If DLL has 9 <-> 1 <-> 4 <-> 6.
For the above Passkey ,output will be 4, as Sam needs to cross 6 doors which each door having below passkeys.
explanation: (1) 9641 (2) 9614 (3) 9461 (4) 9416 (5) 9164 (6) 9146

NOTE:	(1)	DLL can contain maximum of 12 nodes
(2)	All doors will have a Passkey which is formed by the numbers of the original pass key only
(3) From the first door to last, passkey will be in decreasing order.
(4) Duplicates are allowed
(5) "075" is not treated as "75". 0 is also given same importance as others.

You can solve this question in multiple ways. 
Can you solve it without converting to any intermediate forms or using extra space etc? These will be the common followup questions
that can be asked in an interview.

Return -1 for invalid cases.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static int count = 0,c=1;

struct passKeyNode
{
	int num;
	struct passKeyNode *prev;
	struct passKeyNode *next;
};


void combinationUtil(int arr[], int n, int r, int index, int data[], int i, long long int min)
{

	if (index == r)
	{
		int num = 0;
		for (int j = 0; j < r; j++)
			num = num * 10 + data[j];
		if (num > min){
			c++;
		}

		return;
	}

	if (i >= n)
		return;

	data[index] = arr[i];
	combinationUtil(arr, n, r, index + 1, data, i + 1, min);

	combinationUtil(arr, n, r, index, data, i + 1, min);
}
void printCombination(int arr[], int n, int r, long long int min)
{
	int data[12];

	combinationUtil(arr, n, r, 0, data, 0, min);
}

int doorstoCross1(struct passKeyNode *passKeyHead){
	if (passKeyHead == NULL){
		return -1;
	}
	int arr[12], l;
	int i = 0;
	while (passKeyHead != NULL){
		arr[i] = passKeyHead->num;
		i++;
		passKeyHead = passKeyHead->next;
	}
	long long int min = 0;
	for (int j = 0; j < i; j++){
		min = min * 10 + arr[j];
	}
	printCombination(arr, i, i,min);
	return c;
}

int doorstoCross2(struct passKeyNode *passKeyHead)
{
	if (passKeyHead == NULL){
		return -1;
	}
	int arr[12],l;
	int i = 0;
	while (passKeyHead != NULL){
		arr[i] = passKeyHead->num;
		i++;
		passKeyHead = passKeyHead->next;
	}
	l = arr[0];
	long long int min = 0;
	for (int j = 0; j < i; j++){
		min = min * 10 + arr[j];
	}
	int temp, comb[100],t=0,o=1;
	for (int j = 1; j <= i; j++) {
		
			for (int k = 0; k < i-1 ; k++) {
				temp = arr[k];
				arr[k] = arr[k + 1];
				arr[k + 1] = temp;
				long long int num = 0;
				for (int p = 0; p < i; p++){
					num = num * 10 + arr[p];
				}
				if (num > min){
					comb[t] = num;
					o++;
					t++;
				}
			}
		
	}
	return o;
}


void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
int toSwap(int str[], int start, int curr)
{
	for (int i = start; i < curr; i++)
		if (str[i] == str[curr])
			return 0;
	return 1;
}
void permutations(int a[], int index, int n, long long int num)
{
	if (index >= n) {
		long long int resnum = 0;
		for (int i = 0; i<n; i++){
			//printf("%d",a[i]);
			resnum = resnum * 10 + a[i];
		}
		//printf("\n");
		if (resnum >= num)
			count++;
		return;
	}
	for (int i = index; i < n; i++) {
		int check = toSwap(a, index, i);
		if (check) {
			swap((a + index), (a + i));
			permutations(a, index + 1, n, num);
			swap((a + index), (a + i));
		}
	}
}
int doorstoCross(struct passKeyNode *passKeyHead)
{
	count = 0;
	long long int n = 0;
	if (passKeyHead == NULL)
		return -1;
	struct passKeyNode *temp = passKeyHead;
	int a[20], i = 0;
	while (temp != NULL){
		a[i] = temp->num;
		n = n * 10 + a[i];
		i = i + 1;
		temp = temp->next;
	}
	permutations(a, 0, i, n);
	
	return count;
}