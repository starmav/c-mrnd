/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL){
		return -1;
	}
	if (head->next == NULL){
		return head->num;
	}
	struct node *temp,*temp1;
	temp = head;
	temp1 = head;
	int len = 0, c = 0,i=0,result=0;
	while (temp != NULL){
		len++;
		temp = temp->next;
	}
	head = temp1;
	if ((len % 2) == 0){
		c = len / 2;
		while (i < c-1){
			i++;
			head = head->next;
		}
		result = head->num;
		head = head->next;
		result =result+ head->num;
		result=result / 2;
	}
	else{
		c = len / 2;
		while (i < c){
			i++;
			head = head->next;
		}
		result = head->num;
	}
	return result;
}
