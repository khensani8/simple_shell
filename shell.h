#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

/***** ENVIRONMENT *****/
extern char **environ;
char *_getenv(char *envp);

/***** FUNCTIONS *****/
char *rd_line(void);
char **split_line(char *line);
int print_env(void);
int process(char *path, char **ar);

/***** PATH *****/
char *findpath(char *cmd, char *fullpath, char *path);

/***** BUILT-INS *****/
int hsh_exit(void);
int hsh_cd(char **ar);
int check_builtin(char **cmd);
int handle_builtin(char **cmd);
int change_dir(char **cmd, __attribute__((unused)) int st);

/***** STRING FUNCTIONS *****/
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);

#endif
