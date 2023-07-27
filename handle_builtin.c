#include "shell.h"

/**
 * handle_builtin - executes builtins
 * @cmd: argument entered
 * Return: builtin to execute
 */
int handle_builtin(char **cmd)
{
	if (!cmd[0])
		return (0);
	if (!_strcmp(cmd[0], "exit"))
		hsh_exit(cmd);
	else if (!_strcmp(cmd[0], "env"))
		print_env();
	else
		return (0);
	return (1);
}

/**
 * check_builtin - checks for builtin
 * @cmd: split line
 * Return: 1 if cmd excuted, 0 if cmd is not executed
 */
int check_builtin(char **cmd)
{
	if (handle_builtin(cmd))
		return (1);
	else if (**cmd == '/')
	{
		process(cmd[0], cmd);
		return (1);
	}
	return (0);
}
