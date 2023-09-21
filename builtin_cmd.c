#include "shell.h"

/**
 * builtin_cmd - function that takes command
 * and print the commands information
 *
 * @command: command to print its information
 * Return: Nothing
 */

void builtin_cmd(char *command)
{
	if (_strcmp(command, "exit") == 0)
	{
		_printf("exit\n");
		exit(0);
	}
	else
	{
		perror("Error:");
		return;
	}
}
