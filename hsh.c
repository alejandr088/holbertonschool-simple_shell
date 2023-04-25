#include "main.h"

/**
 * execute_command - xcute the given command in a child process
 * @cmd: command to xcute
 *
 * Return: None
 */
void execute_command(char *cmd)
{
	const char *args[] = {cmd, NULL};
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error forking child process");
		exit(1);
	}
	if (child_pid == 0)
	{
		if (execve(args[0], (char *const *)args, NULL) == -1)
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
 * * Return: 0 on success, -1 on error
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("($) ");
		ssize_t read_byte = read(STDIN_FILENO, input, MAX_INPUT_LENGTH);

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
