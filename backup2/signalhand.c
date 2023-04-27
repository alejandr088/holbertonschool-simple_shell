#include "main.h"

/**
 * sigint_handler - signal handler for SIGINT (Ctrl+C)
 * @signo: signal number
 *
 * Return: none
 */
void sigint_handler(int signo)
{
	if (signo == SIGINT)
	{
		printf("\nSIGINT signal received. Continuing...\n");
		fflush(stdout);
	}
}
