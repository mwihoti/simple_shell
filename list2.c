#include "main.h"

/**
 * list_length - determines length of linked list
 * @h: pointer to firrst node
 *
 * Return: list size
 */
size_t list_length(const list_t *h)
{
	size_t m = 0;

	while (h)
	{
		h = h->next;
		m++;
	}
	return (m);
}

/**
 * list_str - returns array of string of list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */

char **list_str(list_t *head)
{
	list_t *node = head;
	size_t i = list_length(head);
	size_t j;
	char **strings;
	char *string;

	if (!head || !i)
		return (NULL);
	strings = malloc(sizeof(char *) * (i + 1));
	if (!strings)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		string = malloc(_strslength(node->str) + 1);
		if (!string)
		{
			for (j = 0; j < i; j++)
				free(strings[j]);
			free(strings);
			return (NULL);
		}
		string = _strcopy(string, node->str);
		strings[i] = string;
	}
	strings[i]  = NULL;
	return (strings);
}

/**
 * prints_list_t - prints all elements of a list_t
 * @p: pointer to first node
 *
 * Return: size of list
 */
size_t prints_list_t(const list_t *p)
{
	size_t m = 0;

	while (p)
	{
		_printstr(convertsnumber(p->num, 10, 0));
		_writechar(':');
		_writechar(' ');
		_printstr(p->str ? p->str : "(nil)");
		_printstr("\n");
		p = p->next;
		m++;
	}
	return (m);
}

/**
 * node_to_start -return node string that starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: character after prefix match
 *
 * Return: match node or null
 */
list_t *node_to_start(list_t *node, char *prefix, char c)
{
	char *s = NULL;

	while (node)
	{
		s = start_hay(node->str, prefix);
		if (s && ((c == -1) || (*s == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_index - gets index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_index(list_t *head, list_t *node)
{
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


