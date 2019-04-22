//
//  E03_Arrays.h
//  Unit02_ExercisE03_Understanding_Arrays
//

#ifndef E03_Arrays_h
#define E03_Arrays_h

#include <stdio.h>
#include <stdlib.h>

struct student {
    char *name;
    int score;
};

struct student ** topKStudents(struct student *students, int size, int K);


struct transaction {
    int amount;
    char date[11];
    char description[20];
};

int countGreaterTransactions(struct transaction *transactions, int len, char *date);
struct transaction *mergeSortedTransactions(struct transaction *A, int ALen, struct transaction *B, int BLen);
struct transaction *sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen);

#endif /* E03_Arrays_h */

