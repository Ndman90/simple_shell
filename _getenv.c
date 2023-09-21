#include "shell.h"

/**
 * _getenv - Searches the environment
 * @env_var: Variable argument
 *
 * Return: Pointer to corresponding value
 */
char *_getenv(char *env_var)
{
	char *tmp, *key, *val, *env;
	int i;

	for (i = 0; environ[i]; i++)
	{
		tmp = _strdup(environ[i]);
		key = strtok(tmp, "=");
		if (_strcmp(key, env_var) == 0)
		{
			val = strtok(NULL, "\n");
			env = _strdup(val);
			free(tmp);
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}
