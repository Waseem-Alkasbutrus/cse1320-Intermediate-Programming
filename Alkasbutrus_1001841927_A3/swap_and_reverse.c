#include <stdio.h>

#define BUFFER 101

int str_length(char str[]);
void clear_newline(char str[BUFFER]);
char* swap_and_reverse(char string[], char key[]);

int main(void) {
	char string[BUFFER], key[BUFFER];

	printf("Enter string : ");
	fgets(string, BUFFER, stdin);
	clear_newline(string);

	printf("Enter key : ");
	fgets(key, BUFFER, stdin);
	clear_newline(key);

	if (swap_and_reverse(string, key) != NULL) {
		printf("%s\n", string);
	} else {
		printf("Key not found!\n");
	}


	return 0;
} 

int str_length(char str[]) {
	int count = 0;

	while(str[count] != '\0') {
			count++;
	}

	return count;	
}

void clear_newline(char str[BUFFER]) {
	int i = 0;
	while(1) {
		if (str[i] == '\0'){ 
			break;
		} else if (str[i] == '\n') {
			str[i] = '\0';
			break;
		}

		i++;
	}
}

char* swap_and_reverse(char str[], char key[]) {
	char *lastchar = NULL;
	int j = 0;


	for(int i = 0; i < str_length(str); i++) {

		if(key[j] == str[i] && key[j+1] == '\0'){ 
			lastchar = &str[i];
			j = i;
			break;
		} else if (key[j] != str[i]) {
			j = 0;
			continue;
		}

		j++;
	}

	if(lastchar != NULL) {
		for (int i = 0; i < str_length(key); i++) {
			str[j-i] = key[i];
		}
	}


	return lastchar;
}