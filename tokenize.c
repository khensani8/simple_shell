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
	int i = 0, count = 0;
	char *tok, **toks;
	char *delim = " \t\n";
	
	count = _strsep(line);
	if (!count)
		return (NULL);

	toks = malloc((count + 1) * sizeof(char *));
	if (toks == NULL)
		exit(1);

	tok = strtok(line, delim);
	while (tok != NULL)
	{
		toks[i] = tok;
		i++;

/*		if (i >= bufsize)
		{
			bufsize += 1024;
			toks = realloc(toks, bufsize * sizeof(char *));
		}
*/		tok = strtok(NULL, delim);
	}
	toks[i] = NULL;

	return (toks);
}

int _strsep(char *str)
{
    int flag = 1, count = 0, i;

    for (i = 0; str[i]; i++)
    {
        if (str[i] != ' ' && flag == 1)
        {
            count += 1;
            flag = 0;
        }
        if (str[i + 1] == ' ')
            flag = 1;
    }
    return (count);
}
