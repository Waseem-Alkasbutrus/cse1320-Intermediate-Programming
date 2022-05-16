#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_LENGTH_ 160
#define MAX_LINES_ 1048

void remove_newline(char str[MAX_LENGTH_]) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '\n') {
			str[i] = '\0';
		}
	}
}

int count_occurences(char keyword[MAX_LENGTH_], char words[MAX_LINES_][MAX_LENGTH_], int wordCount) {
	int occurences = 0;

	for (int i = 0; i < wordCount; i++) {
		if(strcmp(words[i], keyword) == 0) {
			occurences++;
		}
	}

	return occurences;
}

int is_trending(char keyword[MAX_LENGTH_], char words[MAX_LINES_][MAX_LENGTH_], int wordCount) {
	int occurences = count_occurences(keyword, words, wordCount);

	if (occurences >= 3) {
		return 1;
	} else {
		return 0;
	}
}

int main(int argc, char *argv[3]) {
	if (argc != 3) {
		printf("Usage: ./a.out FILE.txt KEYWORD\n");
		return 1;
	}

	FILE *fp;
	if (!access(argv[1], F_OK)) {
		fp = fopen(argv[1], "r");
	} else {
		printf("FILE NOT FOUND.\n");
		return 1;
	}

 	char words[MAX_LINES_][MAX_LENGTH_] = {0};
 	int i = 0;

 	while(1) {
 		if(feof(fp)) {
 			break;
 		}

 		fgets(words[i], MAX_LENGTH_, fp);
 		remove_newline(words[i]);
 		i++;
 	}

 	int occurences = count_occurences(argv[2], words, i);

 	if (is_trending(argv[2], words, i)) {
 		printf("\"%s\" is trending with %d messages.\n", argv[2], occurences);
 	} else {
 		printf("\"%s\" is not trending.\n", argv[2]);
 	}

	return 0;
} 
