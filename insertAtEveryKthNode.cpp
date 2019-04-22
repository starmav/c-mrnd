/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

//Use this function , Dont create any new function with name createNode or createList
struct node * createNodeDummy(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL){
		return NULL;
	}
	else if (K <= 0)
	{
		return NULL;
	}
	struct node *temp;
	struct node *prev;
	
	struct node *temp2;
	temp = head;
	temp2 = head;
	int l = 0;
	while (temp2 != NULL){
		l++;
		temp2 = temp2->next;
	}
	if (l < K){
		return temp;
	}
	if (K == 1){
		while (temp != NULL){
			struct node *temp1 = (struct node *)malloc(sizeof(struct node));
			prev = temp;
			temp = temp->next;
			temp1->num = 1;
			prev->next = temp1;
			temp1->next = temp;
		}

		return head;
	}
	while (head != NULL){
		int i = 0;
		struct node *temp1 = (struct node *)malloc(sizeof(struct node));
		while ((i < K) && (head != NULL)){
			i++;
			prev = head;
			head = head->next;
		}
		if ((i < K) && (head == NULL)){
			break;
		}
		temp1->num = K;
		prev->next = temp1;
		
			temp1->next = head;
	}
	return temp;
}
