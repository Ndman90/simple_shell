#include "shell.h"

/**
 * line_split - Splits  a string into tokens
 * @line: String to be split
 *
 * Return: null terminating array of strings containing each word of line,
 * or NULL if line is only delimiters.
 */
char **line_split(char *line)
{
	int i = 0, j = 0;
	char *tkn, *tmp, **arr = NULL;

	if (!line)
		return (NULL);

	tmp = _strdup(line);
	tkn = strtok(tmp, DELIM);
	if (!tkn)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	while (tkn)
	{
		i++;
		tkn = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	arr = malloc(sizeof(char *) * (i + 1));
	if (!arr)
	{
		free(line), line = NULL;
		free(tmp), tmp = NULL;
		return (NULL);
	}
	tkn = strtok(line, DELIM);

	while (tkn)
	{
		arr[j++] = _strdup(tkn);
		tkn = strtok(NULL, DELIM);
	}
	arr[j] = NULL;
	free(line), line = NULL;

	return (arr);
}
