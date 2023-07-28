#include "shell.h"

/**
 * handle_builtin - executes builtins
 * @cmd: argument entered
 * @line: ...
 * @xstat: exit status
 * Return: builtin to execute
 */
int handle_builtin(char **cmd, char *line, int xstat)
{
	if (!cmd[0])
		return (0);
	if (_strcmp(cmd[0], "exit") == 0)
	{
		free_cmd(cmd);
		free(cmd);
		free(line);
		exit(xstat);
	}
	if (_strcmp(cmd[0], "env") == 0)
	{
		print_env();
		free_cmd(cmd);
		free(cmd);
		free(line);
		return (1);
	}
	else
		return (0);
}
