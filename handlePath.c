#include "shell.h"

/**
 * list_dir_tree - Builds a linked list of directory path
 * Return: linked list of the directory path
 */
dir_list *list_dir_tree(void)
{
	dir_list *head = NULL;
	char *env_path, *tkn;

	env_path = _getenv("PATH");
	if (!env_path)
		return (NULL);
	tkn = strtok(env_path, ":");
	while (tkn)
	{
		add_node_end(&head, tkn);
		tkn = strtok(NULL, ":");
	}
	free(env_path);
	return (head);
}

/**
 * _getpath - Retrieve full path of a command
 * @cmd: command
 *
 * Return: pointer to the full path
 */
char *_getpath(char *cmd)
{
	dir_list *ldir, *tmp;
	char *env_path;
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
	ldir = list_dir_tree();
	tmp = ldir;
	while (tmp)
	{
		env_path = malloc(_strlen(tmp->dir) + _strlen(cmd) + 2);
		if (!env_path)
		{
			free_dir_list(ldir);
			return (NULL);
		}
		_strcpy(env_path, tmp->dir);
		_strcat(env_path, "/");
		_strcat(env_path, cmd);
		if (stat(env_path, &st) == 0)
		{
			free_dir_list(ldir);
			return (env_path);
		}
		free(env_path), env_path = NULL;
		tmp = tmp->next;
	}
	free_dir_list(ldir);
	return (NULL);
}
