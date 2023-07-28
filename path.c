#include "shell.h"

/**
 * findpath - searches dir in PATH var for cmd
 * @cmd: cmd to find
 * @path: path of cmd to execute
 * @pcpy: full PATH variable
 * Return: pointer to full_path
 */
char *findpath(char **cmd, char *path, char *pcpy)
{
	char *fullpath = NULL, *buf = NULL, *tok;
	int count = 0, flag = 0, len = 0, n = 0;
	static char t[256];
	struct stat head;

	pcpy = NULL;
	pcpy = strdup(path);
	count = _pathsep(pcpy);

	tok = strtok(pcpy, ": =");
	while (tok != NULL)
	{
		buf = pathconcat(t, cmd, tok);
		if (stat(buf, &head) == 0)
		{
			fullpath = buf;
			flag = 1;
			break;
		}
		if (n < count - 2)
		{
			len = strlen(tok);
			if (tok[len + 1] == ':')
			{
				if (stat(cmd[0], &head) == 0)
				{
					fullpath = cmd[0];
					flag = 1;
					break;
				}
			}
		}
		n++;
		tok = strtok(NULL, ":");
	}
	if (flag == 0)
		fullpath = cmd[0];
	free(pcpy);
	return (fullpath);
}

/**
 * _pathsep - counts PATH entries
 * @str: pointer to str
 * Return: PATH variables
 */
int _pathsep(char *str)
{
	int flag = 1, count = 0, i;

	for (i = 0; str[i]; i++)
	{
		if (str[i] != ':' && flag == 1)
		{
			count += 1;
			flag = 0;
		}
		if (str[i + 1] == ' ')
			flag = 1;
	}
	return (count);
}

/**
 * cmpPATH - strcmp for PATH against environ
 * @s1: ...
 * @s2: ...
 * Return: 0 (success)
 */
int cmpPATH(const char *s1, const char *s2)
{
	int i = 0;

	while (s2[i] != '=')
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

/**
 * pathconcat - concats input str with PATH
 * @buf: ...
 * @toks: ...
 * @tok: ...
 * Return: ...
 */
char *pathconcat(char *buf, char **toks, char *tok)
{
	int n = 0;

	memset(buf, 0, 256);
	n = _strlen(tok) + strlen(toks[0]) + 2;
	strcat(buf, tok);
	strcat(buf, "/");
	strcat(buf, toks[0]);
	buf[n - 1] = '\0';
	return (buf);
}
