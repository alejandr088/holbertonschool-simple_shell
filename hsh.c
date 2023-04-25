#include "main.h"

/**
 * parse_input - parse input string into arguments
 * @input: the input string
 * @args: array of pointers to store the arguments
 * Return: number of arguments, or -1 on failure
 */
int parse_input(char *input, char *args[])
{
	char *token;
	int i = 0;

	token = strtok(input, " \t\n");
	while (token != NULL && i < MAX_ARG_COUNT - 1)
	{
		args[i] = token;
		token = strtok(NULL, " \t\n");
		i++;
	}
	args[i] = NULL;

	if (i == MAX_ARG_COUNT - 1 && token != NULL)
	{
		print_error(args[0], 2);
		return (-1);
	}

	return (i);
}

/**
 * execute_command - execute the given command in a child process
 * @args: array of arguments
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
		exit(1);
	}
	if (child_pid == 0)
	{
		char *path = "/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin";
		char *path_copy = strdup(path);
		char *dir = strtok(path_copy, ":");
		char *cmd_path = NULL;

		while (dir)
		{
			cmd_path = malloc(strlen(dir) + strlen(args[0]) + 2);
			if (cmd_path == NULL)
			{
				perror("malloc");
				exit(EXIT_FAILURE);
			}

			sprintf(cmd_path, "%s/%s", dir, args[0]);
			execve(cmd_path, args, environ);
			free(cmd_path);
			dir = strtok(NULL, ":");
		}
		print_error(args[0], 1);
		print_error(args[0], 1);
		exit(1);
	}
	else
	{
		if (wait(&status) == -1)
		{
			perror("Error waiting for child process");
			exit(1);
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

/**
 * print_error - print error messages
 * @command: the command that failed
 * @error_code: the error code
 * Return: none
 */
void print_error(char *command, int error_code)
{
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "%s: command not found\n", command);
			break;
		case 2:
			fprintf(stderr, "%s: too many arguments\n", command);
			break;
		case 3:
			fprintf(stderr, "%s: not a directory\n", command);
			break;
		case 4:
			perror(command);
			break;
		default:
			fprintf(stderr, "%s: unknown error\n", command);
			break;
	}
}
