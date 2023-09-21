#include "shell.h"

/**
 * custom_getline_read - Reads input
 * @fd: file descriptor
 * @buffer: memory location
 * @buffer_size: memory size
 *
 * Return: number of characters read
 *
 */

#define INITIAL_BUFFER_SIZE 128

static ssize_t custom_getline_read(int fd, char **buffer, size_t *buffer_size)
{
	if (*buffer == NULL || *buffer_size == 0)
	{
		*buffer_size = INITIAL_BUFFER_SIZE;
		*buffer = (char *)malloc(*buffer_size);
		if (*buffer == NULL)
		{
			return (-1);
		}
	}
	ssize_t bytesRead = 0;
	ssize_t totalBytesRead = 0;
	char *buf;
	buf = *buffer;
	while (1)
	{
		if (totalBytesRead >= *buffer_size)
		{
			*buffer_size *= 2;
			char *newBuffer = (char *)realloc(buf, *buffer_size);
			if (newBuffer == NULL)
			{
				free(buf);
				return -1;
			}
			buf = newBuffer;
			*buffer = buf;
		}

        ssize_t result = read(fd, buf + totalBytesRead, 1);

        if (result == 0) {
            // End of file
            if (totalBytesRead == 0) {
                return 0; // No data read
            }
            break;
        } else if (result == -1) {
            if (totalBytesRead == 0) {
                return -1; // Read error
            }
            break;
        }

        totalBytesRead++;
        bytesRead++;

        if (buf[totalBytesRead - 1] == '\n') {
            break;
        }
    }

    return bytesRead;
}

ssize_t custom_getline(int fd, char **lineptr) {
    static char *buffer = NULL;
    static size_t buffer_size = 0;
    ssize_t bytesRead;

    if (lineptr == NULL || fd < 0) {
        return -1; // Invalid input
    }

    bytesRead = custom_getline_read(fd, &buffer, &buffer_size);

    if (bytesRead > 0) {
        buffer[bytesRead] = '\0'; // Null-terminate the line
        *lineptr = buffer;
    } else if (bytesRead == 0) {
        free(buffer);
        buffer = NULL;
        buffer_size = 0;
    }

    return bytesRead;
}
