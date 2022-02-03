#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MUC 128 	//maximum user count
#define MNL 65		//maximum name length (null terminator is included in count)

int add_user(char userNames[MUC][MNL], int userAges[MUC], int userCount);
void list_users(const char userNames[MUC][MNL], const int userAges[MUC], int userCount);
int get_user(int userCount, int ID);
int find_user(const char userNames[MUC][MNL], const char lookupName[MNL], int userCount);

int main(void) {
	char userNames[MUC][MNL] = {0};
	int option = 0, userAges[MUC] = {0}, userCount = 0;
	
	while (option != 5) {
		while(true) {
			printf("=============================\n");
			printf("|| [1] Add New User        ||\n");
			printf("||-------------------------||\n");
			printf("|| [2] List Existing Users ||\n");
			printf("||-------------------------||\n");
			printf("|| [3] Lookup User ID      ||\n");
			printf("||-------------------------||\n");
			printf("|| [4] Lookup User Name    ||\n");
			printf("||-------------------------||\n");
			printf("|| [5] Exit                ||\n");
			printf("=============================\n");

			printf("Option: ");
			int mainInput = scanf("%d", &option);

			while(getchar() != '\n');

			if (mainInput == 0) {
				printf("\nInvalid Input. Please enter an integer between 1 and 5.\n");
			} else if (option < 1 || option > 5) {
				printf("\nInvalid Option. Please enter an integer between 1 and 5.\n");
			} else {
				break;
			}
		}

		switch(option) {
			case 1://add new user
				if (add_user(userNames, userAges, userCount) == 1) {
					printf("\nFailed adding user. Database at full capacity.\n\n");
				} else {
					printf("\nUser added sucessfully.\n\n");
					userCount++;
				}
				break;
			case 2://list users
				if(userCount != 0) {
					list_users(userNames, userAges, userCount);
				} else {
					printf("\nDatabase is empty. Try adding a new user first.\n\n");
				}
				break;
			case 3://lookup ID
				while(true) {
					int ID = 0, IDScan = 0;

					printf("Enter user ID: ");
					IDScan = scanf("%d", &ID);

					while(getchar() != '\n');

					if (IDScan == 0) {
						printf("\nInvalid ID. IDs are an integer between 1 and 3 digits.\n\n");
					} else {
						int IDLookupResult = get_user(userCount, ID);
						
						if(IDLookupResult == -1) {
							printf("\nNo match was found for user ID '%d'.\n\n", ID);
						} else {
							printf("Match found.\nName: %sAge: %d\n\n", userNames[ID], userAges[ID]);
						}

						break;
					}
				}
				break;
			case 4://lookup Name
				printf("Enter user name: ");
				char lookupName[MNL] = {0};

				fgets(lookupName, MNL, stdin);

				int ID = find_user(userNames, lookupName, userCount);
					
				if(ID == -1) {
					printf("\nNo match was found for the entered user name.'%d'.\n\n", ID);
				} else {
					printf("Match found.\nName: %sID: %d\t\tAge: %d\n\n", userNames[ID], ID, userAges[ID]);
				}
				break;
			case 5: 
				printf("Exiting...\n");
		}
		
	}
	return 0;
} 


int add_user(char userNames[MUC][MNL], int userAges[MUC], int userCount) {
	int status = 1;

	if (userCount <= MUC) {
		printf("Enter user name: ");
		fgets(userNames[userCount], MNL, stdin);

		while(true) {
			printf("Enter age: ");
			int ageScan = scanf("%d", &userAges[userCount]);

			while(getchar() != '\n');
			
			if (ageScan == 0) {
				printf("\nInvalid Input. Please try again.\n\n");
			} else {
				break;
			}
		}

		status = 0;
	}

	return status;
}

void list_users(const char userNames[MUC][MNL], const int userAges[MUC], int userCount) {
	printf("\nID     AGE     NAME\n");
	printf("------------------------\n");
	for (int i = 0; i < userCount; i++) {
		printf("%-7d%-8d%s", i, userAges[i], userNames[i]);
	}
	printf("------------------------\n");
	printf("Total users: %d\n\n", userCount);
}

int get_user(int userCount, int ID) {
	int result = -1;
	if (ID >= 0 && ID < userCount) {
		result = ID;
	}
	return result;
}

int find_user(const char userNames[MUC][MNL], const char lookupName[MNL], int userCount) {
	int result = -1;

	for (int i = 0; i < userCount; i++) {
		if(strcmp(lookupName, userNames[i]) == 0) {
			result = i;
		}
	}

	return result;
}