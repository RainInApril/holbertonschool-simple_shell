#include "main.h"

/**
 * fork_exec - function that creates a child process
 * @argv: list of arguments
 * @env: environment variables
 *Return: 1 success 0 if error
 */

int fork_exec(char **argv, char **env)
{
	pid_t pid = fork();

	if (pid == -1)
	{
/* the fork failed, perror will print the reason */
		perror("fork");
	}
	else if (pid == 0)
	{
/* creates the child process */
		char **argv = argv[0];
		execve(argv[0], argv, env);
/* case unsuccess execution */
		perror("execvpe");
		return (1);
	}
	else
	{
/*  parent wait for the child porocess */
		int exit_status;
		if (waitpid(pid, &exit_status, 0) == -1)
		{
			perror("waitpid");
			return(1);
		}
		printf("error executing the command", exit_status);
	}
	return (0);
}
