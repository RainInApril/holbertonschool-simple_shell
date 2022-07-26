#include "main.h"
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
		head = head->next;
		free(temp->str);
		free(temp);
	}
	free(head);
}
