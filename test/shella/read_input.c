#include "shell.h"

/**
 * read_input - Reads input from the user
 * Return: Pointer to the input string
 */
char *read_input(void)
{
	char *buffer = malloc(sizeof(char) * BUFFER_SIZE);
	int c, i = 0;

	if (!buffer)
	{
		perror("Error de asignación de memoria");
		exit(EXIT_FAILURE);
	}

	while ((c = getchar()) != '\n' && c != EOF)
	{
		buffer[i++] = c;
		if (i == BUFFER_SIZE)
		{
			printf("El comando es demasiado largo\n");
			exit(EXIT_FAILURE);
		}
	}

	buffer[i] = '\0';

	return (buffer);
}
