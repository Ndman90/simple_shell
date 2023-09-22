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
	int status = 0, index = 0;
	(void) ac;

	while (1)
	{
		line = readLine();
		if (!line) /* Reach EOF Ctrl + D */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			return (status);
		}
		index++;

		cmd = tknizer(line);
		if (!cmd)
			continue;

		if (is_cmd_builtin(cmd[0]))
			_handle_builtins(cmd, argv, &status, index);
		else
			 status = _exec(cmd, argv, index);
	}
}
