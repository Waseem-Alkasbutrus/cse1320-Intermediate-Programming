#include <stdio.h>

#define ARRAYSIZE 8

int sort_reverse(int arr[]);
int sort(int arr[]);

int main(void) {
	int array[ARRAYSIZE] = {0}, swaps = 0;

	printf("Enter %d space-seperated numbers (n n2 n3...): ", ARRAYSIZE);
	for (int i = 0; i < ARRAYSIZE; i++) {
		scanf("%d", &array[i]);
	}
	while(getchar() != '\n');

	swaps = sort(array);

	printf("\nAscending = {");
	for(int i = 0; i < ARRAYSIZE-1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d}\n", array[ARRAYSIZE-1]);
	printf("Number of Swaps: %d\n", swaps);

	swaps = sort_reverse(array);

	printf("\nDescending = {");
	for(int i = 0; i < ARRAYSIZE-1; i++) {
		printf("%d, ", array[i]);
	}
	printf("%d}\n", array[ARRAYSIZE-1]);
	printf("Number of Swaps: %d\n", swaps);

	return 0;
}

int sort_reverse(int arr[]) {
	int swaps = 0;
    // sort array
    for (int i = ARRAYSIZE - 1; i >= 0; i--) {
        int max_j = i;
        for (int j = i; j >= 0; j--) {
            if (arr[j] < arr[max_j]) {
                max_j = j;
            }
        }

        // Swap values
        if (max_j != i) {
            int temp = arr[i];
            arr[i] = arr[max_j];
            arr[max_j] = temp;
        	
        	swaps++;
        }
    }

    return swaps;
}

int sort(int arr[]) {
	int swaps = 0;
    // sort array
    for (int i = 0; i < ARRAYSIZE; i++) {
        int min_j = i;
        for (int j = i; j < ARRAYSIZE; j++) {
            if (arr[j] < arr[min_j]) {
                min_j = j;
            }
        }

        // Swap values
        if (min_j != i) {
            int temp = arr[i];
            arr[i] = arr[min_j];
            arr[min_j] = temp;
        	
        	swaps++;
        }
    }

    return swaps;
}