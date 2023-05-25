#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct,function parameter
 * @buf: address of buffer,function parameter
 * @len: address of len var,function parameter
 *
 * Return: bytes read
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	ssize_t rt = 0;
	size_t lg_p = 0;

	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		rt = getline(buf, &lg_p, stdin);
#else
		rt = _getline(info, buf, &lg_p);
#endif
		if (rt > 0)
		{
<<<<<<< HEAD
			if ((*buf)[rt - 1] == '\n')
			{
				(*buf)[rt - 1] = '\0';
=======
			if  ((*buf)[r - 1] == '\n')
			{
				(*buf)[r - 1] = '\0';
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
				rt--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
<<<<<<< HEAD
				*len = r;
=======
				*len =r;
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
				info->cmd_buf = buf;
			}
		}
	}
	return (rt);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct, function parameter
 *
 * Return: bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buff;
	static size_t i, j, lg;
<<<<<<< HEAD
	ssize_t rt = 0;
	char **buff_p = &(info->arg), *q;

	_putchar(BUF_FLUSH);
	rt = input_buf(info, &buff, &lg);
	if (rt == -1)
		return (-1);
	if (lg)
	{
		j = i;
		q = buff + i;

		check_chain(info, buff, &j, i, lg);
		while (j < lg)
		{
			if (is_chain(info, buff, &j))
				break;
			j++;
		}

		i = j + 1;
		if (i >= lg)
		{
			i = lg = 0;
			info->cmd_buf_type = CMD_NORM;
		}

		*buff_p = q;
		return (_strlen(q));
	}

	*buff_p = buff;
	return (rt);
=======
        ssize_t rt = 0;
        char **buff_p = &(info->arg), *q;

        _putchar(BUF_FLUSH);
        rt = input_buf(info, &buff, &lg);
        if (rt == -1)
                return (-1);
        if (lg)
        {
                j = i;
                q = buff + i;

                check_chain(info, buff, &j, i, lg);
                while (j < lg)
                {
                        if (is_chain(info, buff, &j))
                                break;
                        j++;
                }

                i = j + 1;
                if (i >= lg)
                {
                        i = lg = 0;
                        info->cmd_buf_type = CMD_NORM;
                }

                *buff_p = q;
                return (_strlen(q));
        }

        *buff_p = buff;
        return (rt);
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct, function parameter
 * @buf: buffer, function parameter
 * @i: size, function parameter
 *
 * Return: rt
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
<<<<<<< HEAD
	ssize_t rt = 0;

	if (*i)
		return (0);
	rt = read(info->readfd, buf, READ_BUF_SIZE);
	if (rt >= 0)
		*i = rt;
	return (rt);
=======
        ssize_t rt = 0;

        if (*i)
                return (0);
        rt = read(info->readfd, buf, READ_BUF_SIZE);
        if (rt >= 0)
                *i = rt;
        return (rt);
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct,function parameter
 * @ptr: address of pointer to buffer, preallocated or NULL, function parameter
 * @length: size of preallocated ptr buffer if not NULL, function parameter
 *
 * Return: st
 */
int _getline(info_t *info, char **ptr, size_t *length)
{
<<<<<<< HEAD
	static char buff[READ_BUF_SIZE];
	static size_t i, lg;
	size_t kt;
	ssize_t rt = 0, st = 0;
	char *q = NULL, *new_p = NULL, *c;

	q = *ptr;
	if (q && length)
		s = *length;
	if (i == lg)
		i = lg = 0;

	rt = read_buf(info, buf, &len);
	if (rt == -1 || (rt == 0 && lg == 0))
		return (-1);

	c = _strchr(buff + i, '\n');
	kt = c ? 1 + (unsigned int)(c - buff) : lg;
	new_p = _realloc(q, st, st ? st + kt : kt + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (q ? free(q), -1 : -1);

	if (st)
		_strncat(new_p, buff + i, kt - i);
	else
		_strncpy(new_p, buff + i, kt - i + 1);

	st += kt - i;
	i = kt;
	q = new_p;

	if (length)
		*length = st;
	*ptr = q;
	return (st);
=======
        static char buff[READ_BUF_SIZE];
        static size_t i, lg;
        size_t kt;
        ssize_t rt = 0, st = 0;
        char *q = NULL, *new_p = NULL, *c;

        q = *ptr;
        if (q && length)
                s = *length;
        if (i == lg)
                i = lg = 0;

        rt = read_buf(info, buf, &len);
        if (rt == -1 || (rt == 0 && lg == 0))
                return (-1);

        c = _strchr(buff + i, '\n');
        kt = c ? 1 + (unsigned int)(c - buff) : lg;
        new_p = _realloc(q, st, st ? st + kt : kt + 1);
        if (!new_p) /* MALLOC FAILURE! */
                return (q ? free(q), -1 : -1);

        if (st)
                _strncat(new_p, buff + i, kt - i);
        else
                _strncpy(new_p, buff + i, kt - i + 1);

        st += kt - i;
        i = kt;
        q = new_p;

        if (length)
                *length = st;
        *ptr = q;
        return (st);
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number,function parameter
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
<<<<<<< HEAD
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
=======
        _puts("\n");
        _puts("$ ");
        _putchar(BUF_FLUSH);
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
}

