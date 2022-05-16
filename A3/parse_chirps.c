#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

int parse_chirps() {

}


int main(args[2]) {
	char buffer[BUFFER_SIZE] = {0};

	while(!strcmp(buffer, "END")) {

		fgets(buffer, BUFFER_SIZE, stdin);
		puts(buffer);
	
	}

	return 0;
}