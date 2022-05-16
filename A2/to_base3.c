#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 6
#define TO_BASE 3

void int_to_b3(short, char[]);

int main(void) {
	short decimal = 0;
	char base3[ARRAY_SIZE] = {};

	printf("Enter a number in decimal: ");
	scanf("%hi", &decimal);
	while(getchar() != '\n');

	int_to_b3(decimal, base3);

	printf("\n%hi decimal = ", decimal);
	for(int i = 0; i < ARRAY_SIZE; i++) {
		printf("%c", base3[i]);
	}
	printf(" base 3.\n");

	return 0;
} 

void int_to_b3(short decimal, char base3[ARRAY_SIZE]) {
	short quotient = decimal;

	for (int i = ARRAY_SIZE -1; i >= 0; i--) {
		
		short remainder = quotient % TO_BASE;
		quotient = quotient / TO_BASE;

		base3[i] = remainder + '0';

		if(quotient == 0) {
			break;
		}
	}
}
