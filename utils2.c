#include "shell.h"

/**
 * is_positive - check positive argument
 * @str: Argument
 *
 * Return: Always 0
 */
int is_positive(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _str_to_int - converts string to integer
 * @str: String to be converted
 *
 * Return: Converted string
 */
int _str_to_int(char *str)
{
	int i, n = 0;

	for (i = 0; str[i]; i++)
	{
		n *= 10;
		n += (str[i] - '0');
	}
	return (n);
}

/**
 * var_change - replace variable
 * @cmd: current command
 * @status: exit status of last command
 */
void var_change(char **cmd, int status)
{
	int i;
	char *change = NULL, *str, ch;

	for (i = 0; cmd[i]; i++)
	{
		if (cmd[i][0] == '$')
		{
			ch = cmd[i][1];
			if (ch == '?')
				change = _atoi(status);
			else if (ch == '$')
				change = _atoi((int) getpid());
			else if ((ch >= 'a' && ch <= 'z')
					|| (ch >= 'A' && ch <= 'Z'))
			{
				str = cmd[i];
				str++;
				change = _getenv(str);
				if (!change)
					change = _strdup("");
			}
			if (change)
				free(cmd[i]), cmd[i] = change;
		}
	}
}

/**
 * handle_comment - Handles shell comments
 * @cmd: command
 */
void handle_comment(char ***cmd)
{
	int i, comment = 0;

	if (!(*cmd))
		return;

	for (i = 0; (*cmd)[i]; i++)
	{
		if ((*cmd)[i][0] == '#')
		{
			comment = 1;
			break;
		}
	}
	if (comment)
	{
		while ((*cmd)[i])
		{
			free((*cmd)[i]), (*cmd)[i] = NULL;
			i++;
		}
	}
	if (!(*cmd)[0])
	{
		free((*cmd));
		(*cmd) = NULL;
	}
}

/**
 * _setenv_wd - set environment for PWD and OLDPWD
 * @key: environment key
 * @value: environment value
 * @nenv: new environment variable
 */
void _setenv_wd(char *key, char *value, char **nenv)
{
	int i;
	char *e_key, *var, *tmp, *new;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		e_key = strtok(tmp, "=");
		if (_strcmp(e_key, key) == 0)
		{
			var = strtok(NULL, "\n");
			if (_strcmp(var, value) == 0)
			{
				free(tmp);
				return;
			}
			_strcpy(environ[i], key);
			_strcat(environ[i], "=");
			_strcat(environ[i], value);
			free(tmp);
			return;
		}
		free(tmp), tmp = NULL;
	}
	new = malloc(_strlen(key) + _strlen(value) + 2);
	_strcpy(new, key);
	_strcat(new, "=");
	_strcat(new, value);
	environ[i] = new, environ[i + 1] = NULL;
	(*nenv) = new;
}
