#include "shell.h"

/**
 * handle_builtins - executes builtins
 *
 * @arg: argument entered
 *
 * Return: builtin to execute
 */
int handle_builtins(char **arg)
{
	builtin_t builtin[] = {
		{"exit", hsh_exit},
		{"env", print_env},
		{NULL, NULL}
	};
	int i, n;

	/* empty command */
	if (arg[0] == NULL)
		return (1);

	n = builtins_count(builtin);
	for (i = 0; i < n; i++)
	{
		if (strcmp(arg[0], builtin[i].cmd) == 0)
			return ((builtin[i].ptr)());
	}
	return (0);
}

/**
 * builtin_count - ..
 * builtin: builtin to be tallied
 * Return: builtin count
 */
int builtins_count(builtin_t builtin[])
{
	unsigned int i;

	i = 0;
	while (builtin[i].cmd != NULL)
		i++;

	return (i);
}
