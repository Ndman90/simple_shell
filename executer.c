#include "shell.h"

/**
 * executer - function that excute commands
 * that's not part of builtins
 *
 * @argv: command to be executed
 * Return: Nothing(void)
 */

void executer(char **argv) {
    char *command = NULL, *actual_command = NULL;
    pid_t child_ID;
    int status;

    if (argv) {
        /* Get the command */
        command = argv[0];

        /* Generate the path to this command before passing it to execve */
        actual_command = get_location(command);
        
        if (actual_command == NULL) {
            perror("Error: Failed to get command location");
            return;
        }
        
        child_ID = fork();
        if (child_ID < 0) {
            perror("Error: Forking failed");
            exit(EXIT_FAILURE);
        } else if (child_ID == 0) {
            if (execve(actual_command, argv, NULL) == -1) {
                perror("Error: Execution failed");
                exit(EXIT_FAILURE);
            }
        } else {
            // Parent process
            waitpid(child_ID, &status, 0); // Wait for the child to finish
        }
        
        free(actual_command); // Free memory allocated for actual_command
    }
}

