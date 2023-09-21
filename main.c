#include "shell.h"

/**
 * main - Shell main function
 * @ac: Argument count
 * @argv: Arguments
 *
 * Return: 0 Always (Success).
 */
int main(int ac, char **argv)
{
	char *line = NULL, **cmd = NULL;
	int stat = 0;
	(void) ac;

	while (1)
	{
		line = readLine();
		if (!line) /* Reach EOF Ctrl + D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (stat);
		}

		cmd = tknizer(line);
		if (!cmd)
			continue;

		stat = _exec(cmd, argv);
	}
}
