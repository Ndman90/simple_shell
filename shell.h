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

char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
char *_strcat(char *dest, char *src);
int _strlen(char *str);
int _strcmp(char *str1, char *str2);

void arrClean(char **arr);
int _exec(char **cmd, char **argv);

#endif
