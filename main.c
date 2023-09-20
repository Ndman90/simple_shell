#include "shell.h"

/**
 * main - Entry point to shell program
 * @argc: Number of arguments passed into the shell executable.
 * @argv: Vector containing arguments passed.
 *
 * Return: 0 on success or 1 on failure.
 */
int main(__attribute__((unused)) int argc,
		__attribute__((unused)) char **argv)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive();
	} else
	{
		non_interactive();
	}

	return (0);
}
