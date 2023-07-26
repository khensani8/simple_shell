#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @dest: pointer to string one
 * @src: pointer to string two
 * Return: pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int len, i;

	len = 0;
	while (dest[len] != '\0')
		len++;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[len] = src[i];
		len++;
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * _strlen - returns the length of a string
 * @s: pointer to string
 * Return: length of string
 */
int _strlen(char *s)
{
	int ln = 0;

	while (*s != '\0')
	{
		ln++;
		s++;
	}
	return (ln);
}

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: comparison
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] == s2[i])
		return (0);
	else
		return (s1[i] - s2[i]);
}

/**
 * _strcpy - copies the string pointed to by src, including terminating (\0)
 * @dest: buffer
 * @src: string pointer
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int y = 0;

	while (src[y] != '\0')
	{
		dest[y] = src[y];
		y++;
	}
	dest[y] = '\0';
	return (dest);
}
