#ifndef _MAIN_H_
#define _MAIN_H_
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <limits.h>

typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
int list_len(const list_t *h);
void free_list(list_t *head);
int _strlen(const char *s);
#endif /* _MAIN_H_ */
