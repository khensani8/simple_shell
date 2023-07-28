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
		if (tok[0] == NULL)
		{
			free(line);
			free(tok);
			continue;
		}
		if (_strcmp(tok[0], "exit") == 0)
                {
                        free(line);
                        free(tok);
                        shell_exit();
                }
		if (_strcmp(tok[0], "env") == 0)
			print_env();

		path = _getenv("PATH");
		fullpath = findpath(tok[0], fullpath, path);
		if (fullpath == NULL)
			fullpath = tok[0];

		process(fullpath, tok);

		free(line);
		free(tok);
	}
	free(fullpath);
	return (0);
}
