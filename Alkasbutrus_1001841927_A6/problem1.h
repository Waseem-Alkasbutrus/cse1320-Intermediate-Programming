#ifndef PROBLEM1_H_
#define PROBLEM1_H_


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STATIC_SIZE 1024

typedef struct {
int hp;
int ac;
int speed;
char *name;
char *type;
} creature;

int sort_hp(const void *elem1, const void *elem2);
int sort_ac(const void *elem1, const void *elem2);
int sort_speed(const void *elem1, const void *elem2);
int sort_name(const void *elem1, const void *elem2);
int sort_type(const void *elem1, const void *elem2);

void print_menu(int menu);
int menu(char optionCount, int menu);

void remove_newline(char *str);
void append_creature(FILE *fp);
int count_creatures(FILE *fp);
creature* scan_creatures(FILE *fp, int creatureCount);
void print_creatures(creature *arr, int creatureCount);

#endif