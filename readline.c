#include "shell.h"

/**
 *rd_line - read single line from input
 *
 *Return: command input
 */
char *rd_line(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t read = 0;
	int i = 0;

	read = getline(&line, &n, stdin);
	if (read == -1)
	{
		free(line);
		if (isatty(STDIN_FILENO) != 0)
			write(STDOUT_FILENO, "\n", 1);
		exit(0);
	}
	if (line[read - 1] == '\n' || line[read - 1] == '\t')
		line[read - 1] = '\0';
	for (i = 0; line[i]; i++)
	{
		if (line[i] == '#' && line[i - 1] == ' ')
		{
			line[i] = '\0';
			break;
		}
	}

	return (line);
}
