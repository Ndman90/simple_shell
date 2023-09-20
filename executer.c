#include "shell.h"

/**
 * executer - function that execute commands
 * @argv: command to be executed
 */

void executer(char **argv)
{
	char *command = NULL, *actual_command = NULL;
	pid_t child_ID;
	int status;

	if (argv)
	{
		command = argv[0];
		actual_command = get_location(command);

		if (!actual_command)
		{
			perror("Error: Failed to get command location");
			return;
		}
		child_ID = fork();
		if (child_ID < 0)
		{
			perror("Error: Forking failed");
			exit(EXIT_FAILURE);
		} else if (child_ID == 0)
		{
			if (execve(actual_command, argv, NULL) == -1)
			{
				perror("Error: Execution failed");
				exit(EXIT_FAILURE);
			}
		} else
			waitpid(child_ID, &status, 0);

		free(actual_command);
	}
}

