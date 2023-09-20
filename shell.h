#ifndef _SHELL_H_
#define _SHELL_H_

#include <fcntl.h>
#include <math.h>
#include <dirent.h>
#include <limits.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdarg.h>
#include <errno.h>


void executer(char **argv);
char *get_location(char *command);
char *trim_whitespace(const char *line);
void buffer_clearer(void);
void prompt(void);
int execute_with_pipe(char **command, int prev_pipe_fd[2]);
void execute_command(char *command);
void interactive(void);
void non_interactive(void);

/* HELPER FUNCTIONS */
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
void _printf(char *str, int stream);

#endif /*SHELL_H*/
