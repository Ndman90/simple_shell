#include "shell.h"

/**
 * _setenv - Sets a new environment variable or modifies an already
 * existing one
 * @cmd: builtin command
 * @argv: arguments
 * @status: exit status
 * @index: index of command
 * @nenv: new enviroment variable
 */
void _setenv(char **cmd, char **argv, int *status, int index, char **nenv)
{
	int i;
	char *key, *var, *tmp, *new;
	(void) index;
	(void) argv;

	if (!cmd[1] || !cmd[2])
	{
		arrClean(cmd), (*status) = 0;
		return;
	}
	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, cmd[1]) == 0)
		{
			var = strtok(NULL, "\n");
			if (_strcmp(var, cmd[2]) == 0)
			{
				free(tmp), arrClean(cmd), (*status) = 0;
				return;
			}
			_strcpy(environ[i], cmd[1]);
			_strcat(environ[i], "=");
			_strcat(environ[i], cmd[2]);
			free(tmp), arrClean(cmd), (*status) = 0;
			return;
		}
		free(tmp), tmp = NULL;
	}
	new = malloc(_strlen(cmd[1]) + _strlen(cmd[2]) + 2);
	_strcpy(new, cmd[1]);
	_strcat(new, "=");
	_strcat(new, cmd[2]);
	environ[i] = new;
	environ[i + 1] = NULL;
	(*nenv) = new;
	(*status) = 0, arrClean(cmd);
}

/**
 * _unsetenv - Removes an enviroment variable
 * @cmd: builtin command
 * @argv: arguments
 * @status: exit status
 * @index: index of command
 * @nenv: new environment variable
 */
void _unsetenv(char **cmd, char **argv, int *status, int index, char **nenv)
{
	int i;
	char *tmp, *key;
	(void) index;
	(void) argv;
	(void) nenv;

	if (cmd[1])
	{
		for (i = 0; environ[i]; i++)
		{
			tmp = _strdup(environ[i]);
			key = strtok(tmp, "=");
			if (_strcmp(cmd[1], key) == 0)
			{
				free(tmp), tmp = NULL;
				break;
			}
			free(tmp), tmp = NULL;
		}
		while (environ[i])
		{
			environ[i] = environ[i + 1];
			i++;
		}
	}
	(*status) = 0;
	arrClean(cmd);
}

/**
 * _cdir - changes directory to set path
 * @cmd: builtin command
 * @argv: arguments
 * @status: exit status
 * @index: index of command
 * @nenv: new environment variable
 */
void _cdir(char **cmd, char **argv, int *status, int index, char **nenv)
{
	char *HOME, *OLDPWD, cwd[1024];

	getcwd(cwd, 1024);
	if (!cmd[1])
	{
		HOME = _getenv("HOME");
		if (!HOME)
		{
			arrClean(cmd);
			(*status) = 0;
			return;
		}
		chdir(HOME), _setenv_wd("PWD", HOME, nenv);
		free(HOME);
	} else if (_strcmp(cmd[1], "-") == 0)
	{
		OLDPWD = _getenv("OLDPWD");
		if (!OLDPWD)
		{
			write(STDOUT_FILENO, cwd, _strlen(cwd));
			write(STDOUT_FILENO, "\n", 1);
			arrClean(cmd), (*status) = 0;
			return;
		}
		chdir(OLDPWD), _setenv_wd("PWD", OLDPWD, nenv);
		write(STDOUT_FILENO, OLDPWD, _strlen(OLDPWD));
		write(STDOUT_FILENO, "\n", 1);
	} else if (chdir(cmd[1]) == -1)
		_printcderr(argv[0], index, cmd[1]);
	else
		_setenv_wd("PWD", cmd[1], nenv);

	arrClean(cmd), (*status) = 0;
	_setenv_wd("OLDPWD", cwd, nenv);
}
