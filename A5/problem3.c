#include "problem3.h"

int main (int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: ./a.out FILE\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Could not open file\n");
		return 1;
	}

	char buffer[BUF_SIZE]= {0};
	chirp *chirpArr = 0;
	int chirpCount = 0;

	chirpArr = calloc(1, sizeof(chirp));

	while(1) {
		fgets(buffer, BUF_SIZE, fp);
		

		char *token = strtok(buffer, ",");
		strcpy(chirpArr[chirpCount].userId, token);

		token = strtok(NULL, ",");
		chirpArr[chirpCount].message = calloc(strlen(token), sizeof(char));
		strcpy(chirpArr[chirpCount].message, token);

		token = strtok(NULL, ",");
		remove_newline(token);

		strcpy(chirpArr[chirpCount].date, token);


		chirpCount++;
		chirpArr = realloc(chirpArr, (chirpCount + 1) * sizeof(chirp));
		
		printf(" ");
		//WEIRD BUG: if line 55 is not included in the loop, I get
		//corrupted size vs. prev_size
		//Aborted (core dumped)
		
		if(feof(fp)) {
			break;
		}

	}


	for (int i = 0; i < chirpCount; i++) {
		printf("On %s %s Chirped, %s\n", chirpArr[i].date, chirpArr[i].userId, chirpArr[i].message);
	}


	for (int i = 0; i < chirpCount; i++) {
		free(chirpArr[i].message);
	}
	free(chirpArr);	
	fclose (fp);
	return 0;
}

void remove_newline(char *str) {
	if (str[strlen(str) - 1] == '\n') {
		str[strlen(str) - 1] = 0;
	}
}