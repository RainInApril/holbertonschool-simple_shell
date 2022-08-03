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

## Testing Modes ##
The simple shell should work like this in interactive mode:
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
Also in non-interactive mode:
```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Install, Compile and Use ##
Install and Compile:
```C
(terminal)$ git clone https://github.com/RainInApril/holbertonschool-simple_shell.git
(terminal)$ gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```
Run shell
```C
./hsh
```
Type command
```C
echo "Hello World"
```
Example of usage:
```C
#shell$ echo "Hello World"
Hello World
```
Exit program and return to the original shell
```C
#shell$ exit
(terminal)$
```
