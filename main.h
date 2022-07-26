#ifndef _MAIN_H_
#define _MAIN_H_

#include <unistd.h>

/**
 * struct builtin - struct with builtin commands
 * @command: command received
 * @func: function
 */
typedef struct builtin
{
	char *command;
	int (*func)();
} s_builtin;

#endif /* _MAIN_H_ */
