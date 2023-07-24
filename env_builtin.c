#include "shell.h"

/**
 * print_env - prints the current environment
 *
 */

void print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

/**
 * handle_builtin - handles built-in commands
 *
 * @ar: arguments
 *
 * Return: 1 if rhe command is a built-in, 0 otherwise
 */

int handle_builtin(char **ar)
{
	if (ar[0] != NULL)
	{
		if (strcmp(ar[0], "env") == 0)
		{
			print_env();
			return (1);
		}
	}
	return (0);
}


