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
	pid_t child = fork();
	int status;

	if (child == 0)
	{
		if (execve(path, ar, environ) == -1)
		{
			perror("hsh");
			exit(EXIT_FAILURE);
		}
	}
	else if (child < 0)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}
	else
		wait(&status);

	return (0);
}
