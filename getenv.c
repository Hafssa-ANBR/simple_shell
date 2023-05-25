#include "shell.h"

/**
 * get_environ - returns the string array copy of our environ
 * @info: Structure containing potential arguments.function parameter
 * Return: Always 0
 */
char **get_environ(info_t *info)
{
<<<<<<< HEAD
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
=======
        if (!info->environ || info->env_changed)
        {
                info->environ = list_to_strings(info->env);
                info->env_changed = 0;
        }

        return (info->environ);
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. function parameter
 * @var: the string env var property,function parameter
 *  Return: 1 on delete, 0 if not
 */
int _unsetenv(info_t *info, char *var)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
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
<<<<<<< HEAD
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

=======
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
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
