#include "shell.h"

/**
 * handle_builtin - executes builtins
 * @cmd: argument entered
 * Return: builtin to execute
 */
int handle_builtin(char **cmd)
{
	if (_strcmp(*cmd, "exit") == 0)
	{
		shell_exit();
		/*hsh_exit();*/
		exit(EXIT_SUCCESS);
	}

	if (_strcmp(*cmd, "env") == 0)
	{
		print_env();
		return (1);
	}

	return (0);
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
