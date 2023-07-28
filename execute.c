#include "shell.h"

/**
 * process - Execute a shell command in a new process
 *
 * @ar: array of arguments
 * @path: path to the executable file
 *
 * Return:...
 */

int process(char *path, char **ar)
{
	pid_t child;
	int status = 0; 

	child = fork();
	if (child == 0)
	{
		if (execve(path, ar, environ) == -1)
		{
			perror("hsh");
			free(ar);
			free(path);
			exit(EXIT_FAILURE);
		}
	}
	else if (child == -1)
	{
		perror(ar[0]);
		free(ar);
	}
	else
	{
		wait(&status);
		return (status);
	}

	return (0);
}
