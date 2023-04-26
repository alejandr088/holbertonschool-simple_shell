#include "main.h"
/**
 * main - entry point of the shell
 *
 * Return: 0 on success, -1 on error
 */

int main(void)
{
	char *line = NULL;
	char *args[MAX_ARG_COUNT];
	size_t len = 0;
	ssize_t read;
	int argc;

	signal(SIGINT, sigint_handler);

	while (1)
	{
		printf("($) ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			break;
		}
		argc = parse_input(line, args);
		if (argc > 0)
		{
			execute_command(args);
		}
	}

	free(line);
	line = NULL;

	return (EXIT_SUCCESS);
}
