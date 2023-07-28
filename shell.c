#include "shell.h"

/**
 * main - initializes shell and runs
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL, **tok;
	char *path, *fullpath;

	signal(SIGINT, SIG_IGN);
	path = _getenv("PATH");

	while (1)
	{
		if (isatty(STDIN_FILENO))
			/* prompt */
			write(STDOUT_FILENO, "($) ", 4);

		line = rd_line();
		tok = split_line(line);
		if (tok == NULL)
		{
			free(line);
			continue;
		}

		fullpath = findpath(tok[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tok[0];
		if (handle_builtin(tok, line) == 1)
			continue;
		else
			process(fullpath, tok);
/*		if (_strcmp(tok[0], "exit") == 0)
		{
			free(line);
			free(tok);
			shell_exit();
		}

		process(fullpath, tok);
*/
		free(line);
		free(tok);
	}
	free(fullpath);
	return (0);
}
