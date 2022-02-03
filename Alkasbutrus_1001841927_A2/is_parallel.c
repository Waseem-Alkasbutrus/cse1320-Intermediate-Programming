#include <stdio.h> 
#include <stdbool.h>

int isParallel(const float Fx[3], const float Gx[3]);

int main(void) {
	float Fx[3] = {0}, Gx[3] = {0};

	printf("Enter the coefficient of f(x) in standard form (ax+by=c):\n");
	for(int i = 0; i < 3; i++) {
		printf("%c = ", 97+ i);
		scanf("%f", &Fx[i]);
	}

	printf("\nEnter the coefficient of g(x) in standard form (ax+by=c):\n");
	for(int i = 0; i < 3; i++) {
		printf("%c = ", 97+ i);
		scanf("%f", &Gx[i]);
	}

	switch(isParallel(Fx, Gx)){
		case 0: printf("f(x) and g(x) are not parallel.\n");
			break;
		case 1: printf("f(x) g(x) are parallel.\n");
			break;
		case 2: printf("f(x) and g(x) are equal.\n");
	}

	return 0;
}

int isParallel(const float Fx[3], const float Gx[3]) {
	int result = 0;

	bool parallel = (-1*Fx[0])/Fx[1] == (-1*Gx[0])/Gx[1];
	bool equal = parallel && Fx[2]/Fx[1] == Gx[2]/Gx[1];

	if(equal) {
		result = 2;
	} else if (parallel) {
		result = 1;
	}

	return result;
}