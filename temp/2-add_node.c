#include "main.h"


/**
 * add_node - add a new node at the being of a list_t list
 * @head: pointer to beginning of list
 * @str: pointer to string to be duplicated over
 *Return: pointer to node
 */

list_t *add_node(list_t **head, const char *str)
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
	new->next = prev;
	*head = new;

	return (new);
}
