#include "shell.h"

/**
 * _strchar - Locates a character in a string
 * @str: String to be searched
 * @ch: Character to be checked
 *
 * Return: Pointer to the first ocurence of ch in str
 */
char *_strchar(char *str, char ch)
{
	int i;

	for (i = 0; str[i] != ch && str[i] != '\0'; i++)
		;
	if (str[i] == ch)
		return (str + 1);
	else
		return (NULL);
}

/**
 * _strcmp - Compares characters of stringd
 * @str: Input string
 * @delim: Delimiter
 *
 * Return: 1 if equal, 0 otherwise
 */
int _strcmp(char str[], const char *delim)
{
	unsigned int i, j, k;

	for (i = 0, k = 0; str[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (str[i] == delim[j])
			{
				k++;
				break;
			}

		}
	}
	if (i == k)
		return (1);
	return (0);
}

/**
 * _strtok - Tokenizes a string
 * @str: String
 * @delim: Delimiter
 *
 * Return: The next available token
 */
char *_strtok(char *str, char *delim)
{
	static char *end, *is_split;
	char *start;
	unsigned int i, check;

	if (str)
	{
		if (_strcmp(str, delim))
			return (NULL);
		is_split = str;
		i = _strlen(str);
		end = &str[i];
	}
	start = is_split;
	if (start == end)
		return (NULL);

	for (check = 0; *is_split; is_split++)
	{
		if (is_split != start)
			if (*is_split && *(is_split - 1) == '\0')
				break;
		for (i = 0; delim[i]; i++)
		{
			if (*is_split == delim[i])
			{
				*is_split = '\0';
				if (is_split == start)
					start++;
				break;
			}
		}
		if (check == 0 && *is_split)
			check = 1;
	}
	if (check == 0)
		return (NULL);
	return (start);
}
