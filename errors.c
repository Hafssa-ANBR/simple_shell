#include "shell.h"

/**
 * _eputs - prints an input string
 * @str: the string to be printed, function parameter
 *
 * return: Nothing
 */
void _eputs(char *str)
{
	int j = 0;

	if (!str)
		return;
	while (str[j] != '\0')
	{
		_eputchar(str[j]);
		j++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @c: The character to print, function parameter
 *
 * Return: On success 1.(ifis writed)
 * On error(is not writed), -1 is returned, and arrno is set appropriately
 */
int _eputchar(char c)
{
	static char buff[WRITE_BUF_SIZE];
	static int i;

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buff, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buff[i++] = c;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @c: The character to print, function parameter
 * @fd: The filedescriptor to write to,function parameter
 *
 * Return: On success 1.
 * On error, -1 is returned.
 */
int _putfd(char c, int fd)
{
        static char buff[WRITE_BUF_SIZE];
        static int i;

        if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
        {
                write(fd, buff, i);
                i = 0;
        }
        if (c != BUF_FLUSH)
                buff[i++] = c;
        return (1);
}

/**
 * _putsfd - prints an input string
 * @str: The string to be printed, function parameter
 * @fd: the filedescriptor to write to, function parameter
 *
 * Return: always the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int j = 0;

	if (!str)
		return (0);
	while (*str)
	{
		 j += _putfd(*str++, fd);
	}
	return (j);
}
