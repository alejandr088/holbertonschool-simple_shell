#include "main.h"

/**
 * execute_command - execute a command
 * @args: command to execute with arguments
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("Error: fork error\n");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error: execve error\n");
			return (-1);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}

/**
 * tokenize - Tokenizes a string of arguments
 * @line: string of arguments to tokenize
 *
 * Return: array of tokens
 */
char **tokenize(char *line)
{
    int bufsize = MAX_ARG_COUNT;
    int position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));
    char *token, **tmp;

    if (!tokens)
    {
        fprintf(stderr, "Error: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, TOK_DELIM);
    while (token != NULL)
    {
        tokens[position] = token;
        position++;

        if (position >= bufsize)
        {
            bufsize += MAX_ARG_COUNT;
            tmp = realloc(tokens, bufsize * sizeof(char *));
            if (!tmp)
            {
                fprintf(stderr, "Error: allocation error\n");
                free(tokens);
                exit(EXIT_FAILURE);
            }
            tokens = tmp;
        }

        token = strtok(NULL, TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}
