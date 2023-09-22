#include "shell.h"

/**
 * _getline - Prints a prompt and gets input from stdin
 * Return: Input string is success, otherwise, NULL
 */
char *_getline(void)
{
	char *line = NULL;
	size_t size = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, PROMPT, 2);

	if (getline(&line, &size, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	return (line);
}
