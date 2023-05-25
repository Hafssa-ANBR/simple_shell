#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node, functio parameter
 * @str: str field of node, function parameter
 * @num: node index used by history, function parameter
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_hd;

	if (!head)
		return (NULL);
	new_hd = malloc(sizeof(list_t));
	if (!new_hd)
		return (NULL);
	_memset((void *)new_hd, 0, sizeof(list_t));
	new_hd->num = num;
	if (str)
	{
		new_hd->str = _strdup(str);
		if (!new_hd->str)
		{
			free(new_hd);
			return (NULL);
		}
	}
	new_hd->next = *head;
	*head = new_hd;
	return (new_hd);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node, function parameter
 * @str: str field of node,function parameter
 * @num: node index used by history,function parameter
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_nd, *nd;

	if (!head)
		return (NULL);

	nd = *head;
	new_nd = malloc(sizeof(list_t));
	if (!new_nd)
		return (NULL);
	_memset((void *)new_nd, 0, sizeof(list_t));
	new_nd->num = num;
	if (str)
	{
		new_nd->str = _strdup(str);
		if (!new_nd->str)
		{
			free(new_nd);
			return (NULL);
		}
	}
	if (nd)
	{
		while (nd->next)
			nd = nd->next;
		nd->next = new_nd;
	}
	else
		*head = new_nd;
	return (new_nd);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node, function parameter
 *
 * Return: size of list, i
 */
size_t print_list_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node, function parameter
 * @index: index of node to delete,function parameter
 *
 * Return: 1 on success, 0 if not
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *nd, *prv_nd;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		nd = *head;
		*head = (*head)->next;
		free(nd->str);
		free(nd);
		return (1);
	}
	nd = *head;
	while (nd)
	{
		if (i == index)
		{
			prv_nd->next = nd->next;
			free(nd->str);
			free(nd);
			return (1);
		}
		i++;
		prv_nd = nd;
		nd = nd->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node,function parameter
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *nd, *next_nd, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	nd = head;
	while (nd)
	{
		next_nd = nd->next;
		free(nd->str);
		free(nd);
		nd = next_nd;
	}
	*head_ptr = NULL;
}

