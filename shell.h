#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *rd_line(void);
char **split_line(char *line);
int act(char **ar);

#endif 

