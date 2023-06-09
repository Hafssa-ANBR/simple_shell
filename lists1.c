#include "shell.h"

/**
<<<<<<< HEAD
 * list_len - determines length of linked list
=======
 * list_len - determines length if linked list
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
 * @h: pointer to first node,function parameter
 *
 * Return: size of list
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node,function parameter
 *
<<<<<<< HEAD
 * Return: array of strings,strs
=======
 * Return: array of strings, strs
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
 */
char **list_to_strings(list_t *head)
{
	list_t *nd = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
<<<<<<< HEAD
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; nd; nd = nd->next, i++)
	{
		str = malloc(_strlen(nd->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, nd->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
=======
                return (NULL);
        strs = malloc(sizeof(char *) * (i + 1));
        if (!strs)
                return (NULL);
        for (i = 0; nd; nd = nd->next, i++)
        {
                str = malloc(_strlen(nd->str) + 1);
                if (!str)
                {
                        for (j = 0; j < i; j++)
                                free(strs[j]);
                        free(strs);
                        return (NULL);
                }

                str = _strcpy(str, nd->str);
                strs[i] = str;
        }
        strs[i] = NULL;
        return (strs);
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node,function parameter
 *
 * Return: size of list
 */
size_t print_list(const list_t *h)
{
<<<<<<< HEAD
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
=======
        size_t i = 0;

        while (h)
        {
                _puts(convert_number(h->num, 10, 0));
                _putchar(':');
                _putchar(' ');
                _puts(h->str ? h->str : "(nil)");
                _puts("\n");
                h = h->next;
                i++;
        }
        return (i);
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head,function parameter
 * @prefix: string to match,function parameter
 * @c: the next character after prefix to match,function parameter
 *
 * Return: match node or null
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
<<<<<<< HEAD
	char *q = NULL;

	while (node)
	{
		q = starts_with(node->str, prefix);
		if (q && ((c == -1) || (*q == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
=======
        char *q = NULL;

        while (node)
        {
                q = starts_with(node->str, prefix);
                if (q && ((c == -1) || (*q == c)))
                        return (node);
                node = node->next;
        }
        return (NULL);
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head,function parameter
 * @node: pointer to the node,function parameter
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
<<<<<<< HEAD
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

=======
        size_t i = 0;

        while (head)
        {
                if (head == node)
                        return (i);
                head = head->next;
                i++;
        }
        return (-1);
}
>>>>>>> e8ba44942167d578d2d3e71cf52af8c7394f174a
