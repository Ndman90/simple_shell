#include "shell.h"

/**
 * interactive - function that handles commands
 * in interactive mode and calls other functions
 *
 * Return: Nothing(void)
 */

void interactive(void)
{
   char *buffer = NULL, *buffer_copy = NULL, *trimmed_string = NULL, *token_str = NULL;
  size_t n = 0;
  ssize_t num_chars;
  const char *delim = " \n";
  int i, num_tokens = 0;
  char **token = NULL;

    while (1)
    {
      prompt();
      num_chars = getline(&buffer, &n, stdin);
      
      if (num_chars == -1) {
            perror("exit\n");
            break; /* Exit the loop gracefully*/
        }

        /* allocate space for a copy of the lineptr */
        buffer_copy = malloc(sizeof(char) * num_chars);
        if (buffer_copy == NULL) {
            perror("memory allocation error");
            exit(0);
        }
        /* copy lineptr to lineptr_copy */
        strcpy(buffer_copy, buffer);

        trimmed_string = trim_whitespace(buffer_copy);

        /* Replace newline characters with null terminators */
        for (i = 0; i < num_chars; i++) {
            if (trimmed_string[i] == '\n')
                trimmed_string[i] = '\0';
        }

        /********** split the string (trimmed_string) into an array of words ********/
        /* calculate the total number of tokens */
        token_str = strtok(trimmed_string, delim);

        while (token_str != NULL) {
            num_tokens++;
            token_str = strtok(NULL, delim);
        }
        num_tokens++;

        /* Split the string (trimmed_string) into an array of words */
        token = malloc(sizeof(char *) * (num_tokens + 1));

        if (token == NULL) {
            perror("memory allocation error");
            exit(0);
        }

        token_str = strtok(buffer_copy, delim);
        i = 0;

        while (token_str != NULL) {
            token[i] = token_str;
            i++;
            token_str = strtok(NULL, delim);
        }

        token[i] = NULL; /* Null-terminate the token array*/

        /* Execute the command */
        executer(token);

        /* Free the memory allocated for the token array */
        free(token);
      
        /* Free the memory allocated for the trimmed string */
        free(trimmed_string);
    }

    /* Free up allocated memory */
    free(buffer);
}

