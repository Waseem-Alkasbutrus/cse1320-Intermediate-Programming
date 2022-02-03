#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {
	if (argc != 3) {
		printf("Usage: ./a.out ROWS COLUMNS\n");
		return 1;
	}

	int N = atoi(argv[1]), M = atoi(argv[2]);

	//Allocating memory to doubleArr
	double **doubleArr = calloc(N, sizeof(double*));//allocating memory for N double pointers
	for(int i = 0; i < N; i++) {//allocating memory for M doubles in each 'row'
		doubleArr[i] = calloc(M, sizeof(double));
	}

	//assigning values to doubleArr, and print them
	for(int i = 0; i < N; i++) {
		printf("row %d:", i);

		for (int j = 0; j < M; j++) {
			doubleArr[i][j] = (double)(i*M)+j;
			printf("%8.2lf", doubleArr[i][j]);
		}

		printf("\n");
	}

	//Free allocated memory
	for(int i = 0; i < N; i++) {
		free(doubleArr[i]);
	}
	free(doubleArr);

	return 0;
}