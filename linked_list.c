#include "shell.h"

/**
 * add_node_end - A function that adds a new node at the end of a
 * dir_list list
 * @head: a dir_list list
 * @str: added element
 * Return: Address of the new element, or NULL if it fails
 */
dir_list *add_node_end(dir_list **head, const char *str)
{
	dir_list *nnode, *tmp;

	if (!head || !str)
		return (NULL);

	nnode = malloc(sizeof(dir_list));
	if (!nnode)
		return (NULL);

	nnode->dir = _strdup(str);
	if (nnode->dir == NULL)
	{
		free(nnode);
		return (NULL);
	}
	nnode->next = NULL;

	if (*head == NULL)
	{
		*head = nnode;
		return (*head);
	}
	tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = nnode;
	return (*head);
}

/**
 * free_dir_list - Frees a dir_list list
 * @head: Start of list
 */
void free_dir_list(dir_list *head)
{
	dir_list *tmp;

	if (!head)
		return;
	while (head)
	{
		tmp = head->next;
		free(head->dir);
		free(head);
		head = tmp;
	}
}
