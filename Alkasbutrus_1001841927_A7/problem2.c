#include "problem2.h"

int main() {
	quest *head = 0, *tail = 0;

	while(1) {
		int mainMenu = menu('3', 0);

		switch(mainMenu) {
			case 1://Add quest
				add_quest(&head, &tail);
				break;
			case 2://View quests
				printf("\n--------------\n");
				print_quest(tail);
				switch(menu('2', 1)) {
					case 1://mark quest as complete (dequeue quest)
						if (head != NULL) {
							mark_complete(&head, &tail);
						}
						break;
					case 2: //go back to main menu
						break;
					default://invalid selection
						printf("DEV ERROR: '%d' is not a valid menu selection.\n", mainMenu);
						exit(1);		
				}
				break;
			case 3://Exit
				printf("Exiting...\n");
				while (head != NULL) {
					mark_complete(&head, &tail);
				}
				return 0;
				break;
			default://invalid selection
				printf("DEV ERROR: '%d' is not a valid menu selection.\n", mainMenu);
				exit(1);
		}
	}
}

void enqueue(quest **head, quest **tail, char *description) {
	quest *newQuest = calloc(1, sizeof(quest));
	newQuest->questDescription = description;

	if (*head == NULL) {//adding to an empty list
		*head = newQuest;
		*tail = newQuest;
	} else {//adding to an existing list
		newQuest->next = *head;
		(*head)->prev = newQuest;
		*head = newQuest;
	}
}

void add_quest(quest **head, quest **tail) {
	char buffer[BUF_SIZE] = {0};

	printf("Quest description: ");
	fgets(buffer, BUF_SIZE, stdin);

	if (buffer[strlen(buffer) - 1] == '\n') {
		buffer[strlen(buffer) - 1] = 0;
	}

	char *description = malloc((strlen(buffer) + 1) * sizeof(char));
	strcpy(description, buffer);

	enqueue(head, tail, description);
}

void mark_complete(quest **head, quest **tail) {
	if ((*head == *tail) && *head != NULL) {//only one quest
		free((*head)->questDescription);
		free(*head);
		*head = NULL;
		*tail = NULL;
	} else {//more than one quest
		quest *temp = (*tail)->prev;
		temp->next = NULL;

		free((*tail)->questDescription);
		free(*tail);
		*tail = temp;
	}
}

void print_quest(quest *node) {
	if (node != NULL) {
		printf("Quest: %s\n", node->questDescription);
	} else {
		printf("No quests in queue\n");
	}
}

void print_menu(int menuCode) {
	switch(menuCode) {
		case 0://Main menu
			printf("\n--------------\n");
			printf("1. Add Quest\n");
			printf("2. View Quests\n");
			printf("3. Exit\n");
			break;
		case 1://Quest options
			printf("1. Mark as complete\n");
			printf("2. Back to main menu\n");
			break;
		default://Invalid menu
			printf("DEV ERROR: '%d' is not a valid menu code.\n", menuCode);
			exit(1);
	}
}

int menu(char optionCount, int menuCode) {
	int selection = -1;

	while(1) {
		char input = 0;

		if (menu >= 0) {
			print_menu(menuCode);
		}

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