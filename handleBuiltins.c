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
 * @cmd: First argument
 * @argv: Second argument
 * @status: Third argument
 * @index: Fourth argument
 */
void _handle_builtins(char **cmd, char **argv, int *status, int index)
{
	if (_strcmp(cmd[0], "exit") == 0)
		_exit_shell(cmd, argv, status, index);
	else if (_strcmp(cmd[0], "env") == 0)
		_printenv(cmd, status);
}

/**
 * _exit_shell - Exit shell terminal
 * @cmd: First argument
 * @argv: Second argument
 * @status: Third argument
 * @index: Fourth argument
 */
void _exit_shell(char **cmd, char **argv, int *status, int index)
{
	int value = (*status);
	char *idx, err_msg[] = ": exit: Illegal number: ";

	if (cmd[1])
	{
		if (is_positive(cmd[1]))
		{
			value = _str_to_int(cmd[1]);
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
			(*status) = 2;
			return;
		}

	}
	arrClean(cmd);
	exit(value);
}

/**
 * _printenv - Print environment path to stdout
 * @cmd: Argument
 * @status: Argument
 */
void _printenv(char **cmd, int *status)
{
	int i;

	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
	arrClean(cmd);
	(*status) = 0;
}
