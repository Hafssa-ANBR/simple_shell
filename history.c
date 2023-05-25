#include "shell.h"

/**
 * get_history_file - gets the history file
 * @info: parameter struct, function parameter
 *
 * Return: allocated string containg history file
 */

char *get_history_file(info_t *info)
{
	char *buff, *dr;

        dr = _getenv(info, "HOME=");
        if (!dr)
                return (NULL);
        buff = malloc(sizeof(char) * (_strlen(dr) + _strlen(HIST_FILE) + 2));
        if (!buff)
                return (NULL);
        buff[0] = 0;
        _strcpy(buff, dr);
        _strcat(buff, "/");
        _strcat(buff, HIST_FILE);
        return (buff);
}

/**
 * write_history - creates a file, or appends to an existing file
 * @info: the parameter struct,function parameter
 *
 * Return: 1 on success,-1 if not
 */
int write_history(info_t *info)
{
        ssize_t fd;
        char *filename = get_history_file(info);
        list_t *nd = NULL;

        if (!filename)
                return (-1);

        fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
        free(filename);
        if (fd == -1)
                return (-1);
        for (nd = info->history; nd; nd = nd->next)
        {
                _putsfd(nd->str, fd);
                _putfd('\n', fd);
        }
        _putfd(BUF_FLUSH, fd);
        close(fd);
        return (1);
}

/**
 * read_history - reads history from file
 * @info: the parameter struct, function parameter
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
        int i, lt = 0, linecnt = 0;
        ssize_t fd, rdlen, fsize = 0;
        struct stat st;
        char *buff = NULL, *filename = get_history_file(info);

        if (!filename)
                return (0);

        fd = open(filename, O_RDONLY);
        free(filename);
        if (fd == -1)
                return (0);
        if (!fstat(fd, &st))
                fsize = st.st_size;
        if (fsize < 2)
                return (0);
        buff = malloc(sizeof(char) * (fsize + 1));
        if (!buff)
                return (0);
        rdlen = read(fd, buff, fsize);
        buff[fsize] = 0;
        if (rdlen <= 0)
                return (free(buff), 0);
        close(fd);
        for (i = 0; i < fsize; i++)
                if (buff[i] == '\n')
                {
                        buff[i] = 0;
                        build_history_list(info, buff + lt, linecount++);
                        lt = i + 1;
                }
        if (lt != i)
                build_history_list(info, buff + lt, linecnt++);
        free(buff);
        info->histcount = linecnt;
        while (info->histcount-- >= HIST_MAX)
                delete_node_at_index(&(info->history), 0);
        renumber_history(info);
        return (info->histcount);
}

/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments.function parameter
 * @buf: buffer,function parameter
 * @linecount: the history linecount, histcount, function parameter
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buf, int linecount)
{
        list_t *nd = NULL;

        if (info->history)
                nd = info->history;
        add_node_end(&node, buf, linecount);

        if (!info->history)
                info->history = nd;
        return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
        list_t *nd = info->history;
        int i = 0;

        while (nd)
        {
                nd->num = i++;
                nd = nd->next;
        }
        return (info->histcount = i);
}
