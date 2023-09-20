#include "shell.h"

/**
 * prompt - function that asks
 * a user to enter a command
 *
 * Return: Nothing (void)
 */
void prompt(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
}
