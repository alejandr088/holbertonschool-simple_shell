#include "main.h"
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

	signal(SIGINT, sigint_handler); /* maneja la señal */
	while (1) /* bucle infinito para ejecutar el shell */
	{
		printf("($) ");
		fflush(stdout); /* limpia buffer de salida */

		read_byte = read(STDIN_FILENO, input, MAX_INPUT_LENGTH); /* lee input */

		if (read_byte == -1) /* comprueba errores al leer input */
		{
			perror("Error reading input");
			return (-1);
		}
		else if (read_byte == 0) /* maneja EOF o linea vacia */
		{
			printf("\n");
			break;
		}

		if (input[read_byte - 1] == '\n') /* verifica si hay un SL al final */
		{
			input[read_byte - 1] = '\0'; /* agrega el car null al final */
		}
		else
		{
			input[read_byte] = '\0'; /* agrega el car null al final */
		}

		parse_input(input, args); /* llama a la funcion parse */
		execute_command(args); /* llama a func execute */
	}
	return (0);
}

