#include "main.h"

/**
 * execute_command - execute the given command in a child process
 * @cmd: command to execute
 *
 * Return: None
 */
void execute_command(char *cmd)
{
	char *args[2];
	pid_t child_pid;
	int status;

	args[0] = cmd;
	args[1] = NULL;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error forking child process");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Command not found");
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}
}

/**
 * main - entry point of the shell
 *
 * Return: 0 on success, -1 on error
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
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
		input[read_byte - 1] = '\0';
		execute_command(input);
	}
	return (0);
}

