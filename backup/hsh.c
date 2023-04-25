#include "main.h"

/**
 * parse_input - parse input string into arguments
 * @input: input string
 * @args: array to store arguments
 *
 * Return: number of arguments
 */
int parse_input(char *input, char *args[])
{
	int argc = 0;
	char *token;

	token = strtok(input, " \t\n");
	while (token != NULL && argc < MAX_ARG_COUNT - 1)
	{
		args[argc++] = token;
		token = strtok(NULL, " \t\n");
	}
	args[argc] = NULL;

	return (argc);
}

/**
 * execute_command - xcute the given command in a child process
 * @args: array of arguments
 *
 * Return: none
 */
void execute_command(char *args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error forking child process");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve(args[0], args, environ);
		fprintf(stderr, "%s: 1: %s: not found\n", args[0], args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("Error waiting for child process");
		exit(EXIT_SUCCESS);
		}
		if ((!WIFEXITED(status) || WEXITSTATUS(status) != 0) && WIFSIGNALED(status))
		{
			fprintf(stderr, "Command exited with non-zero status\n");
		}
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
