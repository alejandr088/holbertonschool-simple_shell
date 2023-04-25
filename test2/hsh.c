#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_COUNT 64

/**
 * execute_command - Execute the given command in a child process
 * @cmd: The command to execute
 *
 * Return: None
 */
void execute_command(char *cmd)
{
	char *args[3];
	pid_t child_pid;
	int status;

	args[0] = cmd;
	args[1] = NULL;
	args[2] = NULL;

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
 * main - Entry point of the simple shell
 *
 * Return: 0 on success, -1 on error
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf("($) ");
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			if (feof(stdin))
			{
				printf("\n");
				break;
			}
			else
			{
				perror("Error reading input");
				return (-1);
			}
		}

		input[strcspn(input, "\n")] = '\0';

		execute_command(input);
	}
	return (0);
}

