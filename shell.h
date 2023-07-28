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

#define BUFSIZE 1024

/***** ENVIRONMENT *****/
extern char **environ;
char *_getenv(const char *envp);
int _setenv(const char *variable, const char *value);
int _unsetenv(const char *name);

/***** FUNCTIONS *****/
char *rd_line(void);
char **split_line(char *line);
int print_env(void);
int process(char **ar, char *line, char *fullpath);

/***** PATH *****/
/*char *findpath(char *cmd, char *fullpath, char *path);*/

/***** BUILT-INS *****/
void _cd(char **ar);
int handle_builtin(char **cmd, char *line);
void shell_exit(void);

/***** STRING FUNCTIONS *****/
char *_strcat(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strsep(char *str);

/**** FREE *****/
void free_tokens(char **toks);
void free_cmd(char **ar);

/* may remove soon */
char *pathconcat(char *buf, char **toks, char *tok);
int cmpPATH(const char *s1, const char *s2);
int _pathsep(char *str);
char *findpath(char **cmd, char *path, char *pcpy);
#endif
