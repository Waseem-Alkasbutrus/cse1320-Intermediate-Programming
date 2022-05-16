#include <stdio.h>

/*
	strlen_ counts the number of characters in a string.

	parameters:
		char str[100]: A string of characters. Will be counted.

	retruns:
		int length: The number of characters in str
*/
int strlen_(char str[100]) {
	int length = 0;

	while(str[length] != '\0') {
		length++;
	}

	return length;
}

/*
	strcmp_ compares two strings and returns the result.

	parameters:
		char str1[100]: First string of characters. Will be compared with str2.
		char str2[100]: Second string of characters. Will be compares with str1.

	retruns:
		0 if strings match characters and case.
		1 if strings match characters but not case.
		2 if strings do not match characters.
*/
int strcmp_(char str1[100], char str2[100]) {
	int result = 2;

	if(strlen_(str1) == strlen_(str2)) {
		for (int i = 0; i < strlen_(str1); i++) {
			if(str1[i] == str2[i] && result != 1){
				result = 0;
			} else if(str1[i] == (str2[i]+32) || str1[i] == (str2[i]-32)) {
				result = 1;
			} else if (str1[i] != str2[i]) {
				result = 2;
				break;
			}
		}
	}


	return result;
}

int main(void) {
	char str1[100] = {}, str2[100] = {};


	printf("Enter String 1: ");
	scanf("%s", str1);
	while(getchar() != '\n');

	printf("Enter String 2: ");
	scanf("%s", str2);
	while(getchar() != '\n');

	switch(strcmp_(str1, str2)) {
		case 0: printf("Strings match exactly.\n");
			break;
		case 1: printf("Strings match, but cases do not.\n");
			break;
		case 2: printf("Strings do not match.\n");
			break;
	}

	return 0;
}