#include <stdio.h>


typedef float vector2f[2];

void find_min_max(FILE *fp, vector2f cordsArr[]) {
	vector2f tempCords = {0};

	while(1) {
		fscanf(fp, "%f,%f", &tempCords[0], &tempCords[1]);

		for (int i = 0; i < 2; i++) {
			if (tempCords[i] > cordsArr[1][i]) {
				cordsArr[1][i] = tempCords[i];
			}
		}

		for (int i = 0; i < 2;i++) {
			if (tempCords[i] < cordsArr[0][i]) {
				cordsArr[0][i] = tempCords[i];
			}
		}

		if (feof(fp)) {
			break;
		}
	}
}

int main(int argc, char *argv[2]) {
	if (argc != 2) {
		printf("Usage: ./a.out FILE\n");
		return 1;
	}

	FILE *fp = fopen(argv[1], "r");
	if (fp == NULL) {
		printf("CANNOT OPEN FILE.\n");
		return 1;
	}

	vector2f cords[3] = {0};

	find_min_max(fp, cords);

	cords[2][0] = (cords[0][0] + cords[1][0])/2;
	cords[2][1] = (cords[0][1] + cords[1][1])/2;

	printf("%.2f, %.2f, %.2f, %.2f, %.2f, %.2f\n", cords[0][0],cords[0][1],cords[1][0],cords[1][1],cords[2][0],cords[2][1]);	

	fclose(fp);

	return 0;
} 