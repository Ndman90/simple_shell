#include "shell.h"

/**
 * is_cmd_builtin - Checks if argument is a builtin command
 * @cmd: command
 *
 * Return: Always 0
 */
int is_cmd_builtin(char *cmd)
{
	char *builtin_cmd[] = {
		"exit", "env", "setenv",
		"cd", NULL
	};
	int i;

	for (i = 0; builtin_cmd[i]; i++)
	{
		if (_strcmp(cmd, builtin_cmd[i]) == 0)
			return (1);
	}
	return (0);
}

/**
 * _handle_builtins - Builtin handler
 * @cmd: builtin command
 * @argv: arguments
 * @status: exit status
 * @index: index of the command
 * @nenv: new environment variable
 *
 * Return: 1 if command is a builtin, 0 otherwise.
 */
void _handle_builtins(char **cmd, char **argv, int *status,
		int index, char **nenv)
{
	int i;
	builtins command[] = {
		{"exit", _exit_shell},
		{"env", _printenv},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{"cd", _cdir},
		{NULL, NULL}
	};

	for (i = 0; command[i].builtin; i++)
	{
		if (_strcmp(command[i].builtin, cmd[0]) == 0)
		{
			command[i].f(cmd, argv, status, index, nenv);
			break;
		}
	}
}

/**
 * _exit_shell - Exit shell terminal
 * @cmd: Builtin command
 * @argv: arguments
 * @status: exit status
 * @index: index of the command
 * @nenv: new environment variable
 */
void _exit_shell(char **cmd, char **argv, int *status, int index, char **nenv)
{
	int exit_value = (*status);
	char *idx, err_msg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (is_positive(cmd[1]))
		{
			exit_value = _str_to_int(cmd[1]);
		} else
		{
			idx = _atoi(index);

			write(STDERR_FILENO, argv[0], _strlen(argv[0]));
			write(STDERR_FILENO, ": ", 2);
			write(STDERR_FILENO, idx, _strlen(idx));
			write(STDERR_FILENO, err_msg, _strlen(err_msg));
			write(STDERR_FILENO, cmd[1], _strlen(cmd[1]));
			write(STDERR_FILENO, "\n", 1);
			free(idx);
			arrClean(cmd);
			free((*nenv));
			(*status) = 2;
			return;
		}

	}
	arrClean(cmd);
	free((*nenv));
	exit(exit_value);
}

/**
 * _printenv - Print environment variables to stdout
 * @cmd: builtin command
 * @argv: arguments
 * @status: exit status
 * @index: index of command
 * @nenv: new environment variable
 */
void _printenv(char **cmd, char **argv, int *status, int index, char **nenv)
{
	int i;
	(void) argv;
	(void) index;
	(void) nenv;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	(*status) = 0;
	arrClean(cmd);
}
