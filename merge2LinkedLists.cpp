/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL){
		if (head2 == NULL){
			return NULL;
		}
		else{
			return head2;
		}
	}
	else if(head2==NULL){
		return head1;
	}
	struct node *prev1, *prev2, *temp1;
	temp1 = head1;
	prev1 = head1;
	prev2 = head2;
	if ((head1->num) < (head2->num)){
		while ((head1 != NULL) && (head2 != NULL)){
			if ((head1->num) < (head2->num)){
				prev1 = head1;
				head1 = head1->next;
			}
			else {
				if (prev1 == head1){
					prev2 = head2;
					head2 = head2->next;
					head1 = head1->next;
					prev1->next = prev2;
					prev2->next = head1;

				}
				else{
					prev2 = head2;
					head2 = head2->next;
					prev1->next = prev2;
					prev2->next = head1;
				}
				prev1 = prev2;
				prev2 = head2;

			}
		}

		if (head2 != NULL){
			prev1->next = head2;

		}
	}
	else{
		temp1 = head2;
		while ((head1 != NULL) && (head2 != NULL)){
			if ((head2->num) < (head1->num)){
				prev2 = head2;
				head2 = head2->next;
			}
			else {
				if (prev2 == head2){
					prev1 = head1;
					head1 = head1->next;
					head2 = head2->next;
					prev2->next = prev1;
					prev1->next = head2;

				}
				else{
					prev1 = head1;
					head1 = head1->next;
					prev2->next = prev1;
					prev1->next = head2;
				}
				prev2 = prev1;
				prev1 = head1;

			}
		}

		if (head1 != NULL){
			prev2->next = head1;

		}
	}
	return temp1;
}
