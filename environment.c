#include "shell.h"

/**
 * _getenv - ...
 * @envp: ...
 * Return: ...
 */
char *_getenv(char *envp)
{
	int status, i, j;

	i = 0;
	while (environ[i])
	{
		status = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != envp[j])
				status = 0;
		}
		if (status == 1)
			break;
		i++;
	}
	return (&environ[i][j + 1]);
}

/**
 * _setenv - Set or modify an environment variable
 *
 * @variable: The name of the environment variable to set/modify
 * @value: The value to assign to the environment variable
 *
 * Return: 0 on success, -1 on failure
 */
int _setenv(const char *variable, const char *value)
{
	int ret = setenv(variable, value, 1);

	if (variable == NULL || variable[0] == '\0' || value == NULL)
	{
		char *error_msg = "Invalid argument for setenv\n";

		write(STDERR_FILENO, error_msg, strlen(error_msg));
		return (-1);
	}
	if (ret != 0)
	{
		char *error_msg = "setenv failed\n";

		write(STDERR_FILENO, error_msg, strlen(error_msg));
		return (-1);
	}
	return (0);
}

/**
 * _unsetenv - Unset an environment variable
 *
 * @name: The name of the environment variable to unset
 *
 * Return: 0 on success, -1 on failure
 */
int _unsetenv(const char *name)
{
	int ret = unsetenv(name);

	if (name == NULL || name[0] == '\0')
	{
		char *error_msg = "Invalid argument for unsetenv\n";

		write(STDERR_FILENO, error_msg, strlen(error_msg));
		return (-1);
	}
	if (ret != 0)
	{
		char *error_msg = "unsetenv failed\n";

		write(STDERR_FILENO, error_msg, strlen(error_msg));
		return (-1);
	}
	return (0);
}

