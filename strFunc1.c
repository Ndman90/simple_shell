#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @str1: First string
 * @str2: Second string
 *
 * Return: 0
 */
int _strcmp(char *str1, char *str2)
{
	int cmp;

	cmp = (int)*str1 - (int)*str2;
	while (*str1)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
		cmp = (int)*str1 - (int)*str2;
	}
	return (cmp);
}

/**
 * _strlen - Returns length of a string
 * @str: String argument
 *
 * Return: length of string
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcat - Concatenates two strings
 * @dest: first argument
 * @src: second argment
 *
 * Return: Concatenated string
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest;

	while (*ptr)
		ptr++;

	while (*src)
	{
		*ptr = *src;
		ptr++;
		src++;
	}
	*ptr = *src;

	return (dest);
}

/**
 * _strdup - Duplicates string to pointer
 * @str: String argument
 *
 * Return: Pointer
 */
char *_strdup(const char *str)
{
	char *ptr;
	int i, len = 0;

	if (!str)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str -= len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (i = 0; i <= len; i++)
		ptr[i] = str[i];
	return (ptr);
}

/**
 * _strcpy - Copies string
 * @dest: First argument
 * @src: Second argument
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';

	return (dest);
}
