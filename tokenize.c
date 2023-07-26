#include "shell.h"
/**
 * split_line - Split a string into tokens.
 *
 * @line: The input string to be split.
 *
 * Return:...
 */

char **split_line(char *line)
{
	int i, bufsize;
	char *delim, *tok;
	char **toks;

	bufsize = 1024;
	delim = " \t\n\r\a";
	toks = malloc(bufsize * sizeof(char *));

	if (toks == NULL)
	{
		perror("hsh");
		exit(EXIT_FAILURE);
	}

	tok = strtok(line, delim);

	i = 0;
	while (tok != NULL)
	{
		toks[i] = tok;
		i++;

		if (i >= bufsize)
		{
			bufsize += 1024;
			toks = realloc(toks, bufsize * sizeof(char *));
		}
		tok = strtok(NULL, delim);
	}
	toks[i] = NULL;

	return (toks);
}
