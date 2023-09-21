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
	struct stat st;

	env_path = _getenv("PATH");

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
			free(f_cmd), cmd = NULL;

			dir = strtok(NULL, ":");
		}
	}
	free(env_path);
	return (NULL);
}

/**
 * main - Entry point
 * @ac: argument
 * @av: argument
 *
 * Return: 0
 */
int main(int ac, char **av)
{
	char *f_cmd;

	f_cmd = _getpath(av[1]);
	if (f_cmd)
		printf("%s\n", f_cmd);
	else
		printf("Does not exist");
}
