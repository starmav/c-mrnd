/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	if (head == NULL){
		return NULL;
	}
	if (K <= 1){
		return NULL;
	}
	int i = 1;
	struct node *result = (struct node *)malloc(sizeof(struct node));
	struct node *prev = (struct node *)malloc(sizeof(struct node));
	result = head;
	prev = head;
	while (head!=NULL){
		while ((i<K)&&(head!=NULL)){
			prev = head;
			head = head->next;
			i++;
		}
		if (head == NULL){
			break;
		}
		prev->next = head->next;
		head = prev->next;
		i = 1;
	}
	return result;
}