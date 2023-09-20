#include "shell.h"

/**
 * _strcpy - copies string pointed to by src
 * @dest: destinstion
 * @src: source
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i, len;

	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	for (i = 0; i < len; i++)
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
