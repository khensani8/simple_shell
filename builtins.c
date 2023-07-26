#include "shell.h"

/**
 * hsh_exit - exits shell
 * Return: void
 */
int hsh_exit(void)
{
	return (-1);
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
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
	return (0);
}

/**
 * hsh_cd - change directories
 * Return: ...
 *
int hsh_cd(char **ar)
{
	if (ar[1] == NULL)
		perror("hsh");
	else
	{
		if (chdir(ar[1]) != 0)
			perror("hsh");
	}

	return (1);
}*/
