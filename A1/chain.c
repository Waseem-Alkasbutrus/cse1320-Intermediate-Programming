#include <stdio.h>
#include <stdbool.h>

/*
	reads a stream of user input characters and prints the longest character chain in the stream.
*/
int main(void) {
	char C1 = getchar();
	int currentChainLength = 1, maxChainLength = 0;


	while(true) {
		char C2 = getchar();

		if(C2 == (C1 + 1)) {//if C1 and C2 form a chain
			currentChainLength++;
			if (currentChainLength > maxChainLength) {
				maxChainLength = currentChainLength;
			}
		} else if (C2 == '\n') {//if C2 is the end of the line
			break;
		} else {//if C1 and C2 do not form a chain
			currentChainLength = 1;
		}

		C1 = C2;
	}

	printf("Longest chain: %d\n", maxChainLength);

	return 0;
}