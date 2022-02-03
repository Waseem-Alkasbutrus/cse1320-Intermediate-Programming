#include "problem1.h"

int main (int argc, char **argv) {
	FILE *fp = 0;

	if (argc == 1) {
		fp = fopen("monsters.csv", "a+");
	} else if (argc == 2) {
		fp = fopen(argv[1], "a+");
	} else {
		printf("Usage: ./a.out FILE(optional)\n");
		return 1;
	}

	while(1) {
		int creatureCount = 0;
		creature *creatureArr = 0;

		int mainMenuSelection = menu('4', 1);
		switch(mainMenuSelection) {
			case 1://add
				append_creature(fp);
				printf("Saved to file!\n\n");
				break;
			case 2://view
				creatureCount = count_creatures(fp);

				if (creatureArr == NULL) {
					creatureArr = scan_creatures(fp, creatureCount);
				}

				printf("\n\n//Viewing\n");
				print_creatures(creatureArr, creatureCount);

				for(int i = 0; i < creatureCount; i++) {
					free(creatureArr[i].type);
					free(creatureArr[i].name);
				}
				free(creatureArr);
				
				break;
			case 3://sort
				creatureCount = count_creatures(fp);

				if (creatureArr == NULL) {
					creatureArr = scan_creatures(fp, creatureCount);
				}

				int sortSelection = menu('5', 2);

				switch(sortSelection) {
					case 1://name
						qsort(creatureArr, creatureCount, sizeof(creature), sort_name);
						break;
					case 2://hp
						qsort(creatureArr, creatureCount, sizeof(creature), sort_hp);
						break;
					case 3://ac
						qsort(creatureArr, creatureCount, sizeof(creature), sort_ac);
						break;
					case 4://speed
						qsort(creatureArr, creatureCount, sizeof(creature), sort_speed);
						break;
					case 5://type
						qsort(creatureArr, creatureCount, sizeof(creature), sort_type);
						break;
				}

				printf("\n\n//Sorting\n");
				print_creatures(creatureArr, creatureCount);

				for(int i = 0; i < creatureCount; i++) {
					free(creatureArr[i].type);
					free(creatureArr[i].name);
				}
				free(creatureArr);
				
				break;
			case 4://exit
				fclose(fp);
				return 0;
		}
	}
}

int sort_hp(const void *elem1, const void *elem2) {
	creature *a = (creature *)elem1;
	creature *b = (creature *)elem2;

	return b->hp - a->hp;
}

int sort_ac(const void *elem1, const void *elem2) {
	creature *a = (creature *)elem1;
	creature *b = (creature *)elem2;

	return b->ac - a->ac;
}

int sort_speed(const void *elem1, const void *elem2) {
	creature *a = (creature *)elem1;
	creature *b = (creature *)elem2;

	return b->speed - a->speed;
}

int sort_name(const void *elem1, const void *elem2) {
	creature *a = (creature *)elem1;
	creature *b = (creature *)elem2;

	return strcmp(b->name, a->name);
}

int sort_type(const void *elem1, const void *elem2) {
	creature *a = (creature *)elem1;
	creature *b = (creature *)elem2;

	return strcmp(b->type, a->type);
}

void print_creatures(creature *arr, int creatureCount) {
	printf("%-25s%-10s%-10s%-10s%s\n", "NAME", "HP", "AC", "SPEED", "TYPE");

	for (int i = 0; i < creatureCount; i++) {
		printf("%-25s%-10d%-10d%-10d%s\n", arr[i].name, arr[i].hp, arr[i].ac, arr[i].speed, arr[i].type);
	}
}

void remove_newline(char *str) {
	if (str[strlen(str) -1] == '\n') {
		str[strlen(str) -1] = 0;
	}
}

void append_creature(FILE *fp) {
	char buffer[STATIC_SIZE] = {0};
	creature c = {0};

	printf("NAME: ");
	fgets(buffer, STATIC_SIZE, stdin);
	remove_newline(buffer);
	c.name = calloc(strlen(buffer)+1, sizeof(char));
	strcpy(c.name, buffer);

	printf("HP: ");
	scanf("%d", &c.hp);

	printf("AC: ");
	scanf("%d", &c.ac);

	printf("SPEED: ");
	scanf("%d", &c.speed);

	while(getchar() != '\n');

	printf("TPYE: ");
	fgets(buffer, STATIC_SIZE, stdin);
	remove_newline(buffer);
	c.type = calloc(strlen(buffer)+1, sizeof(char));
	strcpy(c.type, buffer);

	fprintf(fp, "%s,%d,%d,%d,%s\n", c.name, c.hp, c.ac, c.speed, c.type);

	free(c.type);
	free(c.name);
}

int count_creatures(FILE *fp) {
	fseek(fp, 0, SEEK_SET);

	int creatureCount = 0;

	while(1) {
		char temp = getc(fp);

		if (temp == '\n') {
			creatureCount++;
		} 

		if (feof(fp)) {
			return creatureCount;
		}
	}
}

creature* scan_creatures(FILE *fp, int creatureCount) {
	fseek(fp, 0, SEEK_SET);

	creature *arr = 0;

	for (int i = 0; i < creatureCount; i++) {
		if (feof(fp)) {
			break;
		}

		arr = realloc(arr, (size_t)(i + 1) * sizeof(creature));

		char buffer[STATIC_SIZE] = {0}, *token = 0;

		fgets(buffer, STATIC_SIZE, fp);

		token = strtok(buffer, ",");
		arr[i].name = realloc(arr[i].name, (size_t)(strlen(token) + 1)*sizeof(char));
		strcpy(arr[i].name, token);


		token = strtok(NULL, ",");
		arr[i].hp = atoi(token);

		token = strtok(NULL, ",");
		arr[i].ac = atoi(token);

		token = strtok(NULL, ",");
		arr[i].speed = atoi(token);

		token = strtok(NULL, ",");
		
		if (token[strlen(token)-1] == '\n') {
			token[strlen(token)-1] = 0;
		}

		arr[i].type = realloc(arr[i].type, (size_t)(strlen(token) + 1)*sizeof(char));
		strcpy(arr[i].type, token);	
	}

	return arr;
}

void print_menu(int menu) {

		switch (menu) {		
			case 1: 
				printf("---------------------\n");
				printf("|    CREATURE DB    |\n");
				printf("---------------------\n");
				printf("| 1. Add Creature   |\n");
				printf("| 2. View Creatures |\n");
				printf("| 3. Sort Creatures |\n");
				printf("| 4. Exit           |\n");
				printf("---------------------\n");
				break;
			case 2: 
				printf("---------------------\n");
				printf("|      SORT BY      |\n");
				printf("---------------------\n");
				printf("| 1. NAME           |\n");
				printf("| 2. HP             |\n");
				printf("| 3. AC             |\n");
				printf("| 4. SPEED          |\n");
				printf("| 5. TYPE           |\n");
				printf("---------------------\n");
				break;
		}
}

int menu(char optionCount, int menu) {
	int result = -1;


	while(1) {
		char input = 0;

		if (menu >= 0) {
			print_menu(menu);
		}

		printf("Option: ");
		scanf("%c", &input);

		while(getchar() != '\n');

		if(input >= 49 && input <= optionCount) {
			result = input - '0';
			break;
		} else {
			printf("\nInvalid Option. Please try again\n");
		}
	}

	return result;
}
