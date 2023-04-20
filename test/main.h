#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_COUNT 64

/**
 * Execute a command in a child process.
 *
 * @param args      Array of arguments for the command, including the command name as the first element.
 * @param background Indicates whether the process should run in the background (1) or foreground (0).
 */
void execute_command(char *args[], int background);

/**
 * Parse user input into separate arguments.
 *
 * @param input  The user input.
 * @param args   Array to store the arguments.
 *
 * @return The number of parsed arguments.
 */
int parse_input(char *input, char *args[]);

#endif /* MAIN_H */
