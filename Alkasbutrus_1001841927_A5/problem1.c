#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* part_a() {
	int *ptr = malloc(sizeof(int));
	*ptr = 20;

	return ptr;
}

int* part_b() {
	int *ptr = calloc(200, sizeof(int));

	return ptr;
}

int** part_c() {
	int **ptr = calloc(30, sizeof(int*));

	for(int i = 0; i < 30; i++) {
		ptr[i] = calloc(40, sizeof(int));
	}

	return ptr;
}

int*** part_d() {
	int ***ptr = calloc(40, sizeof(int*));

	for(int i = 0; i < 40; i++) {
		ptr[i] = calloc(40, sizeof(int*));

		for(int j = 0; j < 40; j++) {
			ptr[i][j] = calloc(20, sizeof(int));
		}
	}

	return ptr;
}

double* part_e() {
	double *ptr = malloc(sizeof(double));
	*ptr = 3.14;

	return ptr;
}

double* part_f() {
	double *ptr = calloc(300, sizeof(double));

	return ptr;
}

double** part_g() {
	double **ptr = calloc(80, sizeof(double*));

	for(int i = 0; i < 80; i++) {
		ptr[i] = calloc(80, sizeof(double));
	}

	return ptr;
}

char* part_h() {
	char *ptr = calloc(1 ,sizeof(char));

	return ptr;
}

char* part_i() {
	char *ptr = calloc(2048 ,sizeof(char));

	return ptr;
}

char** part_j() {
	char **ptr = calloc(1024 ,sizeof(char*));

	for(int i = 0; i < 1024; i++) {
		ptr[i] = calloc(1024, sizeof(char));
	}

	return ptr;
}

int main() {
	//part a
	int *a = part_a();

	//part b
	int *b = part_b();

	//part c
	int **c = part_c();

	//part d
	int ***d = part_d();

	//part e
	double *e = part_e();

	//part f
	double *f = part_f();

	//part g
	double **g = part_g();


	//part h
	char* h = part_h();

	//part i
	char* i = part_i();

	//part j
	char **j = part_j();



	//free allocated memory	
	free(a);

	free(b);

	for(int i = 0; i < 30; i++) {
		free(*(c + i));
	}
	free(c);
	
	for (int i = 0; i < 40; i++) {

		for(int j = 0; j < 40; j++) {
			free(d[i][j]);
		}
		free(d[i]);
	}
	free(d);

	free(e);
	
	free(f);

	for (int i = 0; i < 80; i++) {
		free(g[i]);
	}
	free(g);

	free(h);

	free(i);

	for (int i = 0; i < 1024; i++) {
		free(j[i]);
	}
	free(j);

	return 0;
}