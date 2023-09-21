#include "shell.h"

/**
 * get_location - function takes command and returns it's path
 * @command: command to lookup for it's path
 *
 * Return: path where command located
 */

char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_copy = _strdup(path);
		command_length = _strlen(command);
		path_token = _strtok(path_copy, ":");

		while (path_token)
		{
			directory_length = _strlen(path_token);
			file_path = malloc(command_length + directory_length + 2);
			_strcpy(file_path, path_token);
			_strcat(file_path, "/");
			_strcat(file_path, command);
			_strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
				free(file_path);
				path_token = _strtok(NULL, ":");
		}
		free(path_copy);

		if (stat(command, &buffer) == 0)
		{
			return (command);
		}
	}
	return (NULL);
}

