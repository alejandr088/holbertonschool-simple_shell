#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void prompt(void);
char *read_input(void);
char **parse_input(char *input);
int execute(char **args);
int execute_with_status(char **args);

#endif /* SHELL_H */
