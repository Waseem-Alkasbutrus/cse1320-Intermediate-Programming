#ifndef PROBLEM3_H_
#define PROBLEM3_H_

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1048
#define DATE_SIZE 11
#define NAME_SIZE 12

typedef struct {
	char userId[NAME_SIZE];
	char date[DATE_SIZE];
	char *message;
} chirp;

void remove_newline(char *str);

#endif