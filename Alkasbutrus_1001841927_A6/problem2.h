#ifndef PROBLEM2_H_
#define PROBLEM2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

typedef struct creature Creature;
struct creature{
	int hp;
	int ac;
	int speed;
	char *name;
	char *type;

	Creature *next;
};

void remove_newline(char *str);
char* alloc_str(char *str);
int count_creatures(FILE *fp);
void print_creatures(Creature *creature_list);
void release_creatures(Creature *creature_list);
Creature* add_Creature(Creature c);
Creature* insert_creature(Creature *creature_list, Creature c);
Creature* scan_creatures(FILE *fp);
Creature* filter_creatures(char *type, Creature *creatureList);

#endif