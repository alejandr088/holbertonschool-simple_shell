#include "main.h"

/**
 * exe_command - Executes a command with its arguments
 * @args: array of arguments to execute
 *
 * Return: exit status of the command
 */
int exe_command(char **args)
{
	pid_t child_pid = 0;
	int status = 0;
	char *exe_path;

	if (args == NULL || args[0] == NULL)
		return (0);
	exe_path = find_executable_path(args[0]);
	if (exe_path == NULL)
	{
		fprintf(stderr, "%s: command not found\n", args[0]);
		return (127);
	}
	args[0] = exe_path;
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error: fork");
		free(exe_path);
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error: execve");
			free(exe_path);
			_exit(1);
		}
	}
	else
	{
		wait(&status);
	}
	free(exe_path);
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
