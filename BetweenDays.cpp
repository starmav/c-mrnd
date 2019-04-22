/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int between_days(struct node *date1head, struct node *date2head){
	if ((date1head == NULL) || (date2head == NULL)){
		return -1;
	}



	int date1 = 0, month1 = 0, year1 = 0, i = 0, date2 = 0, month2 = 0, year2 = 0;
	while (i < 2){
		date1 = date1 * 10 + date1head->data;
		date2 = date2 * 10 + date2head->data;
		date2head = date2head->next;
		date1head = date1head->next;
		i++;
	}
	i = 0;
	while (i < 2){
		month1 = month1 * 10 + date1head->data;
		month2 = month2 * 10 + date2head->data;
		date2head = date2head->next;
		date1head = date1head->next;
		i++;
	}
	i = 0;
	while ((date1head != NULL)){
		year1 = year1 * 10 + date1head->data;
		year2 = year2 * 10 + date2head->data;
		date2head = date2head->next;
		date1head = date1head->next;
		i++;
	}
	if ((year1 - year2) == 0){
		if ((month1 - month2) == 0){
			if (((date1-date2)==0)||((date1-date2)==1)){
				return 0;
			}
		}
	}
	long int n1=0, n2=0;
	int monthDays[12] = { 31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31 };
	for (int i = 0; i<month1 - 1; i++)
		n1 += monthDays[i];
	for (int i = 0; i<month2 - 1; i++)
		n2 += monthDays[i];
	if (month1 > 2){
		n1 += year1 * 365 + date1 +(( year1 / 4) - (year1 / 100) + (year1 / 400));
	}
	else{
		n1 += (year1-1) * 365 + date1+ (((year1-1) / 4) - ((year1-1) / 100) + ((year1-1) / 400));
		n1 = n1 + 365;
	}
	if (month2 > 2){
		n2+= year2 * 365 + date2 +(( year2 / 4) - (year2 / 100) + (year2 / 400));
	}
	else{
		n2 += (year2-1) * 365 + date2 + (((year2 - 1) / 4) - ((year2 - 1) / 100) + ((year2 - 1) / 400));
		n2 = n2 + 365;
	}
	if (n2 > n1){
		return (n2 - n1) - 1;
	}
	return n1 - n2 - 1;
}