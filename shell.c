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

	while (1)
	{
		if (isatty(STDIN_FILENO))
			/* prompt */
			write(STDOUT_FILENO, "($) ", 4);

		line = rd_line();
		tok = split_line(line);

		path = getenv("PATH");
		fullpath = findpath(tok[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tok[0];
		if (tok[0] != NULL)
			process(fullpath, tok);

		free(line);
		free(tok);
	}

	return (0);
}
