#include "shell.h"

/**
 * hsh_exit - exits shell
 * Return: void
 */
void hsh_exit(char **ar)
{
	int i = 0;

	if (ar[1] != NULL)
		i = atoi(ar[1]);
	free(ar);

	exit(i);
}

/**
 * print_env - print environment
 * Return: ...
 */
int print_env(void)
{
	int i = 0;

	while (environ[i])
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}
