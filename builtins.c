#include "shell.h"

/**
 * print_env - print environment
 * Return: ...
 */
int print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 * shell_exit - exits the shell
 */
void shell_exit(char **ar)
{
	int status = 0;

	if (ar[1] != NULL)
		status = atoi(ar[1]);
	/* Perform any cleanup or saving state here if necessary */
	exit(status);
}
