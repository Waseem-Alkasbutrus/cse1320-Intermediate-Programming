#include <stdio.h>
#include <string.h>

#define STRING_SIZE_ 160

typedef struct {
	char name[160];
	int cr;
	int ac;
	int hp;
} creature;

void clear_newline(char str[STRING_SIZE_]) {
    int len = strlen(str);
    if (str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

void add_creature(FILE *fp, creature *c) {
	char buffer[STRING_SIZE_] = {0};

	printf("Enter Name: ");
	fgets(buffer, STRING_SIZE_, stdin);
	clear_newline(buffer);
	strcpy(c->name, buffer);

	printf("Enter Challenge Rating: ");
	scanf("%d", &c->cr);
	while(getchar() != '\n');

	printf("Enter Armor Class: ");
	scanf("%d", &c->ac);
	while(getchar() != '\n');
	
	printf("Enter Hit Points: ");
	scanf("%d", &c->hp);
	while(getchar() != '\n');

	fwrite(c, sizeof(c), 1, fp);
}

void list_creatures(FILE *fp, creature *c) {
	fseek(fp, 0, SEEK_SET);

	while(fread(c, sizeof(c), 1, fp)) {
		printf("\n%s\n", c->name);
		for(int i = 0; i < strlen(c->name); i++) {
			printf("-");
		}
		printf("\nCR: %d\nAC: %d\nHP: %d\n", c->cr, c->ac, c->hp);
	}
}

int main(int argc, char *argv[2]) {
	if (argc != 2) {
		printf("Usage: ./a.out FILE_NAME\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "a+");
	if (fp == NULL) {
		printf("COULD NOT OPEN FILE.\n");
		return 1;
	}

	int mainOption = 0;
	creature c = {0};
	while(1) {
		while (1) {
			printf("=================\n1. List Creatures\n2. Add Creatures\n3. Exit\n=================\noption: ");
			mainOption = getchar();

			while (getchar() != '\n');

			if (!(mainOption >= '1' && mainOption <= '3')) {
				printf("=================\nInvalid Entry. Try again.\n");
			} else {
				break;
			}
		}

		switch(mainOption) {
			case '1': //list creatures
				list_creatures(fp, &c);
				break;
			case '2': //Add creature
				add_creature(fp, &c);
				break;
			case '3': //Exit
				fclose(fp);
				return 0;
		}

	}
}