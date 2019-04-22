//
// Every number repeats twice, except one number.
// Write a function that finds the number that does not repeat.
//
// e.g:
// {11, 8, 11}, 3  => 8
//
int numberWithoutRepeatition(int numbers[], int size) {
	int c = 0;
	for (int i = 0; i < size; i++){
		for (int j = 0; j < size; j++){
			if (numbers[i] == numbers[j]){
				c++;
			}
		}
		if (c == 1){
			c = numbers[i];
			break;
		}
		c = 0;
	}
    return c;
}

//
// encode an array of numbers by doing
// XOR with n'th prime number
// and subtract 1
//
// output the encode numbers in encodedMessage[8] array.
//
// e.g:
// for 5'th prime
// encoding will be
// (message[i] ^ 11) - 1
// since 11 is the 5'th prime. // 2, 3, 5, 7, 11...
//

int prime(int n){
	int m = 10000000;
	int p = 0;
	int k = 0;
	for (int i = 1; i < m; i++){
		int c = 0;
		for (int j = 1; j <= i; j++){
			if (i%j == 0){
				c++;
			}
		}
		if (c == 2){
			p = i;
			k++;
		}
		if (k == n){
			break;
		}
	}
	return p;
}


void encodeWithNthPrime(int message[8], int n, int encodedMessage[8]) {
	int i=0;
	int p = prime(n);
	for (i = 0; i < 8; i++){
		encodedMessage[i] = (message[i] ^ p) - 1;
	}
}

//
// decode an array of numbers in
// which are encoded using above encodeWithPrime function.
//
// output the decoded numbers in decodedMessage[8] array.
//
void decodeWithNthPrime(int message[8], int n, int decodedMessage[8]) {
	int i = 0, j, k;
	int p = prime(n);
	for (i = 0; i < 8; i++){
		decodedMessage[i] = (message[i] +1)^p;
	}
}

//
// Encode data and flags in packet header
//
// From Left to Right the data and flags are packed as follows:
// fromMobileId   - 7 bits
// toMobileId     - 7 bits
// msgId          - 7 bits
// msgLen         - 7 bits
// reserved       - 2 bits
// urgent         - 1 flag bit
// adHoc          - 1 flag bit
//
// Note:
// The values will be in the range
// 0 <= fromMobileId, toMobileId, msgId, msgLen <= 127
//
// The reserved bits should be set to zero.
//
// For the context refer:
// https://en.wikipedia.org/wiki/Transmission_Control_Protocol#TCP_segment_structure
//
void toBin(int n, int arr[]){
	for (int k = 0; k<7; k++){
		arr[k] = 0;
	}
	int i = 0;
	while (n > 0) {


		arr[i] = n % 2;
		n = n / 2;
		i++;
	}


	int k = 0;

	k = 0;
	for (int j = 6; j >= k; j--){
		int l = arr[k];
		arr[k] = arr[j];
		arr[j] = l;
		k++;
	}

}
unsigned int fromBin(int n[])
{

	unsigned int dec_value = 0;

	// Initializing base value to 1, i.e 2^0 
	int base = 1;

	int i = 31;
	while (i >= 0)
	{

		dec_value += n[i] * base;

		base = base * 2;
		i--;
	}
	
	return dec_value;
}
unsigned int packHeader(int fromMobileId, int toMobileId, int msgId, int msgLen, bool urgent, bool adHoc) {

	int binaryNum[1000];
	int arr[7];

	// counter for binary array 
	int i = 0;
	unsigned int n;
	 toBin(fromMobileId, arr);
	for (int k = 0; k<7; k++){
		binaryNum[k] = arr[k];
		i++;
	}

	for (int k = 0; k<7; k++){
		arr[k] = 0;
	}
	 toBin(toMobileId, arr);
	for (int k = 0; k<7; k++){
		binaryNum[i] = arr[k];
		i++;
	}

	for (int k = 0; k<7; k++){
		arr[k] = 0;
	}
	 toBin(msgId, arr);
	for (int k = 0; k<7; k++){
		binaryNum[i] = arr[k];
		i++;
	}

	for (int k = 0; k<7; k++){
		arr[k] = 0;
	}
	 toBin(msgLen, arr);
	for (int k = 0; k<7; k++){
		binaryNum[i] = arr[k];
		i++;
	}
	binaryNum[i] = 0;
	i++;
	binaryNum[i] = 0;
	i++;
	binaryNum[i] = urgent;
	i++;
	binaryNum[i] = adHoc;
	i++;
	n = fromBin(binaryNum);
	return n;
}

// unpack a given header, with the properties like the above

int fromBin1(int n[])
{

	int dec_value = 0;

	// Initializing base value to 1, i.e 2^0 
	int base = 1;

	int i = 6;
	while (i >= 0)
	{

		dec_value += n[i] * base;

		base = base * 2;
		i--;
	}

	return dec_value;
}
void toBin1(unsigned int n, int arr[]){
	for (int k = 0; k<32; k++){
		arr[k] = 0;
	}
	int i = 0;
	while (n > 0) {


		arr[i] = n % 2;
		n = n / 2;
		i++;
	}


	int k = 0;

	k = 0;
	for (int j = 31; j >= k; j--){
		int l = arr[k];
		arr[k] = arr[j];
		arr[j] = l;
		k++;
	}

}
 void unpackHeader(unsigned int header, int *pFromMobileId, int *pToMobileId,
	int *pMsgId, int *pMsgLen, bool *pUrgent, bool *pAdHoc) {
	int bin[32];
	toBin1(header, bin);
	int arr[7];
	int i = 0;
	int k = 0;

	for (int k = 0; k<7; k++){
		arr[k] = 0;
	}
	for (i = 0; i < 7; i++){
		arr[i] = bin[k];
		k++;
	}

	*pFromMobileId = fromBin1(arr);
	
	for (int k = 0; k<7; k++){
		arr[k] = 0;
	}
	for (i = 0; i < 7; i++){
		arr[i] = bin[k];
		k++;
	}
	*pToMobileId = fromBin1(arr);
	
	for (int k = 0; k<7; k++){
		arr[k] = 0;
	}
	for (i = 0; i < 7; i++){
		arr[i] = bin[k];
		k++;
	}
	*pMsgId = fromBin1(arr);
	
	for (int k = 0; k<7; k++){
		arr[k] = 0;
	}
	for (i = 0; i < 7; i++){
		arr[i] = bin[k];
		k++;
	}
	*pMsgLen = fromBin1(arr);
	
	k++;
	k++;
	*pUrgent = bin[k];
	k++;
	*pAdHoc = bin[k];
	
	k++;

}

