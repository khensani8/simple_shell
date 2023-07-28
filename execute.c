#include "shell.h"

/**
 * process - Execute a shell command in a new process
 *
 * @ar: array of arguments
 * @line: ptr to input
 * @fullpath: path to the executable file
 *
 * Return:...
 */
int process(char **ar, char *line, char *fullpath)
{
	pid_t child;
	int status, exitstat;

	child = fork();
	if (child == -1)
	{
		perror("hsh");
		exit(1);
	}
	if (child == 0)
	{
		if (execve(fullpath, ar, environ) == -1)
		{
			perror(ar[0]);
			free_cmd(ar);
			free(ar);
			free(line);
			exit(127);
		}
	}
	wait(&status);

	if (WIFEXITED(status))
		exitstat = WEXITSTATUS(status);
	free_cmd(ar);
	free(ar);
	free(line);
	return (exitstat);
}
