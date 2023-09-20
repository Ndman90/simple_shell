#include "shell.h"

/**
 * buffer_clearer - clears the input buffer
 *
 * Return: nothing
 */

void buffer_clearer(void)
{
	int c;

	while ((c = getchar()) != '\n' && c != EOF)
	{
		fflush(stdin);
	}
}


