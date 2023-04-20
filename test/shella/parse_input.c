#include "shell.h"

/**
 * parse_input - Parse a line of input into an array of arguments
 * @input: The line of input to parse
 * Return: An array of arguments, where the first
 *         argument is the command, or NULL
 *         if an error occurs.
 */
char **parse_input(char *input)
{
	char **args = NULL;
	char *arg = NULL;

	args = malloc(sizeof(char *) * 2);
	if (args == NULL)
	{
		perror("malloc");
		return (NULL);
	}

	arg = strtok(input, "\n");
	args[0] = arg;

	if (arg == NULL)
	{
		free(args);
		return (NULL);
	}

	args[1] = NULL;

	return (args);
}

