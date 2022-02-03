#include <stdio.h>

#define ARRAYSIZE 8

void sortArray(float sortedArray[ARRAYSIZE]);
float min(float numberArray[ARRAYSIZE]);
float max(float numberArray[ARRAYSIZE]);
float mean(const float numberArray[ARRAYSIZE]);
float median(const float numberArray[ARRAYSIZE]);

int main(void) {
	float unsortedArray[ARRAYSIZE] = {0}, sortedArray[ARRAYSIZE] = {0};

	printf("Enter %d space-seperated numbers (n n2 n3...): ", ARRAYSIZE);
	for (int i = 0; i < ARRAYSIZE; i++) {
		//to do: add a check for input and only allow numbers
		scanf("%f", &unsortedArray[i]);
		sortedArray[i] = unsortedArray[i];
	}
	while(getchar() != '\n');

	sortArray(sortedArray);

	printf("%0.2f, %0.2f, %0.2f, %0.2f\n", min(sortedArray), max(sortedArray), mean(sortedArray), median(sortedArray));

	printf("Unsorted Array= {");
	for(int i = 0; i < ARRAYSIZE-1; i++) {
		printf("%0.0f, ", unsortedArray[i]);
	}
	printf("%0.0f}\n", unsortedArray[ARRAYSIZE-1]);



	printf("Sorted Array  = {");
	for(int i = 0; i < ARRAYSIZE-1; i++) {
		printf("%0.0f, ", sortedArray[i]);
	}
	printf("%0.0f}\n", sortedArray[ARRAYSIZE-1]);

	return 0;
}

void sortArray(float sortedArray[ARRAYSIZE]) {
	for (int i = 0; i < ARRAYSIZE; i++) {
		for(int j = i+1; j < ARRAYSIZE;j++) {
			if (sortedArray[j] < sortedArray[i]) {
				int temp = sortedArray[j];
				sortedArray[j] = sortedArray[i];
				sortedArray[i] = temp;
			}
		}
	}
}

float min(float numberArray[ARRAYSIZE]) {
	sortArray(numberArray);

	return numberArray[0];
}

float max(float numberArray[ARRAYSIZE]) {
	sortArray(numberArray);

	return numberArray[ARRAYSIZE-1];
}

float mean(const float numberArray[ARRAYSIZE]) {
	float result = 0;

	for (int i = 0; i < ARRAYSIZE; i++) {
		result = result + numberArray[i];
	}

	result = result/ (float) ARRAYSIZE;

	return result;
}

float median(const float numberArray[ARRAYSIZE]) {
	float result = 0;
	int index = ARRAYSIZE/2;

	if(ARRAYSIZE % 2 == 1) {
		result = numberArray[index];
	} else if (ARRAYSIZE % 2 == 0) {
		result = (numberArray[index] + numberArray[index-1])/2;
	}

	return result;
}