#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

extern char **environ;

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_COUNT 64

/**
 * execute_command - Execute a command in a child process.
 *
 * @args: Array of arguments for the command.
 * @background: Indicates whether the process bckgrnd or frgrnd.
 */
void execute_command(char *args[], int background)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) < 0)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (!background)
		{
			waitpid(pid, &status, 0);
		}
	}
}

/**
 * parse_input - parse user input into separate arguments.
 *
 * @input: The user input.
 * @args: Array to store the arguments.
 *
 * Return: The number of parsed arguments.
 */
int parse_input(char *input, char *args[])
{
	int arg_count = 0;
	char *arg;

	arg = strtok(input, " \t\n");
	while (arg != NULL && arg_count < MAX_ARG_COUNT - 1)
	{
		args[arg_count++] = arg;
		arg = strtok(NULL, " \t\n");
	}
	args[arg_count] = NULL;

	return (arg_count);
}

/**
 * main - function of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARG_COUNT];
	int arg_count;
	int background;

	while (1)
	{
		printf("($) ");
		fflush(stdout);

		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		background = 0;
		if (input[strlen(input) - 2] == '&')
		{
			background = 1;
			input[strlen(input) - 2] = '\0';
		}

		arg_count = parse_input(input, args);

		execute_command(args, background);
	}

	return (0);
}

