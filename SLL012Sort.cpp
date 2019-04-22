/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head){
	struct node *result = (struct node*)malloc(sizeof(struct node));
	struct node *result1 = (struct node*)malloc(sizeof(struct node));

	result = *head;
	result1 = (*head)->next;
	while (result1 != NULL){
		if ((result->data) > (result1->data)){
			int num = result1->data;
			result1->data = result->data;
			result->data = num;
		}
		result = result->next;
		result1 = result1->next;
	}
}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head){
	struct node *result = (struct node *)malloc(sizeof(struct node));
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *temp1 = (struct node *)malloc(sizeof(struct node));
	struct node *prev = (struct node *)malloc(sizeof(struct node));
	struct node *prev1 = (struct node *)malloc(sizeof(struct node));
	result = *head;
	temp = *head;
	temp1 = *head;
	prev = *head;
	prev1 = *head;
	while (temp != NULL){
		result = temp->next;
		while (result != NULL){
			if ((temp->data) > (result->data)){
				if ((temp != temp1) && (temp->next != result)){
					prev1->next = result->next;
					prev->next = result;
					result->next = temp;

					prev = temp;
					temp = result;
					result = temp;
				}
				else if ((temp != temp1) && (temp->next == result)){
					temp->next = result->next;
					prev->next = result;
					result->next = temp;

					prev = temp;
					temp = result;
					result = temp;
				}
				else if ((temp == temp1) && (temp->next == result)){
					temp->next = result->next;
					result->next = temp;

					prev = temp;
					temp = result;
					result = temp;

					temp1 = temp;
				}
				else{
					prev1->next = result->next;
					result->next = temp;

					prev = temp;
					temp = result;
					result = temp;

					temp1 = temp;
				}
			}

			prev1 = result;
			result = result->next;

		}
		prev = temp;
		temp = temp->next;
	}
	*head = temp1;
}
void sll_012_sort1(struct node **head){
	struct node *result = (struct node*)malloc(sizeof(struct node));
	struct node *result1 = (struct node*)malloc(sizeof(struct node));
	int v = 0;
	int z = 0, o = 0, t = 0;
	while (*head != NULL){
		if ((*head)->data == 0){
			z++;
		}
		else if ((*head)->data == 1){
			o++;
		}
		else if ((*head)->data == 2){
			t++;
		}
		*head = (*head)->next;
	}
	for (int i = 0; i < z; i++){
		result->data = 0;

		result->next = (struct node*)malloc(sizeof(struct node));

		if (v == 0){
			result1 = result;
			v = 1;
		}
		result = result->next;
	}

	for (int i = 0; i < o; i++){
		result->data = 1;

		result->next = (struct node*)malloc(sizeof(struct node));
		if (v == 0){
			result1 = result;
			v = 1;
		}
		result = result->next;
	}

	for (int i = 0; i < t - 1; i++){
		result->data = 2;

		result->next = (struct node*)malloc(sizeof(struct node));
		if (v == 0){
			result1 = result;
			v = 1;
		}
		result = result->next;
	}
	result->data = 2;
	result->next = NULL;
	*head = result1;
	return;
}

