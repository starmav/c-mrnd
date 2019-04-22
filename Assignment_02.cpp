
//
// Compute factorial of a given positive integer
// 0 <= n <= 100
//
// return value         - number of digits in n!
// factorialDigits[158] - digits of n!
//
void productOfNumbers(int num1[], int num2) {
	int c = 0;
	for (int i = 158; i >= 0; i--){
		int k = (num1[i] * num2) + c;
		num1[i] = k % 10;
		c = k / 10;
	}

}

int factorialOfN(int n, int factorialDigits[158]) {
	
	factorialDigits[158] = 1;
	for (int i = 0; i <158; i++){
		factorialDigits[i] = 0;
	}
	if (n == 0){
		factorialDigits[158] = 0;
		factorialDigits[0] = 1;
		return 1;
	}
	for (int i = 1; i <= n; i++){
		productOfNumbers(factorialDigits, i);
	}
	int c = 0;
	int i = 0;
	while (factorialDigits[i] == 0){
		i++;
	}
	c = 159 - i;
	for (int j = 0; j <c; j++){
		int k = factorialDigits[i];
		factorialDigits[j] = k;
		factorialDigits[i] = 0;
		i++;
	}
	return c;
}


//
// recamán’s sequence: "subtract if you can, otherwise add"
//
// a(0) = 0; for n > 0, a(n) = a(n-1) - n if positive and
// not already in the sequence, otherwise a(n) = a(n-1) + n.
//
// http://oeis.org/A005132
//
// Write a function to find the first n numbers in this sequence
// n >= 0
//
// e.g:
// 0 => {0}
// 2 => {0, 1, 3}
// 5 => {0, 1, 3, 6, 2, 7}
//
// Note:
// The sequence will contain (n + 1) terms.
//
void recamanSequence(int n, int sequence[]) {
	sequence[0] = 0;
	int i;
	for (i = 1; i <= n; i++){
		int x = sequence[i - 1] - i;
		for (int j = 0; j < i; j++){
			if (x == sequence[j] || x < 0){
				x = sequence[i - 1] + i;
				break;
			}
		}
		sequence[i] = x;
	}
}
