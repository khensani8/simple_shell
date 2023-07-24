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
        if (read == EOF)
        {
		write(1, "\n", 1);
                free(line);
                exit(EXIT_SUCCESS);
        }

        return (line);
}
