#include "main.h"
#define _GNU_SOURCE

/**
 * main - Entry point for the custom shell
 *
 * Return: Always 0 on success, 1 on failure
 */
int main(void)
{
	char *line = NULL, **args = NULL, *prompt = "($) ";
	int status = 0;
	size_t len = 0;
	ssize_t read_byte = 0;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 5);

		read_byte = getline(&line, &len, stdin);
		if (read_byte == -1)
			break;

		args = tokenize(line);
		if (args[0] != NULL)
		{
			if (strcmp(args[0], "env") == 0)
			{
				char **env_var = environ;

				while (*env_var != NULL)
				{
					printf("%s\n", *env_var);
					env_var++;
				}
				status = 0;
			}
			else
			{
				status = execute_command(args);
			}
		}
		free(args);
	}
	free(line);
	return (status);
}
