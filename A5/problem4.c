#include "problem4.h"

int main (int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./a.out FILE ZONE\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Couldn't open file.\n");
        return 1;
    }

    creature *creatureArr = 0;

    int creatureCount = get_creatures(fp, atoi(argv[2]), creatureArr);



    for (int i = 0; i < creatureCount; i++) {
        printf("Name: %s\n", creatureArr[i].name);
        printf("CR: %d", creatureArr[i].cr);
        printf("HP: %d\n", creatureArr[i].hp);
        printf("AC: %d\n", creatureArr[i].ac);
        printf("Zone: %d\n", creatureArr[i].zone);
    }

    for (int i = 0; i < creatureCount; i++) {
        free(creatureArr[i].name);
    }
    free(creatureArr);
    fclose(fp);
    return 0;
}

int get_creatures(FILE *fp, int zone, creature *creatureArr) {
    creature creatureBuff = {0};
    int len_creatureArr = 0;
    while(1) {
        fread(&creatureBuff, sizeof(creature) - sizeof(char*), 1, fp);

        if (creatureBuff.zone == zone) {
            len_creatureArr++;
            creatureArr = realloc(creatureArr, (len_creatureArr + 1)*sizeof(creature));

            creatureArr[len_creatureArr - 1] = creatureBuff;

            char nameBuff[BUFF_SIZE] = {0};
            fread(&nameBuff, creatureBuff.size - (sizeof(creature) - sizeof(char*)), 1, fp);
            creatureArr[len_creatureArr - 1].name = calloc(1, strlen(nameBuff)*sizeof(char));
            strcpy(creatureArr[len_creatureArr - 1].name, nameBuff);
        } else {
            fseek(fp, -(sizeof(creature)-sizeof(char*)), SEEK_CUR);
            fseek(fp, creatureBuff.size, SEEK_CUR);
        }

        if (feof(fp)) {
            break;
        }

    }

    return len_creatureArr;
}