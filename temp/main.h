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

extern char **environ;
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

typedef struct path_s
{
	char *str;
	struct path_s *next;
} path_t;
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
path_t *save_path(path_t **head, char *token);
path_t *save_path_end(path_t **head, const char *token);
int list_len(const list_t *h);
void free_list(list_t *head);
int _strlen(const char *s);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
char **argarr(char *str);

#endif /* _MAIN_H_ */
