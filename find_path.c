#include "main.h"
/**
 * find_executable_path - function to find path
 * @exe_name: name for exe to search
 *
 * Return: pointer to path of exe, or NULL if fail.
 */
char *find_executable_path(char *exe_name)
{
        char *path = NULL, **env, *dir = NULL, *exe_path, *path_copy;

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
        path_copy = strdup(path);
        while ((dir = strtok(path_copy, ":")) != NULL)
        {
                path_copy = NULL;
                exe_path = malloc(strlen(dir) + strlen(exe_name) + 2);
                if (exe_path == NULL)
                {
                        fprintf(stderr, "Error: allocation error\n");
                        free(path_copy);
                        return (NULL);
                }
                sprintf(exe_path, "%s/%s", dir, exe_name);
                if (access(exe_path, X_OK) == 0)
                {
                        free(path_copy);
                        return (exe_path);
                }
                else
                {
                        free(exe_path);
                }
        }
        fprintf(stderr, "/hsh: 1: %s: not found\n", exe_name);
        free(path_copy);
        return (NULL);
}
