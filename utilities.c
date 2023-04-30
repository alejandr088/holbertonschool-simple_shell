#include "main.h"

/**
 * print_env - Prints the current environment
 *
 * Return: 0 on success, 1 on failure
 */
int print_env(void)
{
    char **env;
    for (env = environ; *env != NULL; env++)
    {
        printf("%s\n", *env);
    }
    return (0);
}
int exit_funct(void)
{
    exit (0);
}