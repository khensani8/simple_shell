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
	int xstat = 0;

	signal(SIGINT, SIG_IGN);
	path = _getenv("PATH");

	while (1)
	{
		if (isatty(STDIN_FILENO))
			/* prompt */
			write(STDOUT_FILENO, "($) ", 4);

		line = rd_line();
		if (*line != '\0')
		{
			tok = split_line(line);
			if (tok == NULL)
			{
				free(line);
				continue;
			}

			fullpath = findpath(tok, path, pcpy);
			if (handle_builtin(tok, line, xstat) == 1)
				continue;
			xstat = process(tok, line, fullpath);
		}
		else
			free(line);
	}
	return (0);
}
