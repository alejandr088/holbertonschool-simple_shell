#include "main.h"
#define _GNU_SOURCE

/**
 * main - Entry point for the custom shell
 *
 * Return: Always 0 on success, 1 on failure
 */
int main(void)
{
	char *line = NULL, **args = NULL;
	char *prompt = "($) ";
	size_t len = 0;
	ssize_t read_byte = 0;
	int status = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 5);

		read_byte = getline(&line, &len, stdin);
		if (read_byte == -1)
			break;

		args = tokenize(line);
		status = execute_command(args);

		free(args);
	}

	free(line);
	return (status);
}