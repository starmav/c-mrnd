/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * numberToLinkedList(int N) {
	struct node *result = (struct node*)malloc(sizeof(struct node));
	struct node *head = (struct node*)malloc(sizeof(struct node));
	int v = 0;
	int rev = 0;
	if (N < 0){
		N = N*-1;
	}
	if (N > 10){
		while (N > 0){
			rev = rev * 10 + N % 10;
			N = N / 10;
		}
		while (rev > 10){
			result->num = rev % 10;
			rev = rev / 10;
			result->next = (struct node*)malloc(sizeof(struct node));

			if (v == 0){
				head = result;
				v = 1;
			}
			result = result->next;

		}

		result->num = rev % 10;

		result->next = NULL;
		result = head;
	}
	else{
		result->num = N;
		result->next = NULL;
	}
	return result;
}