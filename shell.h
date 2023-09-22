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

/* MACROS */
#define DELIM " \n\t"
#define PROMPT "$ "

/* GLOBAL VARIABLE */
extern char **environ;

/* STRUCTURES */

/**
 * struct dir_list - singly linked list.
 * @dir: name of directory
 * @next: Pointer to next node
 */
typedef struct dir_list
{
	char *dir;
	struct dir_list *next;
} dir_list;

/**
 * struct file_input - file input data
 * @lines: file input line
 * @length: number of lines in the input file
 * Description: File input data
 */
typedef struct file_input
{
	char *lines[1024];
	int length;
} file_input;

/**
 * struct builtins - builtin and its function
 * @builtin: builtin name
 * @f: function to handle builtin
 * Description: custom shell builtins
 */
typedef struct builtins
{
	char *builtin;
	void (*f)(char **, char **, int*, int, char**);
} builtins;

/* HELFPER FUNCTIONS */
int _exec(char **cmd, char **argv, int index);
char *_getpath(char *cmd);
dir_list *list_dir_tree(void);
char *_getenv(char *env_var);
char *_getline(void);
char **line_split(char *line);

/* BUILTINS */
int is_cmd_builtin(char *cmd);
void _handle_builtins(char **cmd, char **argv, int *status, int index,
		char **nenv);
void _exit_shell(char **cmd, char **argv, int *status, int index,
		char **nenv);
void _printenv(char **cmd, char **argv, int *status, int index,
		char **nenv);
/* BUILTINS2 */
void _setenv(char **cmd, char **argv, int *status, int index, char **nenv);
void _unsetenv(char **cmd, char **argv, int *status, int index, char **nenv);
void _cdir(char **cmd, char **argv, int *status, int index, char **nenv);

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

/* UTILS2 */
void var_change(char **cmd, int status);
void handle_comment(char ***cmd);
void _printcderr(char *name, int index, char *path);
void _setenv_wd(char *key, char *value, char **nenv);

/* FILE_INPUT */
file_input _getfile(char **argv);

/* LINKED_LIST */
dir_list *add_node_end(dir_list **head, const char *str);
void free_dir_list(dir_list *head);

#endif
