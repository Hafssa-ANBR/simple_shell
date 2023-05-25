#include "shell.h"

/**
 * _strncpy - copies a string
 * @dest: the destination string to be copied to, function parameter
 * @src: the source string, function parameter
 * @n: the amount of characters to be copied, function parameter
 * Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *st = dest;
	int i = 0, j;

	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (st);
}

/**
 * *_strncat - concatenates two strings
 *@dest: the first string,function parameter
 *@src: the second string,function parameter
 *@n: the amount of bytes to be maximally used,function parameter
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i = 0, j = 0;
	char *st = dest;

	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (st);
}

/**
 * *_strchr - locates a character in a string
 *@s: the string to be parsed,function parameter
 *@c: the character to look for,function parameter
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
