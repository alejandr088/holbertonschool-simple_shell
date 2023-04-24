#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

/**
 *  * parse_input - Parse input string into array of arguments
 *   * @input: input string to parse
 *    *
 *     * Return: array of arguments, or NULL on failure
 *      */
char **parse_input(char *input)
{
	char **args = NULL;
	char *arg = strtok(input, " \t\n");
	int nargs = 0;

	while (arg)
	{
		args = realloc(args, sizeof(char *) * (nargs + 1));
		if (!args)
		{
			perror("realloc");
			exit(1);
		}
		args[nargs++] = arg;
		arg = strtok(NULL, " \t\n");
	}

	args = realloc(args, sizeof(char *) * (nargs + 1));
	if (!args)
	{
		perror("realloc");
		exit(1);
	}
	args[nargs] = NULL;

	return (args);
}

/**
 *  * main - Entry point
 *   *
 *    * Return: 0 on success, 1 on failure.
 *     */
int main(void)
{
	char *input;
	char **args;
	pid_t pid;
	int status;
	size_t len = 0;

	while (1)
	{
		printf("$ ");
		fflush(stdout);

		input = NULL;
		if (getline(&input, &len, stdin) == -1)
		{
			perror("getline");
			return (1);
		}

		args = parse_input(input);
		if (!args)
		{
			free(input);
			continue;
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			free(input);
			free(args);
			continue;
		}
		else if (pid == 0)
		{
			if (execvp(args[0], args) == -1)
			{
				perror("execvp");
				free(input);
				free(args);
				exit(1);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
		}

		free(input);
		free(args);
	}

	return (0);
}
