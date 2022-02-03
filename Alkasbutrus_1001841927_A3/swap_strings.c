#include <stdio.h>

void print_ptr_array(char *arr[], int arrSize);
void swap_strings(char *str1[], int str1Size, int index1, char *str2[], int str2Size, int index2);

int main(void) {
	int str1Size = 6, str2Size = 7, index1 = 0, index2 = 0;
	
	char *str1[6] = {"I", "am", "extremly", "unimaginative", "and", "I"};
	char *str2[6] = {"can't", "think", "of", "what", "to" ,"write"};

	printf("String 1: ");
	print_ptr_array(str1, str1Size);

	printf("String 2: ");
	print_ptr_array(str2, str2Size);

	printf("\nEnter index 1: ");
	scanf("%d", &index1);
	while(getchar() != '\n');

	printf("Enter index 2: ");
	scanf("%d", &index2);
	while(getchar() != '\n');

	swap_strings(str1, str1Size, index1, str2, str2Size, index2);

	printf("\nSwapped string 1: ");
	print_ptr_array(str1, str1Size);
	printf("Swapped string 2: ");
	print_ptr_array(str2, str2Size);

	return 0;
} 

void print_ptr_array(char *arr[], int arrSize) {
	for(int i = 0; i < arrSize; i++) {
		printf("%s ", arr[i]);
	}

	putchar('\n');
}

void swap_strings(char *str1[], int str1Size, int index1, char *str2[], int str2Size, int index2) {
	char *temp = str1[index1];
	str1[index1] = str2[index2];
	str2[index2] = temp;
}