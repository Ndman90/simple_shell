#include "shell.h"

/**
 * _strcpy - copies string pointed to by src
 * @dest: destinstion
 * @src: source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';

	return (dest);

}

/**
 * _printf - Prints string to stdout
 * @str: String to be printed
 * @stream: Stream to print out to
 *
 * Return: void, return nothing
 */
void _printf(char *str, int stream)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		write(stream, &str[i], 1);
}

/**
 * _strlen - counts string
 * @str: string to be counted
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
 * _strdup - duplicate to new memory location
 * @str: char
 *
 * Return: Pointer to newly allocated space in memory
 */
char *_strdup(char *str)
{
	char *dup_ptr;
	unsigned int i, j;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	dup_ptr = malloc(sizeof(char) * (i + 1));
	if (!dup_ptr)
		return (NULL);

	for (j = 0; j <= i; j++)
		dup_ptr[j] = str[j];

	return (dup_ptr);
}

/**
 * _strcat - concatenates two strings
 * @src: First string argument
 * @dest: Second string argument
 *
 * Return: Pointer of an array of characters
 */
char *_strcat(char *dest, const char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
		;
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
