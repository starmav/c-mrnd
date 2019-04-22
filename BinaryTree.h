//
//  BinaryTree.h


#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdlib.h>

struct treeNode {
    int data;
    struct treeNode *left;
    struct treeNode *right;
};

typedef struct treeNode TreeNode;

struct CityNode{
	char city[20];
	struct CityNode * nextCity;
};

#endif /* BinaryTree_h */
