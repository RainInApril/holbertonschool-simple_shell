#include "main.h"

/**
 * argarr - initialises an array of pointers
 * @str: string to be broken into pointers
 * Return: char **
 */

char **argarr(char *str)
{
        list_t *head = NULL;
        char *token;
        char **argv;
        int listlen, i = 0;

        token = strtok(str, " ");
        add_node(&head, token);
         while (token != NULL)
        {
                token = strtok(NULL, " ");
                if (token != NULL)
                        add_node_end(&head, token);
        }

        listlen = list_len(head);
        argv = malloc(sizeof(char *) * listlen);

        while (i < listlen)
        {
                argv[i] = strdup(head->str);
                i++;
                head = head->next;
        }
        argv[i] = NULL;
        free_list(head);
        return (argv);
}