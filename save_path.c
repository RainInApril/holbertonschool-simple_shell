#include "main.h"

/**
 * save_path - saves the different paths from PATH in env
 * @token: path to be saved
 * @head: pointer to start of list.
 * Return: pointer to start of list.
 */


path_t *save_path(path_t **head, char *token)
{
	path_t *new;
	path_t *prev;

	prev = *head;
	new = malloc(sizeof(path_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = _strdup(token);
	if (new->str == NULL)
		free(new);
	new->next = prev;
	*head = new;

	return (new);
}

/**
 * save_path_end - saves the different paths from PATH in env
 * @token: path to be saved
 * @head: pointer to start of list.
 * Return: pointer to start of list.
 */

path_t *save_path_end(path_t **head, const char *token)
{
	path_t *new;
	path_t *prev;

	prev = *head;

	new = malloc(sizeof(path_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->str = _strdup(token);
	if (new->str == NULL)
		free(new);

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

void free_path_list(path_t *head)
{
	path_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = temp->next;
		free(temp->str);
		free(temp);
	}
	free(head);
}
