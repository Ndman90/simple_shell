#include "shell.h"

/**
 * non_interactive - function that handles commands
 * in non-interactive mode  and calls other functions
 *
 * Return: Nothing(void)
 */

void non_interactive(void)
{
	char *buffer = NULL, *buffer_copy = NULL,
	     *trimmed_string = NULL, *token_str = NULL;
	size_t n = 0;
	ssize_t num_chars;
	const char *delim = " \n";
	int i, num_tokens = 0;
	char **token = NULL;
	bool pipe = false;

	while (1 && !pipe)
	{
		pipe = true;
		prompt();
		num_chars = getline(&buffer, &n, stdin);

		if (num_chars == -1)
		{
			_printf("exit\n", STDERR_FILENO);
			break;
		}
		buffer_copy = malloc(sizeof(char) * num_chars);
		if (!buffer_copy)
		{
			perror("memory allocation error");
			exit(0);
		}
		_strcpy(buffer_copy, buffer);
		trimmed_string = trim_whitespace(buffer_copy);
		for (i = 0; i < num_chars; i++)
		{
			if (trimmed_string[i] == '\n')
				trimmed_string[i] = '\0';
		}
		token_str = strtok(trimmed_string, delim);
		while (token_str)
		{
			num_tokens++;
			token_str = strtok(NULL, delim);
		}
		num_tokens++;
		token = malloc(sizeof(char *) * (num_tokens + 1));
		if (!token)
		{
			perror("memory allocation error");
			exit(0);
		}
		token_str = strtok(buffer_copy, delim);
		i = 0;

		while (token_str)
		{
			token[i] = token_str;
			i++;
			token_str = strtok(NULL, delim);
		}
		token[i] = NULL;
		executer(token);
		free(token);
		free(trimmed_string);
	}
	free(buffer);
}
