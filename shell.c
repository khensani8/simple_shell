#include "shell.h"

/*
 * rd_line - read single line from input
 *
 * Return: command input
 */
char *rd_line(void)
{
    char *line = NULL;
    size_t n = 0;

    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "($) ", 4);

    if (getline(&line, &n, stdin) == -1)
    {
        if (isatty(STDIN_FILENO))
            write(STDOUT_FILENO, "\n", 1);
        free(line);
        return NULL;
    }

    return line;
}

/**
 * split_line - separate input string into individual tokens
 *
 * @line: pointer to input string
 *
 * Return: ...
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
    return toks;
}

/**
 * act - executes arguments
 *
 * @ar: arguments
 *
 * Return: int
 */
int act(char **ar)
{
    pid_t child = fork();

    if (child == 0)
    {
        if (execve(ar[0], ar, NULL) == -1)
        {
            perror("hsh");
            exit(EXIT_FAILURE);
        }
    }
    else if (child < 0)
    {
        perror("hsh");
    }
    else
    {
        int status;
        wait(&status); /* Wait for the child process to complete */
    }

    return 1;
}

/**
 * main - initializes shell and runs
 *
 * Return: Always 0
 */
int main(void)
{
    char *line, **tok;

    while (1)
    {
        line = rd_line();
        if (line == NULL)
        {
            break;
        }

        tok = split_line(line);
        if (tok[0] != NULL)
        {
            if (strcmp(tok[0], "exit") == 0)
            {
                /* Free allocated memory before exiting */
                free(tok);
                free(line);
                if (isatty(STDIN_FILENO))
		
			break;
            }
            else
            {
                act(tok);
            }
        }

        free(tok);
        free(line);
    }

    return 0;
}

