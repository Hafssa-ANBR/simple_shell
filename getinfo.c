#include "shell.h" 

/**
 * clear_info - initializes info_t struct
 * @info: struct address, function parameter
 */
void clear_info(info_t *info)
{
        info->arg = NULL;
        info->argv = NULL;
        info->path = NULL;
        info->argc = 0;
}

/**
 * set_info - initializes info_t struct
 * @info: struct address, function parameter
 * @av: argument vector, function parameter
 */
void set_info(info_t *info, char **av)
{
        int i = 0;

        info->fname = av[0];
        if (info->arg)
        {
                info->argv = strtow(info->arg, " \t");
                if (!info->argv)
                {
                        info->argv = malloc(sizeof(char *) * 2);
                        if (info->argv)
                        {
                                info->argv[0] = _strdup(info->arg);
                                info->argv[1] = NULL;
                        }
                }
                for (i = 0; info->argv && info->argv[i]; i++)
                        ;
                info->argc = i;

                replace_alias(info);
                replace_vars(info);
        }
}

/**
 * free_info - frees info_t struct fields
 * @info: struct address, function parameter
 * @all: true if freeing all fields, function parameter
 */
void free_info(info_t *info, int all)
{
        ffree(info->argv);
        info->argv = NULL;
        info->path = NULL;
        if (all)
        {
                if (!info->cmd_buf)
                        free(info->arg);
                if (info->env)
                        free_list(&(info->env));
                if (info->history)
                        free_list(&(info->history));
                if (info->alias)
                        free_list(&(info->alias));
                ffree(info->environ);
                        info->environ = NULL;
                bfree((void **)info->cmd_buf);
                if (info->readfd > 2)
                        close(info->readfd);
                _putchar(BUF_FLUSH);
        }
}

Sent from Outlook for iOS
 
From: Amina Elkharraz
Sent: Friday, May 26, 2023 12:14:01 AM
To: Amina Elkharraz <aminaaelkharraz@gmail.com>
Subject: 
 
#include "shell.h" 

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments.function parameter
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
        if (!info->environ || info->env_changed)
        {
                info->environ = list_to_strings(info->env);
                info->env_changed = 0;
        }

        return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. function parameter
 * @var: the string env var property,function parameter
 *  Return: 1 on delete, 0 if not
 */
int _unsetenv(info_t *info, char *var)
{
        list_t *nd = info->env;
        size_t i = 0;
        char *q;

        if (!nd || !var)
                return (0);

        while (nd)
        {
                q = starts_with(nd->str, var);
                if (q && *q == '=')
                {
                        info->env_changed = delete_node_at_index(&(info->env), i);
                        i = 0;
                        nd = info->env;
                        continue;
                }
                nd = nd->next;
                i++;
        }
        return (info->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments.function parameter
 * @var: the string env var property, function parameter
 * @value: the string env var value, function parameter
 *  Return: Always 0
 */
int _setenv(info_t *info, char *var, char *value)
{
        char *buff = NULL;
        list_t *nd;
        char *q;

        if (!var || !value)
                return (0);

        buff = malloc(_strlen(var) + _strlen(value) + 2);
        if (!buf)
                return (1);
        _strcpy(buff, var);
        _strcat(buff, "=");
        _strcat(buff, value);
        nd = info->env;
        while (nd)
        {
                q = starts_with(nd->str, var);
                if (q && *q == '=')
                {
                        free(nd->str);
                        nd->str = buff;
                        info->env_changed = 1;
                        return (0);
                }
                nd = nd->next;
        }
        add_node_end(&(info->env), buff, 0);
        free(buff);
        info->env_changed = 1;
        return (0);
}
