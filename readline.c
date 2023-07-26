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

	read = getline(&line, &n, stdin);
	if (read == -1)
	{
		free(line);
		write(STDOUT_FILENO, "\n", 1);
		exit(EXIT_SUCCESS);
	}
	if (read == EOF || strcmp("exit\n", line) == 0)
	{
		free(line);
		exit(EXIT_SUCCESS);
	}
	line[read - 1] = '\0';

	if (strcmp("env", line) == 0)
		print_env();

	return (line);
}
