#include "shell.h"

/**
 * main - initializes shell and runs
 *
 * Return: Always 0
 */
int main(void)
{
	char *line = NULL, **tok;
	char *path, *fullpath, *pcpy = NULL;

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

		fullpath = findpath(tok, path, pcpy);
		if (handle_builtin(tok, line) == 1)
			continue;
		else
			process(tok, line, fullpath);

		free(line);
		free(tok);
	}
	free(fullpath);
	return (0);
}
