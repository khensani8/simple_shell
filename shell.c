#include "shell.h"

/**
 * main - initializes shell and runs
 *
 * @argc: number of command-line arguments
 * @argv: array of command-line arguments
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *line, **tok;
	char *path, *fullpath;

	(void) argc;
	(void) argv;

	while (1)
	{
		/* prompt */
		write(STDOUT_FILENO, "($) ", 4);
		line = rd_line();
		tok = split_line(line);
		if (tok[0] != NULL)
		{
			if (strcmp(tok[0], "exit") == 0)
			{
				free(tok);
				free(line);
				break;
			}
		}
		if (tok[0] == NULL)
			continue;

		path = getenv("PATH");
		fullpath = findpath(tok[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tok[0];

		process(fullpath, tok);

		free(line);
		free(tok);
		free(fullpath);
	}
	return (0);
}
