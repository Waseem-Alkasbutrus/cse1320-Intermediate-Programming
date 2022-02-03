#ifndef PROBLEM2_H_
#define PROBLEM2_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

typedef struct quest quest;
struct quest {
	char *questDescription; 
	quest *prev;
	quest *next;
};

void enqueue(quest **head, quest **tail, char *description);
void add_quest(quest **head, quest **tail);
void mark_complete(quest **head, quest **tail);
void print_quest(quest *node);
void print_menu(int menuCode);
int menu(char optionCount, int menuCode);

#endif