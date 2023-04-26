#ifndef MAIN_H
#define MAIN_H

/* Constants */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

extern char **environ;

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_COUNT 64

/* Prototypes */
void execute_command(char *args[]);
void sigint_handler(int signo);
int parse_input(char *input, char *args[]);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

#endif /* MAIN_H */
