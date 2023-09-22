#include "shell.h"

/**
 * is_positive - check positive argument
 * @str: Argument
 *
 * Return: Always 0
 */
int is_positive(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * _str_to_int - converts string to integer
 * @str: String to be converted
 *
 * Return: Converted string
 */
int _str_to_int(char *str)
{
	int i, n = 0;

	for (i = 0; str[i]; i++)
	{
		n *= 10;
		n += (str[i] - '0');
	}
	return (n);
}
