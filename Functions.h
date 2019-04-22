//
//  Functions.h


#ifndef Functions_h
#define Functions_h

int time_taken_by_winner(int n, int weights[]);

struct CityNode * meetingPoint(struct CityNode * deepikaStartCity, struct CityNode *mayaStartCity, int *numberOfCitiesMayaShouldTravel);

int numberOfLeafNodeParents(struct treeNode *rootNode);

int** initialSnakePosition(int len);

char sumOfDigits(char number[], int base);

#endif /* Functions_h */
