#include "main.h"
/**
 * find_executable_path - function to find path
 * @exe_name: name for exe to search
 *
 * Return: pointer to path of exe, or NULL if fail.
 */
char *find_executable_path(char *exe_name)
{
	char *path = NULL, **env, *dir = NULL, *exe_path;
	for (env = environ; *env != NULL; env++)
	{
		if (strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env + 5;
			break;
		}
	}

	if (path == NULL)
	{
		fprintf(stderr, "Error: PATH environment variable not found\n");
		return (NULL);
	}

	while ((dir = strtok(path, ":")) != NULL)
	{
		path = NULL;
		exe_path = malloc(strlen(dir) + strlen(exe_name) + 2);
		if (exe_path == NULL)
		{
			fprintf(stderr, "Error: allocation error\n");
			return (NULL);
		}
		sprintf(exe_path, "%s/%s", dir, exe_name);
		if (access(exe_path, X_OK) == 0)
		{
			return (exe_path);
		}
		else
		{
			free(exe_path);
		}
	}
	fprintf(stderr, "%s: 1: %s: not found\n", exe_name, exe_name);
	return (NULL);
}

