#include "problem1.h"

int main() {
	instruction *head = 0;
	while(1) {
		switch(menu('4')) {
			case 1://Add step
				add_step(&head);
				break;
			case 2://Undo step
				pop(&head, 'Y');
				break;
			case 3://Assemble
				print_instructions(head);
				break;
			case 4://Quit
				printf("Exiting...\n");
				while(head != NULL) {
					pop(&head, 'N');
				}
 				return 0;
			default://Invalid
				printf("DEV ERROR: not a valid menu selection.\n");
				exit(1);	
		}
	}
}

void add_step(instruction **head) {
	char buffer[BUF_SIZE] = {0};

	printf("Description: ");
	fgets(buffer, BUF_SIZE, stdin);

	if (buffer[strlen(buffer) - 1] == '\n') {
		buffer[strlen(buffer) - 1] = 0;
	}

	int selection = 0;
	while(1) {
		char input = 0;

		printf("Priority:\n0. Optional\n1. Required\n>");

		scanf("%c", &input);
		while(getchar() != '\n');

		if(input >= '0' && input <= '1') {
			selection = input - '0';
			break;
		} else {
			printf("\nInvalid Option. Please try again\n");
		}
	}

	push(head, buffer, selection);	
}
	
void push(instruction **head, char *desc, priority p) {
	instruction *newInstruction = calloc(1, sizeof(instruction));
	newInstruction->p = p;
	
	newInstruction->desc = malloc((strlen(desc) + 1)*sizeof(char));
	strcpy(newInstruction->desc, desc);

	if (*head == NULL) {//adding first instruction
		*head = newInstruction;
	} else {
		newInstruction->next = *head;
		*head = newInstruction;
	}
}

void pop(instruction **head, char print) {//print dictates whether the removal announcement will be printed or no
	instruction *temp = *head;


	if (*head != NULL) {
		if(print == 'Y') {
			printf("Step \"%s\" removed\n", temp->desc);
		} 

		if (temp->next == NULL) {//only one instruction on the stack
			free(temp->desc);
			free(temp);

			*head = NULL;
		} else {//more than one instruction on the stack
			*head = temp->next;

			free(temp->desc);
			free(temp);
		}
	} else {
		printf("Queue is empty. Cannot undo.\n");
	}
}

void print_instructions(instruction *head) {
	instruction *temp = head;
	int i = 1;
	while (temp != NULL) {
		if (temp->p == REQUIRED) {
			printf("%d) %s\n", i, temp->desc);
		}

		temp = temp->next;
		i++;
	}
}

int menu(char optionCount) {
	int selection = -1;

	while(1) {
		char input = 0;

		printf("\n--------------\n");
		printf("1. Add step\n");
		printf("2. Undo step\n");
		printf("3. Assemble\n");
		printf("4. Quit\n");
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