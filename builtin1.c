#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_alias - sets alias to string
 * @info: parameter struct,function parameter
 * @str: the string alias, function parameter
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *str)
{
	char *q, s;
	int rt;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	s = *q;
	*q = 0;
	rt = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = s;
	return (rt);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct, function parameter
 * @str: the string alias, function parameter
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *str)
{
	char *p;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	if (!*++q)
		return (unset_alias(info, str));

	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node, function parameter
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *node)
{
	char *q = NULL, *b = NULL;

	if (node)
	{
		q = _strchr(node->str, '=');
		for (b = node->str; b <= q; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(q + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _myalias(info_t *info)
{
	char *q = NULL;
	int i = 0;
	list_t *nd = NULL;

	if (info->argc == 1)
	{
		nd = info->alias;
		while (nd)
		{
			print_alias(nd);
			nd = nd->next;
		}
		return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
		q = _strchr(info->argv[i], '=');
		if (q)
			set_alias(info, info->argv[i]);
		else
			print_alias(node_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}

