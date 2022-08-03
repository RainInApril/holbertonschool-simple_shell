# :shell:
# Simple Shell #
A mini replica of the standard Shell 

## Description ##
This project is a simple UNIX shell to read and call the bassic commands from a file or from user input (interactive mode)

## Sypnosis ##
### Simple Shell project's core files:
| File's name        | Description                                                         |
|--------------------|---------------------------------------------------------------------|
| main.h             | contains important prototypes of functions for Simple Shell program |
| simple_shell.c     | an executable file which runs a simple shell program                |
| man_1_simple_shell | the manual created for Simple Shell program                         |
### Supporting files:
| File's name    | Description                                                      |
|----------------|------------------------------------------------------------------|
| _getenv.c      | get environment variable                                         |
| argarr.c       | initialises an array of pointers                                 |
| can_exec.c     | function that checks if a command is executable                  |
| find_command.c | finds the command sent through                                   |
| forck_exec.c   | function that creates a child process                            |
| node_func.c    | contains prototypes: list_len, add_node, add_node_end, free_list |
| print_error.c  | prints an error message when command is not found                |
| save_path.c    | saves the different paths from PATH in env                       |
| string_func.c  | contains prototypes: _strlen, _strcmp, _strcpy, _strcat, strdup  |

## Functions and System Calls used (from the C standard libraries)
`access`, `execve`, `exit`, `fork`, `free`, `getline`, `isatty`, `malloc`, `perror`,`read`, `strtok`, `waitpid`, `write`

## Example ##

