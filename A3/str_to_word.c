#include <stdio.h>

#define MAX_CHAR_INPUT 101
#define MAX_WORDS 100

int str_to_word(char str[MAX_CHAR_INPUT], char *words[]) {
	int wordCount = 1;

	words[0] = &str[0];

	for(int i = 0; i < MAX_CHAR_INPUT; i++) {
		if (str[i] == ' ') {
			str[i] = '\0';
			words[wordCount] = &str[i+1];
			wordCount++;
		} else if (str[i] == '\0') {
			break;
		}
	}

	return wordCount;
}

int main(void) {
	char inputString[MAX_CHAR_INPUT];
	char *words[MAX_WORDS] = {};
	int wordCount = 0;
	printf("Enter a string (%d char max): ", MAX_CHAR_INPUT-1);
	fgets(inputString, MAX_CHAR_INPUT, stdin);

	wordCount = str_to_word(inputString, words);
	printf("%d word(s) found.\n", wordCount);

	return 0;
} 