#include "shell.h"

/**
 * main - Shell main function
 * @argc: Argument count
 * @argv: Arguments
 *
 * Return: 0 Always (Success).
 */
int main(int argc, char **argv)
{
	char *line = NULL, **cmd = NULL, *nenv = NULL;
	int status = 0, index = 0, sh_loop = 1, i = 0;
	file_input data_file;

	if (argc == 2)
	{
		data_file = _getfile(argv);
		sh_loop = data_file.length;
	}
	while (sh_loop)
	{
		if (argc == 2)
		{
			sh_loop--;
			line = data_file.lines[i++];
		} else
			line = _getline();
		if (!line)
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(nenv);
			return (status);
		}
		index++;
		cmd = line_split(line);
		handle_comment(&cmd);
		if (!cmd)
			continue;
		var_change(cmd, status);

		if (is_cmd_builtin(cmd[0]))
			_handle_builtins(cmd, argv, &status, index, &nenv);
		else
			 status = _exec(cmd, argv, index);
	}
	return (0);
}
