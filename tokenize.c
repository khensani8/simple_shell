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

	bufsize = 64;
	delim = " \t\n\r\a";
	toks = malloc(bufsize * sizeof(char *));
	i = 0;
	tok = strtok(line, delim);

	while (tok != NULL)
	{
		toks[i] = tok;
		i++;

		if (i >= bufsize)
		{
			bufsize += 64;
			toks = realloc(toks, bufsize * sizeof(char *));
		}
		tok = strtok(NULL, delim);
	}
	toks[i] = NULL;
	return (toks);
}
