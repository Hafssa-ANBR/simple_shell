#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address,function parameter
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter or not
 * @c: the char to check, function parameter
 * @delim: the delimeter string, function parameter
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input, function parameter
 * Return: 1 if c is alphabetic, 0 otherwise(if not)
 */

int _isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted, function parameter
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, signd = 1, f = 0, oput;
	unsigned int rst = 0;

	for (i = 0; s[i] != '\0' && f != 2; i++)
	{
		if (s[i] == '-')
			signd *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			f = 1;
			rst *= 10;
			rst += (s[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}

	if (signd == -1)
		oput = -rst;
	else
		oput = rst;

	return (oput);
}

