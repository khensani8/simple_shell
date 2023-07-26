#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

typedef struct builtin_t
{
	char *cmd;
	int (*ptr)(void);
} builtin_t;

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
int builtins_count(builtin_t builtin[]);
int handle_builtins(char **arg);

#endif 
