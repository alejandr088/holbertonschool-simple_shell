#include "main.h"

/**
 * execute_command - Executes a command with its arguments
 * @args: An array of arguments to execute
 *
 * Return: 0 on success, 1 on error
 */
int execute_command(char **args)
{
	pid_t child_pid = 0;
	int status = 0;

	if (args == NULL || args[0] == NULL)
		return (0);

	if (strcmp(args[0], "exit") == 0)
	{
		exit(0);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: fork");
		return (1);
	}

	if (child_pid == 0)
	{
		char *exe_path = find_executable_path(args[0]);
		if (exe_path == NULL)
		{
			fprintf(stderr, "/hsh: 1: %s: not found\n", args[0]);
			exit(1);
		}

		if (execve(exe_path, args, NULL) == -1)
		{
			perror("Error: execve");
			exit(1);
		}
	}
	else
	{
		wait(&status);

		if (WIFEXITED(status))
			status = WEXITSTATUS(status);

		if (status != 0)
			return (1);
	}
	return (0);
}

/**
 * tokenize - Tokenizes a string of arguments
 * @line: string of arguments to tokenize
 *
 * Return: array of tokens
 */
char **tokenize(char *line)
{
	int bufsize = MAX_ARG_COUNT;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

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