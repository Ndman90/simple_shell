#include "shell.h"

/**
 * trim_whitespace - function that returns new line with space removed
 * @line: to check against
 *
 * Return: newline without space duplicates
 */

char *trim_whitespace(const char *line)
{
	int i, left, right, trimmedLength, length = 0;
	char *result = NULL;

	while (line[length] != '\0')
	{
		length++;
	}
	left = 0;
	while (line[left] == ' ' || line[left] == '\t')
	{
		left++;
	}

	if (left == length)
	{
		result = (char *)malloc(1);
		if (result)
		{
			result[0] = '\0';
		}
		return (result);
	}

	right = length - 1;
	while (line[right] == ' ' || line[right] == '\t')
	{
		right--;
	}

	trimmedLength = right - left + 1;
	result = (char *)malloc(trimmedLength + 1);

	if (result)
	{
		for (i = 0; i < trimmedLength; i++)
		{
			result[i] = line[left + i];
		}
		result[trimmedLength] = '\0';
	}
	return (result);
}
