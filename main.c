#include "main.h"
/**
 * main - entry point of the shell
 *
 * Return: 0 on success, -1 on error
 */

int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARG_COUNT];
	int read_byte;

	while (1)
	{
		printf("($) ");
		fflush(stdout);

		read_byte = read(STDIN_FILENO, input, MAX_INPUT_LENGTH);

		if (read_byte == -1)
		{
			perror("Error reading input");
			return (-1);
		}
		else if (read_byte == 0)
		{
			printf("\n");
			break;
		}

		if (input[read_byte - 1] == '\n')
		{
			input[read_byte - 1] = '\0';
		}
		else
		{
			input[read_byte] = '\0';
		}

		parse_input(input, args);
		execute_command(args);
	}
	return (0);
}
