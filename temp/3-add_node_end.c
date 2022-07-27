#include "main.h"

/**
 * add_node_end - add a node to end of linked list
 * @head: pointer to current head of node
 * @str: str to copy over
 *Return: pointer to node
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new;
	list_t *prev;

	prev = *head;

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = strdup(str);
	if (new->str == NULL)
		free(new);
	new->len = _strlen(new->str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	/* get to end of linked list */
	while (prev->next != NULL)
	{
		prev = prev->next;
	}

	/* once at end assigned new address to created block */
	prev->next = new;
	return (new);
}
