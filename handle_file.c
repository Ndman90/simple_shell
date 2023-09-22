#include "shell.h"

/**
 * _getfile - get input from file
 * @argv: arguments
 * Return: a struct file input containing data
 */
file_input _getfile(char **argv)
{
	int _file, rd, i = 0;
	char buff[4096], *line = NULL;
	char msg[] = ": 0: Can't open ";
	file_input data_file;

	data_file.length = 0;
	_file = open(argv[1], O_RDONLY);
	if (_file == -1)
	{
		write(STDERR_FILENO, argv[0], _strlen(argv[0]));
		write(STDERR_FILENO, msg, _strlen(msg));
		write(STDERR_FILENO, argv[1], _strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(127);
	}
	rd = read(_file, buff, 4095);
	if (rd <= 0)
		return (data_file);
	buff[rd] = '\0';

	line = strtok(buff, "\n");
	while (line)
	{
		data_file.lines[i] = _strdup(line);
		line = strtok(NULL, "\n");
		i++;
		data_file.length++;
	}
	close(_file);
	return (data_file);
}
