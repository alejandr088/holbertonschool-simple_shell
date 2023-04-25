#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_ARG_COUNT 64

extern char **environ;
/**
 * execute_command - Execute a command in a child process.
 *
 * @args: Array of arguments for the command.
 * @background: Indicates whether the process should bckgd or fgd (0).
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
 * parse_input - parse the input string into an array of arguments.
 *
 * @input: Input string to parse.
 * @args: Array of arguments to store the parsed arguments.
 * Return: Number of arguments parsed.
 */
int parse_input(char *input, char *args[])
{
	int arg_count = 0;
	char *token;

	token = strtok(input, " \t\n");
	while (token != NULL)
	{
		args[arg_count++] = token;
		token = strtok(NULL, " \t\n");
	}

	args[arg_count] = NULL;
	return (arg_count);
}
/**
 * main - main function.
 *
 * Return: always 0.
 */
int main(void)
{
	char input[MAX_INPUT_LENGTH];
	char *args[MAX_ARG_COUNT];
	int arg_count;
	int background;

	while (1)
	{
		printf("myshell> ");
		fgets(input, MAX_INPUT_LENGTH, stdin);
		input[strcspn(input, "\n")] = '\0';

		background = 0;
		if (input[strlen(input) - 1] == '&')
		{
			background = 1;
			input[strlen(input) - 1] = '\0';
		}

		arg_count = parse_input(input, args);
		if (arg_count > 0)
		{
			if (strcmp(args[0], "exit") == 0)
			{
				exit(0);
			}
			else
			{
				execute_command(args, background);
			}
		}
	}

	return (0);
}

