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
void loop(void);
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);
char **tokenize(char *input);
int print_env(void);
int exit_funct(void);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
char *find_executable_path(char *exe_name);

/* Global variables */
extern char **environ;

#endif
