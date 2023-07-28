#include "shell.h"

/**
 * free_cmd - frees cmd allocation
 * @cmd: to be freed
 * Return: void
 */
void free_cmd(char **ar)
{
	int i;

	for (i = 0; ar[i]; i++)
		free(ar[1]);
}

/**
 * free_tokens - Frees the memory allocated for an array of tokens.
 *
 * @toks: The array of tokens to be freed.
 */
void free_tokens(char **toks)
{
        free(toks);
}
