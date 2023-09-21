#include "shell.h"

/**
 * tknizer - Token
 * @line: line argument
 *
 * Return: Always 0
 */
char **tknizer(char *line)
{
	char *tkn = NULL, *tmp = NULL, **cmd = NULL;
	int iter = 0, i = 0;

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
		iter++;
		tkn = strtok(NULL, DELIM);
	}
	free(tmp), tmp = NULL;
	cmd = malloc(sizeof(char *) * (iter + 1));
	if (!cmd)
	{
		free(line), line = NULL;
		return (NULL);
	}
	tkn = strtok(line, DELIM);
	while (tkn)
	{
		cmd[i] = _strdup(tkn);
		tkn = strtok(NULL, DELIM);
		i++;
	}
	free(line), line = NULL, cmd[i] = NULL;
	return (cmd);
}
