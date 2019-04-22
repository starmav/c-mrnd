/*	Maximum Marks: 15
	Problem code: Parent of Leaf Nodes
*/

// Find the numbers of nodes, which have a leaf node.
#include "BinaryTree.h"

/*
  e.g:
  single node => 0
  3 nodes balanced tree => 1
  10 nodes skewed tree => 1
  3 level complete binary tree => 2

*/

int numberOfLeafNodeParents(struct treeNode *rootNode) {
	if (rootNode == NULL){
		return 0;
	}
	
	int k = numberOfLeafNodeParents(rootNode->left);
	int k1= numberOfLeafNodeParents(rootNode->right);
	if ((rootNode->left == NULL) && (rootNode->right == NULL)){
		return k + k1;
	}
	else if ((rootNode->left != NULL) || (rootNode->right != NULL)){
		if (rootNode->left != NULL){
			rootNode = rootNode->left;
			if ((rootNode->left == NULL) && (rootNode->right == NULL)) {
				return k + k1 + 1;
			} 
		}
		else if (rootNode->right != NULL){
			rootNode = rootNode->right;
			if ((rootNode->left == NULL) && (rootNode->right == NULL)) {
				return k + k1 + 1;
			}
		}
	}
	return k+k1;
}

