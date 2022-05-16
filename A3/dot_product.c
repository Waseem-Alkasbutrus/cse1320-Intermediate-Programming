#include <stdio.h>

double dot_product(double *A, double *B, int n) {
	double result = 0;

	for (int i = 0; i < n; i++) {
		result = result + ((*(A+i)) * (*(B+i)));
	}

	return result;
}

int main(void) {
	int arrSize = 8;

	double arrA[arrSize];
	double arrB[arrSize];

	printf("Enter A = (a1 a2 a3...): ");
	for(int i = 0; i < arrSize; i++){ 
		scanf("%lf", arrA+i);
	}
	while(getchar() != '\n');

	printf("Enter B = (b1 b2 b3...): ");
	for(int i = 0; i < arrSize; i++){ 
		scanf("%lf", arrB+i);
	}
	while(getchar() != '\n');

	printf("Result = %0.2lf\n", dot_product(arrA, arrB, arrSize));

	return 0 ;
} 
