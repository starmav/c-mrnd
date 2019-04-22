//
//  E04_Problems.cpp
//  Unit03_Exercise04_Understanding_Optimization
//

/*
 
 Note:
 Implement the functions in this exercise file to make the tests
 pass in E04_ProblemsSpec.cpp file.
 
 */

#include "E04_Problems.h"


/*
 Problem Code :NWAR
 
 There is a war going among numbers ,on who should be considered as a Leader and finally they have reached a conclusion .
 For those numbers when breaked into digits and Individual squares are added ,and if the sum is not 1 ,the process is repeated for the sum and so on.
 When doing this if any any time ,Sum reaches 1 , that number can be called as Leader Number , other wise not .
 
 Ex: 1000 => (1^2 + 0^2 + 0^2 + 0^2) ==> 1 .1000 is a leader number
 Ex: 44 => (16+16) => 32 => (9+4) ==> 13 => (1+9) ==> 10 ==> (1+0) ==> 1. 44 is a leader number .
 Ex: 67 => (36+49) ==> 85 => By Doing Dividing and Squaring and Summing we get this series
 89 => 145 => 42 => 20 => 4 => 16 => 37 => 58 => 89 , As 89 is already generated No matter how many times we do this process We can never reach 1 .So its not a leader Element .
 
 Given an Array of Numbers ,You need to return the array of Leader Elements .You should also copy the Number of Leader Elements Found in *leadersArraLen variable .
 Order should be maintained in the Result Array .
 
 Ex Input : [
 
 Constraints :
 0<= A[i]< 1000000
 0<len<10000
 
 Note : Returns Array Length will not be greater than 10001 . And If the leader number occured 2 or more times in the original array include those many times in answer
 */

int *getSquareLeaders(int *numbers, int len, int *leadersCount) {
	int *res = (int *)malloc(sizeof(int) * 100000);
	//int res[100];
	int m = 0,k=0;
	for (int i = 0; i < len; i++){
		int sum = numbers[i],fix=0,c=0;
	Hello:
		k = sum;
		sum = 0;
		if (k == numbers[i]){
			c = 1;
			while (k > 0){
				sum = sum + (k % 10)*(k % 10);
				k = k / 10;
			}
			fix = sum;
		}
		else{
			c = 0;
			while (k > 0){
				sum = sum + (k % 10)*(k % 10);
				k = k / 10;
			}
		}
	if (sum == 1){
		res[m] = numbers[i];
		m++;
		
	}
	else{
		if (((sum != fix)&&(c==0)&&(sum>9))||((c==1)&&(numbers[i]!=0))){
			goto Hello;
		}
	}
	}
	*leadersCount = m;
    return res;
	//return NULL;
}




/*
 
 You have N steps to climb .
 You can either take one step or two steps at a time .
 You need to find the total number of ways you can reach N steps .
 
 Example : For N=4 , You can either reach 4 steps in following ways
 ->1111
 ->112
 ->121
 ->211
 ->22
 So total number of ways is 5
 
 Input : A Integer denoting N (number of steps )
 Output : Return an Integer denoting the number of ways to reach N steps
 
 Example Input : get_steps(5)
 Example Output : Returns 8
 
 Note : Test Cases would be small < 25.
 
 */


int getSteps(int s) {
	int a = 1;
	int b = 2;
	int c = 0;
	if (s == 1){
		return 1;
	}
	else if (s == 2){
		return 2;
	}
	else{
		for (int i = 2; i < s; i++){
			c = a + b;
			a = b;
			b = c;
		}
	}
    return c;
}
