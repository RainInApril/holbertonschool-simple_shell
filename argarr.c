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
        char **argv;
        int listlen, i = 0;

        token = strtok(str, " \t\n\r");
	if (token == NULL)
	{
		free(str);
		return(NULL);
		exit(0);
	}
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
                argv[i] = _strdup(node->str);
                i++;
                node = node->next;
        }
	free(token);
        argv[i] = NULL;
        free_list(head);
        return (argv);
}
