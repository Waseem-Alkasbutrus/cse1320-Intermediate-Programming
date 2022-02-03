#include <stdio.h>


/*
	findFactors finds and prints the biggest 3 factors of a user defined integer (N), 
	given that N is a non-prime number outside the range (-1,1).

	parameters:
		int N: an integer value

	returns:
		NONE (void)
*/
void findFactors(int N) {
	int count = 0, factors[3] = {0}, min = 0, max = N;

	if (N < 0) {
		min = N;
		max = N * -1;
	}

	for (int i = max; i >= min; i--) {
		if (count >= 3) {
			break;
		}

		if (i != 0 && N%i == 0) {
			factors[count] = i;
			count++;
		}
	}

	if (count < 3) {
		printf("%d is prime!\n", N);
	} else {
		printf("%d\n%d\n%d\n", factors[0], factors[1], factors[2]);
	}
}

/*
	main asks the user to enter an integer (N). If N is greater than 1, or less than -1 it will call findFactor() to
	check for the 3 biggest factors of N.

	parameters:
		NONE

	return:
		0 for a successful run
*/
int main(void) {
	int N = 0;

	printf("Enter an integer: ");
	scanf("%d", &N);

	if (N > 1 || N < -1) {
		findFactors(N);
	} else {
		printf("%d is neither prime, not composite.\n", N);
	}

	return 0;
}