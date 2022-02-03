#include <stdio.h>
#include <stdbool.h>

void printMenu() {
	printf("|-----------------------|\n");
	printf("|\tGradebook\t|\n");
	printf("|-----------------------|\n");
	printf("| 1. Enter grade\t|\n");
	printf("| 2. View grades\t|\n");
	printf("| 3. Calculate Average\t|\n");
	printf("| 4. Exit\t\t|\n");
	printf("|-----------------------|\n");
	printf("Option: ");
} 

int main(void) {
	float grades[100] = {0}, totalGrade = 0;
	int numberOfAssignments = 0;

	while(true) {
		char menuOption = 0;
		printMenu();
		
		scanf("%c", &menuOption);

		while(getchar() != '\n');


		if (menuOption == '4') {
			printf("Bye!\n");
			break;
		}

		switch(menuOption) {
			case '1': //enter grade
				printf("Enter grade: ");
				scanf("%f", &grades[numberOfAssignments]);

				while(getchar() != '\n');

				totalGrade = totalGrade + grades[numberOfAssignments];
				numberOfAssignments++;
				break;
			case '2': //View Grades
				if (numberOfAssignments == 0) {
					printf("You don't have any grades in the gradebook yet.\n");
					break;
				}

				for(int i = 0; i < numberOfAssignments; i++) {
					printf("%0.2f\t", grades[i]);
				}
				putchar('\n');
				break;
			case '3': //Calculate averages
				if (numberOfAssignments == 0) {
					printf("You don't have any grades in the gradebook yet.\n");
					break;
				}

				printf("Average: %0.2f\n", totalGrade/numberOfAssignments);
				break;
			default: //invalid option
				printf("%c is not a valid option.\n", menuOption);
		}
	}

	return 0;
}