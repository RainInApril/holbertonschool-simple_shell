#include "main.h"

/**
 * fork_exec - function that creates a child process
 * @argv: list of arguments
 * @env: environment variables
 * Return: 0 success 1 if error
 */

int fork_exec(char **argv, char **env)
{
	int exit_status;
	pid_t pid = fork();

	if (pid == -1)
	{
/* the fork failed, perror will print the reason */
		perror("fork");
	}
	else if (pid == 0)
	{
/* creates the child process */
		if (execve(argv[0], argv, env) == -1)
		{
			perror("execve");
		}
/* case unsuccess execution */
		return (1);
	}
	else
	{
/*  parent wait for the child porocess */
		waitpid(pid, &exit_status, 0);

		if (WIFEXITED(exit_status))
		{
			exit_code = WEXITSTATUS(exit_status);
		}
	}
	return (0);
}
