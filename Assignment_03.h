//
//  Assignment_03.h
//  Unit1_assignment_03
//

#ifndef Assignment_03_h
#define Assignment_03_h

int numberWithoutRepeatition(int numbers[], int size);

void encodeWithNthPrime(int message[8], int n, int encodedMessage[8]);
void decodeWithNthPrime(int message[8], int n, int decodedMessage[8]);

unsigned int packHeader(int fromMobileId, int toMobileId, int msgId,
                        int msgLen, bool urgent, bool adHoc);
void unpackHeader(unsigned int header, int *pFromMobileId, int *pToMobileId,
                  int *pMsgId, int *pMsgLen, bool *pUrgent, bool *pAdHoc);

#endif /* Assignment_03_h */
