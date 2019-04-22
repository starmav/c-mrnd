/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	
	if (head == NULL){
		return NULL;
	}
	if (head->next == NULL){
		return head;
	}
	struct node *temp, *temp2, *prev, *temp3;
	temp = head->next;
	temp2 = head;
	prev = head;
	temp3 = head;
	head->next = NULL;
	while (temp2 != NULL){
		temp3 = temp;
		temp2 = temp->next;
		temp->next = prev;
		prev = temp3;
		temp = temp2;
	}
	return prev;
}
