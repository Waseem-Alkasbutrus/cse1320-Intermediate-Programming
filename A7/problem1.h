#ifndef PROBLEM1_H_
#define PROBLEM1_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

typedef enum {
	OPTIONAL,
	REQUIRED
} priority;

typedef struct instruction instruction;
struct instruction {
	char *desc;
	priority p;
	instruction *next;
};

void add_step(instruction **);
void push(instruction **, char *, priority);
void pop(instruction **head, char print);
void print_instructions(instruction *);
int menu(char);

#endif