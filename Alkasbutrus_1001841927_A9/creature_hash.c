#include "creature_hash.h"

int main (int argc, char **argv) {
	if (argc != 2) {
		printf("USAGE: ./a.out FILEPATH\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "a+");
	if (fp == NULL) {
		printf("Could not open \"%s\"\n", argv[1]);
		return 1;
	}

	Creature *creatures = 0;
	scan_file(fp, &creatures);

	while(1) {
		switch(menu('3')) {
			case 1://Search
				printf("Enter name: \n");
				break;
			case 2://Add Creature
				add_creature();
				break;
			case 3://Exit
				printf("Exiting...\n");
				return 0;
			default:
				printf("DEV ERR: Invalid menu return.\n");
				fclose(fp);
				return(1);
		}
	}
}

Creature* add_creature() {
	Creature *newCreature = 0; 
	//newCreature = calloc(1, sizeof(Creature));
	char buffer[BUF_SIZE];
	
	printf("Enter name: \n");
	fgets(buffer, BUF_SIZE, stdin);
	//(*newCreature)->name = calloc(strlen(buffer) + 1, sizeof(char));
	//strcpy((*newCreature)->name, buffer);

	printf("Enter type: \n");
	fgets(buffer, BUF_SIZE, stdin);
	//(*newCreature)->type = calloc(strlen(buffer) + 1, sizeof(char));
	//strcpy((*newCreature)->type, buffer);

	printf("Enter HP: \n");
	printf("Enter AC: \n");
	printf("Enter SPEED: \n");

	return newCreature;
}

int scan_file(FILE *fp, Creature **list) {
	int creatureCount = 1;
	
	while(1) {
		char buffer[BUF_SIZE] = {0}, *token = 0;

		//*list = realloc(*list, creatureCount);

		fgets(buffer, BUF_SIZE, fp);
		if (buffer[strlen(buffer)-1] == '\n') {
			buffer[strlen(buffer)-1] = 0;
		}

		token = strtok(buffer, ",");//name
		//int nameSize = strlen(buffer) + 1;
		//(*list)[creatureCount-1]->name = calloc(nameSize, sizeof(char));
		//strcpy((*list)[creatureCount-1]->name, token);

		//token = strtok(NULL, ",");//hp
		//(*list)[creatureCount-1]->hp = atoi(token);

		//token = strtok(NULL, ",");//ac
		//(*list)[creatureCount-1]->ac = atoi(token);

		//token = strtok(NULL, ",");//speed
		//(*list)[creatureCount-1]->speed = atoi(token);

		//token = strtok(NULL, ",");//type
		//int typeSize = strlen(buffer) + 1;
		// (*list)[creatureCount-1]->type = calloc(typeSize, sizeof(char));
		// strcpy((*list)[creatureCount-1]->type, token);

		if (feof(fp)) {
			break;
		}

		creatureCount++;
	}


	return creatureCount;
} 

int menu(char optionCount) {
	int selection = -1;

	while(1) {
		char input = 0;

		printf("\n--------------\n");
		printf("1. Search\n");
		printf("2. Add Creature\n");
		printf("3. Exit\n");
		printf(">");

		scanf("%c", &input);
		while(getchar() != '\n');

		if(input >= '1' && input <= optionCount) {
			selection = input - '0';
			break;
		} else {
			printf("\nInvalid Option. Please try again\n");
		}
	}

	return selection;
}