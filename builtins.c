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

/**
 * _cd - changes the current working directory of the shell
 * @args: array of arguments
 * Return: ...
 */
void _cd(char **args)
{
	char *dir = args[1];
	int ret;

	/* If no argument is provided, change to HOME directory */
	if (dir == NULL)
	{
		dir = _getenv("HOME");
		if (dir == NULL)
		{
			perror("hsh");
			return;
		}
	}

	ret = chdir(dir);
	if (ret == -1)
	{
		perror("cd");
	}
}
