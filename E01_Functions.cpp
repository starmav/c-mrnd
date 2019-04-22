//
//  E01_Functions.cpp
//  Unit02_Exercise01_Understanding_Functions
//

/*

Note:
Implement the functions in this exercise file to make the tests
pass in E01_FunctionsSpec.cpp file.

*/

#include "E01_Functions.h"

int sumOfNodes(TreeNode *root) {
	if (root == NULL){
		return 0;
	}
	int s = sumOfNodes(root->right);
	int s1 = sumOfNodes(root->left);

	return s + s1 + (root->data);
}

int numberOfNodes(TreeNode *root) {
	if (root == NULL){
		return 0;
	}
	int n = numberOfNodes(root->right);
	int n1 = numberOfNodes(root->left);

	return n + n1 + 1;

}

int numberOfLeafNodes(TreeNode *root) {
	if (root == NULL){
		return 0;
	}
	int n = numberOfLeafNodes(root->right);
	int n1 = numberOfLeafNodes(root->left);
	if ((root->right == NULL) && (root->left == NULL)){
		return n + n1 + 1;
	}
	return n + n1;
}




//
// Note: don't change this function code
//
// sort records, based on specific parameters.
//
void sort(struct people *peopleRecords[], int size, IsInOrderPeopleFunc isInOrder) {
	// implement simple sorting method
	int positionToReplace;
	for (int i = 0; i < size - 1; i++) {
		positionToReplace = i;
		for (int j = i + 1; j < size; j++) {
			if (!isInOrder(peopleRecords[positionToReplace], peopleRecords[j])) {
				positionToReplace = j;
			}
		}
		// swap the records in position: i & positionToReplace
		struct people *temp = peopleRecords[i];
		peopleRecords[i] = peopleRecords[positionToReplace];
		peopleRecords[positionToReplace] = temp;
	}
}

//
// write this method to make the sorting by age non-ascending order work
//
// Returns
// 1 - yes non-ascending order
// 0 - otherwise
int isNonAscendingByAge(struct people *record1, struct people *record2) {
	// write your code here
	if ((record1->age) < (record2->age)){
		return 0;
	}

	return 1;
}

// Note: don't change this function code
// sort records based on age non-ascending order
void sortByAgeNonAscending(struct people *peopleRecords[], int size) {
	// create isNonAscendingByAge function and call sort method
	sort(peopleRecords, size, isNonAscendingByAge);
}


//
// write this method to make the sorting by name non-decending order work
//
// Returns
// 1 - yes non-decending order
// 0 - otherwise
int isNonDecendingByName(struct people *record1, struct people *record2) {
	// write your code here
	for (int i = 0; (record1->name[i] != '\0') && (record2->name[i] != '\0'); i++){
		if (record1->name[i] > record2->name[i]){
			return 0;
		}
		else if (record1->name[i] < record2->name[i]){
			break;
		}
	}


	return 1;

}

// Note: don't change this function code
// sort records based on name non-decending order
void sortByNameNonDecending(struct people *peopleRecords[], int size) {
	// create isNonDecendingByName function and call sort method
	sort(peopleRecords, size, isNonDecendingByName);
}

//
// The 'format' will contain only %c and %d, format specifiers
// rest are just characters
//

// Returns
//   number of characters in the output string
//   when printed with format and the two arguments
//
// e.g:
// ("Hai %c 00%d", 'b', 7) => 9
//  since "Hai b 007" contains 9 characters
int outputStringLength(char *format, char ch, int n) {
	int count = 0;
	for (int i = 0; format[i] != '\0'; i++){
		if ((format[i] != '%') && ((format[i + 1] != 'c') || (format[i + 1] != 'd'))){
			count++;
		}
		else{
			i++;
		}
	}
	count++;
	while (n > 0){
		count++;
		n = n / 10;
	}
	return count;
}
