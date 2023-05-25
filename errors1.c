#include "shell.h"

/**
 * _erratoi - converts a string to an integer
 * @s: the string to be converted, function parameter
 * Return: 0 if no numbers in string, -1 on error
 */
int _erratoi(char *s)
{
	unsigned long int rlt = 0;
	int i = 0;

	if (*s == '+')
                s++;  /* TODO: why does this make main return 255? */
        for (i = 0;  s[i] != '\0'; i++)
        {
                if (s[i] >= '0' && s[i] <= '9')
                {
                        rlt *= 10;
                        rlt += (s[i] - '0');
                        if (rlt > INT_MAX)
                                return (-1);
                }
                else
                        return (-1);
        }
        return (rlt);
}

/**
 * print_error - prints an error message
 * @info: the parameter & return info struct,function parameter
 * @estr: string containing specified error type,function parameter
 * Return: 0 if no numbers in string,-1 on error
 */
void print_error(info_t *info, char *estr)
{
        _eputs(info->fname);
        _eputs(": ");
        print_d(info->line_count, STDERR_FILENO);
        _eputs(": ");
        _eputs(info->argv[0]);
        _eputs(": ");
        _eputs(estr);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
        int (*__putchar)(char) = _putchar;
        int i, cnt = 0;
        unsigned int _abs_, crrt;

        if (fd == STDERR_FILENO)
                __putchar = _eputchar;
        if (input < 0)
        {
                _abs_ = -input;
                __putchar('-');
                cnt++;
        }
        else
                _abs_ = input;
        crrt = _abs_;
        for (i = 1000000000; i > 1; i /= 10)
        {
                if (_abs_ / i)
                {
                        __putchar('0' + crrt / i);
                        cnt++;
                }
                crrt %= i;
        }
        __putchar('0' + crrt);
        cnt++;

        return (cnt);
}

/**
 * convert_number - converter function, a clone of itoa
 * @num: number,function parameter
 * @base: base,function parameter
 * @flags: argument flags,function parameter
 *
 * Return: string
 */
char *convert_number(long int num, int base, int flags)
{
        static char *arr;
        static char buff[50];
        char signd = 0;
        char *ptr;
        unsigned long nm = num;

        if (!(flags & CONVERT_UNSIGNED) && num < 0)
        {
                nm = -num;
                signd = '-';

        }
        arr = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
        ptr = &buff[49];
        *ptr = '\0';

        do      {
                *--ptr = arr[n % base];
                nm /= base;
        } while (nm != 0);

        if (signd)
                *--ptr = signd;
        return (ptr);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buf: address of the string to modify,function parameter
 *
 * Return: Always 0;
 */
void remove_comments(char *buf)
{
        int i;

        for (i = 0; buf[i] != '\0'; i++)
                if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
                {
                        buf[i] = '\0';
			break;
		}
}
