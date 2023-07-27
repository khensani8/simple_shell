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
void shell_exit(void)
{
	/* Perform any cleanup or saving state here if necessary */
	
	exit(EXIT_SUCCESS);
}

