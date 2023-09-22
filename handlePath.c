#include "shell.h"

/**
 * _getpath - Retrieve full path
 * @cmd: command argument
 *
 * Return: pointer to path
 */
char *_getpath(char *cmd)
{
	char *env_path, *f_cmd, *dir;
	int i;
	struct stat st;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i] == '/')
		{
			if (stat(cmd, &st) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}

	env_path = _getenv("PATH");
	if (!env_path)
		return (NULL);

	dir = strtok(env_path, ":");
	while (dir)
	{
		f_cmd = malloc(_strlen(dir) + _strlen(cmd) + 2);
		if (f_cmd)
		{
			_strcpy(f_cmd, dir);
			_strcat(f_cmd, "/");
			_strcat(f_cmd, cmd);
			if (stat(f_cmd, &st) == 0)
			{
				free(env_path);
				return (f_cmd);
			}
			free(f_cmd), f_cmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(env_path);
	return (NULL);
}
