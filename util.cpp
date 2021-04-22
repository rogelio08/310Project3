#include "util.h"
#include <iostream>
#include <ctype.h>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


void nextCommandFind(char str[30], int* source, int* destination, int* flag) {

	char upper;
	char c;

	
	char inputSource[] = { str[5], str[6] };
	int src = atoi(inputSource);
	*source = src;

	char inputDestination[] = { str[7], str[8], str[9] };
	if (str[7] == '1') {
		*destination = 100;
	//	char inputFlag[] = { str[10], str[11] };
	//	int fl = atoi(inputFlag);
		if(str[10] == '1' || str[11] == '1'){
			*flag = 1;
		}
		else{
			*flag = 0;
		}
		
	}
	else if (str[7] == '-') {
		*destination = -1;
		char inputFlag[] = { str[10] };
		int f = atoi(inputFlag);
		*flag = f;
	}
	else {
		int dest = atoi(inputDestination);
		*destination = dest;
		char inputFlag[] = { str[9], str[10] };
		int f = atoi(inputFlag);
		*flag = f;
	}
	
	
	
}

void nextCommandWrite(char str[30], int* source, int* destination) {

	char inputSource[] = { str[11], str[12] };
	int src = atoi(inputSource);
	*source = src;

	char inputDestination[] = { str[13], str[14], str[15] };
	int dest = atoi(inputDestination);
	*destination = dest;
}




