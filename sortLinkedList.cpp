/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * sortLinkedList(struct node *head) {
	struct node *result = (struct node *)malloc(sizeof(struct node));
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	struct node *temp1 = (struct node *)malloc(sizeof(struct node));
	struct node *prev = (struct node *)malloc(sizeof(struct node));
	struct node *prev1 = (struct node *)malloc(sizeof(struct node));
	result = head;
	temp = head;
	temp1 = head;
	prev = head;
	prev1 = head;
	while (temp != NULL){
		result = temp->next;
		while (result != NULL){
			if ((temp->num) > (result->num)){
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
	head = temp1;
	return head;
}