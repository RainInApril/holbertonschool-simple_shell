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
#include <errno.h>

extern int errno;
extern char **environ;

typedef struct path_s
{
	char *str;
	struct path_s *next;
} path_t;

path_t *save_path(path_t **head, char *token);
path_t *save_path_end(path_t **head, char *token);
void free_path_list(path_t *head);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int argarr(char **args, char *str);
char *find_command(char *argv);
int can_exec(char *argv);
int check_args(char *input, char **argv, char *name, char **env, int i);
int fork_exec(char **argv, char **env);
void print_error(char *argv, char *name, int i);
int builtin(char *input, char **argv);
void _env(void);
void ctrlc(int signal);
#endif /* _MAIN_H_ */
