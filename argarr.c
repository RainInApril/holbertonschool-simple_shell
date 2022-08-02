#include "main.h"

/**
 * argarr - initialises an array of pointers
 * @str: string to be broken into pointers
 * Return: char **
 */

char **argarr(char *str)
{
        list_t *node, *head = NULL;
        char *token;
	char **argv = NULL;
        int listlen, i = 0;

        token = strtok(str, " \t\n\r");
	if (token == NULL)
		return(NULL);

        add_node(&head, token);
	while (token != NULL)
        {
                token = strtok(NULL, " \t\n\r");
                if (token != NULL)
                        add_node_end(&head, token);
        }

	listlen = list_len(head);

	argv = malloc(sizeof(char *) * (listlen + 1));
	node = head;
	while (i < listlen)
        {
                argv[i] = strdup(node->str);
                i++;
                node = node->next;
	}
	argv[i] = NULL;
	free(token);
	free(node);
        free_list(head);
        return (argv);
}
