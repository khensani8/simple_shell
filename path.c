#include "shell.h"
/**
 * findpath - searches dir in PATH var for cmd
 * @cmd: cmd to find
 * @fullpath: path of cmd to execute
 * @path: full PATH variable
 * Return: pointer to full_path
 */
char *findpath(char *cmd, char *fullpath, char *path)
{
	unsigned int len;
	char *p_cpy, *tok;

	p_cpy = malloc(sizeof(char) * strlen(path) + 1);
	if (p_cpy == NULL)
	{
		perror("hsh");
		return (NULL);
	}
	strcpy(p_cpy, path);
	/* copy PATH dir + cmd name and check if it exists */
	tok = strtok(p_cpy, ":");
	if (tok == NULL)
		tok = strtok(NULL, ":");

	while (tok != NULL)
	{
		len = strlen(tok);
		fullpath = malloc(sizeof(char) * (len + strlen(cmd) + 2));
		if (fullpath == NULL)
		{
			perror("hsh");
			return (NULL);
		}

		strcpy(fullpath, tok);
		fullpath[len] = '/';
		strcpy(fullpath + len + 1, cmd);
		fullpath[len + strlen(cmd) + 1] = '\0';
		if (access(fullpath, X_OK) != 0)
		{
			free(fullpath);
			fullpath = NULL;
			tok = strtok(NULL, ":");
		}
		else
			break;
	}
	free(p_cpy);
	return (fullpath);
}
