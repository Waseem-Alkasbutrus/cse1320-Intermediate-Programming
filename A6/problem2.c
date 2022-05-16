#include "problem2.h"

int main (int argc, char **argv) {
	if (argc != 2) {
		printf("Usage: ./a.out FILE\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("Could not open \"%s\"\n", argv[1]);
		return 1;
	}

	char *filterType = 0, buffer[BUF_SIZE] = {0};

	printf("Enter Type: ");
	fgets(buffer, BUF_SIZE, stdin);
	filterType = alloc_str(buffer);

	Creature *allCreatures = scan_creatures(fp), *filteredCreatures = filter_creatures(filterType, allCreatures);

	if (filteredCreatures != NULL) {
		printf("\n%-20s%-7s%-7s%s\n", "NAME", "HP", "AC", "SPEED");
		print_creatures(filteredCreatures);
	} else {
		printf("No Creatures found.\n");
	}

	release_creatures(allCreatures);
	fclose(fp);
	return 0;
}

void remove_newline(char *str) {
	if (str[strlen(str) -1] == '\n') {
		str[strlen(str) -1] = 0;
	}
}

char* alloc_str(char *str) {
	remove_newline(str);
	int strLen = strlen(str);

	char *newStr = calloc(strLen + 1, sizeof(char));
	strcpy(newStr, str);

	return newStr;
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

void print_creatures(Creature *creature_list) {
	if (creature_list != NULL) {
		printf("%-20s%-7d%-7d%-7d\n", creature_list->name, creature_list->hp, creature_list->ac, creature_list->speed);
		print_creatures(creature_list->next);		
	}
}

Creature* add_Creature(Creature c) {
	Creature *newCreature = calloc(1, sizeof(Creature));

	newCreature->hp = c.hp;
	newCreature->ac = c.ac;
	newCreature->speed = c.speed;
	newCreature->name = alloc_str(c.name);
	newCreature->type = alloc_str(c.type);

	return newCreature;
}

Creature* insert_creature(Creature *creature_list, Creature c) {
	Creature *head = creature_list, *prev = NULL, *current = creature_list, *newCreature = add_Creature(c);

	while(current != NULL) {
		prev = current;
		current = current->next;
	}

	if (head == NULL) {
		head = newCreature;
		newCreature->next = current;
	} else {
		prev->next = newCreature;
		newCreature->next = current;
	}

	return head;
}

Creature* scan_creatures(FILE *fp) {

	Creature *creature_list = 0, temp = {0};
	int creatureCount = count_creatures(fp);
	fseek(fp, 0, SEEK_SET);

	for(int i = 0; i < creatureCount; i++) {
		char buffer[BUF_SIZE] = {0};
		fgets(buffer, BUF_SIZE, fp);

		remove_newline(buffer);

		char *token = strtok(buffer, ",");
		temp.name = alloc_str(token);

		token = strtok(NULL, ",");
		temp.hp = atoi(token);

		token = strtok(NULL, ",");
		temp.ac = atoi(token);

		token = strtok(NULL, ",");
		temp.speed = atoi(token);

		token = strtok(NULL, ",");
		temp.type = alloc_str(token);


		creature_list = insert_creature(creature_list, temp);
	}

	return creature_list;
}

Creature* filter_creatures(char *type, Creature *creatureList){
	Creature *filteredCreatureList = 0;

	while(creatureList != NULL) {
		if (!strcmp(type, creatureList->type)) {
			filteredCreatureList = insert_creature(filteredCreatureList, *creatureList);
		}

		creatureList = creatureList->next;
	}

	return filteredCreatureList;
}

void release_creatures(Creature *creature_list) {
	if (creature_list != NULL) {
		Creature *temp = creature_list->next;
		free(creature_list->type);
		free(creature_list->name);
		free(creature_list);

		release_creatures(temp);
	}
}
