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

	input[strcspn(input, "\n")] = '\0';

	if (strspn(input, " \t\n") == strlen(input))
		return (0);

	token = strtok(input, " \t\n");
	while (token != NULL && argc < MAX_ARG_COUNT - 1)
	{
		args[argc++] = token;
		while (*token && (*token == ' ' || *token == '\t'))
		{
			token++;
		}
		token = strtok(NULL, " \t\n");
	}
	return (argc);
}

/**
 * execute_command - execute the given command in a child process
 * @args: array of arguments
 *
 * Return: none
 */
void execute_command(char *args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork(); /* crea child process */
	if (child_pid == -1)
	{
		perror("Error forking child process");
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		if (args[0] == NULL)
		{
			fprintf(stderr, "Invalid command.\n");
			exit(EXIT_FAILURE);
		}
		execve(args[0], args, environ);
		fprintf(stderr, "%s: 1: %s: not found\n", args[0], args[0]);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(child_pid, &status, 0) == -1)
		{
			perror("Error waiting for child process");
			exit(EXIT_SUCCESS);
		}
		if ((!WIFEXITED(status) || WEXITSTATUS(status) != 0) && WIFSIGNALED(status))
		{ /* 1er () - si proceso no termino OK (SIN signal, o c/codigo de error) */
			/* 2da parte - si process termino c/señal */
			fprintf(stderr, "Command exited with non-zero status\n");
		}
	}
}
