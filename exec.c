#include "shell.h"

/**
 * _exec - Executes command
 * @cmd: command passed
 * @argv: arguments
 *
 * Return: 0
 */
int _exec(char **cmd, char **argv)
{
	pid_t child;
	int stat;

	child = fork();
	if (child == 0)
	{
		if (execve(cmd[0], cmd, environ) == -1)
		{
			perror(argv[0]);
			arrClean(cmd);
			exit(0);
		}
	} else
	{
		waitpid(child, &stat, 0);
		arrClean(cmd);
	}
	return (WEXITSTATUS(stat));
}
