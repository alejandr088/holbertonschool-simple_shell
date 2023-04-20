#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_COMMAND_LENGTH 1024
/**
 * main - main function.
 *
 * Return: always 0.
 */

int main(void)
{
	char command[MAX_COMMAND_LENGTH];
	char *args[64];

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		if (fgets(command, MAX_COMMAND_LENGTH, stdin) == NULL)
			break;
		command[strcspn(command, "\n")] = '\0';
		if (strcmp(command, "exit") == 0)
			break;
		int i = 0;

		args[i] = strtok(command, " ");
		while (args[i] != NULL)
		{
			i++;
			args[i] = strtok(NULL, " ");
		}
		args[i] = NULL;
		pid_t pid = fork();

		if (pid == 0)
		{
			execvp(args[0], args);
			perror("Error");
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			waitpid(pid, NULL, 0);
		}
		else
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

