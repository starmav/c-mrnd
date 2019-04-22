/*
	Maximum Marks: 25
	
	Problem code: Biryani Competition
	
	Problem Statement:

	A biryani making competition has been organized as an event in MRND. It's the time when the coders wore the hat of Chef.
	The contestants have to just mix the given ingredients. The time taken to mix the ingredients will be equal to their weights.
	The contestant can mix only two components at a time. The one who prepares the biryani first will be the winner.
	You need to find the time taken by the winner.

	Note: As the competition is fierce, the winner shall be the one who makes biriyani most optimally

	Input Format:

	n - no. of ingredients,
	weights[] - weights of  ingredients

	Constraints:

	2 < n <= 100
	1 <= weights[i] < 1000000

	Output:

	The time taken is returned.

	Sample Input 0:

	4
	1 4 7 10

	Sample Output 0:

	39

	Explanation 0:

	Items of weight 1 and 4 are added(1+4=5). Then one with weight 7 is added(5+7=12).
	Finally the last one with weight 10 is added(12+10=22).
	The total time taken is (5+12+22)39.

	Sample Input 1:

	5
	1 3 7 5 6

	Sample Output 1:
	 
	48 

	Explanation 1:

	The components with weight 1 and 3 are mixed to get a mix of weight 4(mixA).
	Then the mixA and component with weight 5 are added to get a mix of weight 9(mixB).
	Then the components with weights 6 and 7 are mixed to get mix of weight 13(mixC).
	Then mixB and mixC are added to get the final mixture of weight 22.
	The total time=4(mixA)+9(mixB)+13(mixC)+22(final).


*/

// Function that returns the time taken by the Winner in the competition

int time_taken_by_winner(int n, int weights[])
{
    // code goes here
    
    return -1;
}
