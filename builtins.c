#include "shell.h"

/**
 * hsh_exit - exits shell
 * Return: void
 */
int hsh_exit(void)
{
	exit(0);
}

/**
 * print_env - print environment
 * Return: ...
 */
int print_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
