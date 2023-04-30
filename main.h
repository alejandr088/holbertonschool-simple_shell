#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_COUNT 64
#define TOK_DELIM " \t\r\n\a"

/* Function Declarations */
int execute_command(char **args);
char **tokenize(char *input);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

extern char **environ;

#endif
