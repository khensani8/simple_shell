#include "shell.h"

/**
 * handle_builtin - executes builtins
 * @cmd: argument entered
 * Return: builtin to execute
 */
int handle_builtin(char **cmd, char *line)
{
	if (!cmd[0])
		return (0);
	if (_strcmp(cmd[0], "exit") == 0)
	{
		free_cmd(cmd);
		free(cmd);
		free(line);
		exit(EXIT_SUCCESS);
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
