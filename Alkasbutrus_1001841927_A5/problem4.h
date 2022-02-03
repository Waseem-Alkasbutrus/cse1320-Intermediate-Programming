#ifndef PROBLEM4_H_
#define PROBLEM4_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF_SIZE 64

typedef struct {
    long size;
    int zone;
    int cr;
    int ac;
    int hp;
    char *name;
} creature;

int get_creatures(FILE *fp, int zone, creature *creatureArr);

#endif