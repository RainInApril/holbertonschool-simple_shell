#include "main.h"

/**
 * list_len - prints the elements of a struct list
 * @h: pointer to struct list item
 *Return: size_t of number of elements
 */

int list_len(const list_t *h)
{
	int count = 0;

	while (h != NULL)
	{
		count++;
		h = h->next;
	}
	return (count);
}

/**
 * add_node_end - add a node to end of linked list
 * @head: pointer to current head of node
 * @str: str to copy over
 *Return: pointer to node
 */

list_t *add_node_end(list_t **head, char *str)
{
	list_t *new;
	list_t *prev;

	prev = *head;

	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = _strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}

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

/**
 * add_node - add a new node at the being of a list_t list
 * @head: pointer to beginning of list
 * @str: pointer to string to be duplicated over
 *Return: pointer to node
 */

list_t *add_node(list_t **head, char *str)
{
	list_t *new;
	list_t *prev;

	prev = *head;
	new = malloc(sizeof(list_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = _strdup(str);
	if (new->str == NULL)
	{
		free(new);
		return (NULL);
	}
	new->len = _strlen(new->str);
	new->next = prev;
	*head = new;

	return (new);
}

/**
 * free_list - Free a linked list
 * @head: pointer to start of list
 *Return: void
 */

void free_list(list_t *head)
{
	list_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = temp->next;
		free(temp);
	}
	free(head);
}
