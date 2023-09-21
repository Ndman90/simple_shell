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
void execute_command(char *command);
void interactive(void);
void non_interactive(void);
void builtin_cmd(char *command);

/* STRING FUNCTIONS */
char *_strcpy(char *dest, char *src);
int _strlen(char *str);
char *_strdup(char *str);
char *_strcat(char *dest, const char *src);
char *_strchar(char *str, char ch);
int _strcmp(char str[], const char *delim);
char *_strtok(char *str, char *delim);
void _printf(char *str, int stream);
void _setenv(char *name, char *value);
void _printenv()

#endif /*SHELL_H*/
