#include "shell.h"

/**
 * _exec - Executes command
 * @cmd: command passed
 * @index: index location of argument
 * @argv: arguments
 *
 * Return: 0
 */
int _exec(char **cmd, char **argv, int index)
{
	char *f_cmd;
	pid_t child;
	int status;

	f_cmd = _getpath(cmd[0]);
	if (!f_cmd)
	{
		_printerr(argv[0], cmd[0], index);
		arrClean(cmd);
		return (127);
	}

	child = fork();
	if (child == 0)
	{
		if (execve(f_cmd, cmd, environ) == -1)
		{
			free(f_cmd), f_cmd = NULL;
			arrClean(cmd);
		}
	} else
	{
		waitpid(child, &status, 0);
		arrClean(cmd);
		free(f_cmd), f_cmd = NULL;
	}
	return (WEXITSTATUS(status));
}
