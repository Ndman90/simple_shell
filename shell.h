#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>

#define DELIM " \t\n"
extern char **environ;

char *readLine(void);
char **tknizer(char *line);
int _exec(char **cmd, char **argv, int index);
char *_getpath(char *cmd);
char *_getenv(char *env_var);

/* BUILTINS */
int is_cmd_builtin(char *cmd);
void _handle_builtins(char **cmd, char **argv, int *status, int index);
void _exit_shell(char **cmd, char **argv, int *status, int index);
void _printenv(char **cmd, int *status);

/* STRING FUNCTIONS */
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);

/* UTILS */
void arrClean(char **arr);
void rev_str(char *str, int len);
char *_atoi(int n);
void _printerr(char *name, char *cmd, int index);
int is_positive(char *str);
int _str_to_int(char *str);

#endif
