#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

/***** ENVIRONMENT *****/
extern char **environ;

/***** FUNCTIONS *****/
char *rd_line(void);
char **split_line(char *line);

/***** EXECUTE *****/
int process(char *path, char **ar);

/***** PATH *****/
char *findpath(char *cmd, char *fullpath, char *path);

#endif 

