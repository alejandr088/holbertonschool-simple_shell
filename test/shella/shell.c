#include "shell.h"
#include <stdio.h>
#define _GNU_SOURCE

/**
 * main - Entry point
 * Return: 0 on success, -1 on error.
 */
int main(void)
{
	char *input;
	char **args;
	int status;

	while (1)
	{
		prompt();
		input = read_input();
		args = parse_input(input);
		status = execute(args);
		if (status == -1)
			printf("Error executing command\n");
		free(input);
		free(args);
	}

	return (0);
}

/**
 * prompt - Display a prompt for the user
 */
void prompt(void)
{
	printf("$ ");
}

/**
 * read_input - Read a line of input from the user
 * Return: The line of input read from the user.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t size = 0;

	getline(&input, &size, stdin);

	return (input);
}

/**
 * parse_input - Parse a line of input into an array of arguments
 * @input: The line of input to parse
 * Return: An array of arguments.
 */
char **parse_input(char *input)
{
	char **args = NULL;
	char *token;
	int i = 0;

	token = strtok(input, " \n");
	while (token != NULL)
	{
		args = realloc(args, sizeof(char *) * (i + 1));
		args[i] = token;
		i++;
		token = strtok(NULL, " \n");
	}
	args = realloc(args, sizeof(char *) * (i + 1));
	args[i] = NULL;

	return (args);
}

/**
 * execute - Execute a command with arguments
 * @args: An array of arguments, where the first argument is the command
 * Return: 0 on success, -1 on error.
 */
int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(args[0], args, NULL) == -1)
		{
			perror("execve");
			return (-1);
		}
	}
	else
	{
		/* Parent process */
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}
