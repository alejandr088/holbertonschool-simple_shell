#include "main.h"

/**
 * execute_command - Executes a command with its arguments
 * @args: An array of arguments to execute
 *
 * Return: The exit status of the command
 */
int execute_command(char **args)
{
	pid_t child_pid = 0;
	int status = 0;

	if (args == NULL || args[0] == NULL)
		return (0);
	if (access(args[0], X_OK) == -1)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", args[0]);
		return 127;
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: fork");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error: execve");
			_exit(1);
		}
	}
	else
	{
		wait(&status);
	}
	return (status);
}

/**
 * tokenize - Tokenizes a string of arguments
 * @line: string of arguments to tokenize
 *
 * Return: array of tokens
 */
char **tokenize(char *line)
{
	int bufsize = MAX_ARG_COUNT, position = 0;
	char *token;
	char **tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		fprintf(stderr, "Error: allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += MAX_ARG_COUNT;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Error: allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, TOK_DELIM);
	}
	tokens[position] = NULL;
	return (tokens);
}
