#include "main.h"

/**
 * execute_command - Execute a command in a child process.
 *
 * @args: Array of arguments for the command, including the command name.
 * @background: Indicates if process run in the background or foreground.
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
		// Child process
		if (execve(args[0], args, NULL) < 0)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		// Parent process
		if (!background)
		{
			waitpid(pid, &status, 0);
		}
	}
}

/**
 * parse_input - user input into separate arguments.
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
 * main - main function of the program.
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
			// End of input (e.g., Ctrl + D)
			printf("\n");
			break;
		}
		// Check if command should run in the background
		background = 0;
		if (input[strlen(input) - 2] == '&')
		{
			background = 1;
			input[strlen(input) - 2] = '\0';
		}
		// Parse input into arguments
		arg_count = parse_input(input, args);
		// Check if input is empty
		if (arg_count == 0)
		{
			continue;
		}
		// Handle built-in commands
		if (strcmp(args[0], "exit") == 0)
		{
			break;
		}
		// Execute the command
		execute_command(args, background);
	}
	return (0);
}

