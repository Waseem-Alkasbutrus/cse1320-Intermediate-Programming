#ifndef CREATURE_HASH_H_
#define CREATURE_HASH_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

typedef struct Creature Creature;
struct Creature {
	char *name;
	char *type;
	int hp;
	int ac;
	int speed;
};

int menu(char);
int scan_file(FILE *, Creature **);
Creature* add_creature();

#endif//CREATURE_HASH_H_