#include "shell.h"

/**
 * arrClean - Clears array input
 * @arr: argument
 */
void arrClean(char **arr)
{
	int i;

	if (!arr)
		return;
	for (i = 0; arr[i]; i++)
		free(arr[i]), arr[i] = NULL;

	free(arr), arr = NULL;
}

/**
 * _printerr - Prints error message to stdout
 * @name: first argument
 * @cmd: command argument
 * @index: index
 *
 * Return: 0
 */
void _printerr(char *name, char *cmd, int index)
{
	char *idx, err_msg[] = ": command not found\n";

	idx = _atoi(index);

	write(STDERR_FILENO, name, _strlen(name));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, idx, _strlen(idx));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, cmd, _strlen(cmd));
	write(STDERR_FILENO, err_msg, _strlen(err_msg));

	free(idx);
}

/**
 * _atoi - converts integer to string
 * @n: Integer to be converted
 *
 * Return: Pointer to string
 */
char *_atoi(int n)
{
	char _buff[20];
	int i = 0;

	if (n == 0)
		_buff[i++] = '0';
	else
	{
		while (n > 0)
		{
			_buff[i++] = (n % 10) + '0';
			n /= 10;
		}
	}
	_buff[i] = '\0';
	rev_str(_buff, i);

	return (_strdup(_buff));
}

/**
 * rev_str - Reverses string
 * @str: String to be reversed
 * @len: Length
 */
void rev_str(char *str, int len)
{
	char tmp;
	int start, end;

	start = 0;
	end = len - 1;

	while (start < end)
	{
		tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

