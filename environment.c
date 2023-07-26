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
