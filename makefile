# Compilation for the hsh simple shell requirements are 
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC = gcc
SRC = shell.c main.c
CFLAGS = -g -Wall -Werror -Wextra -pedantic

# shell hsh
all:
	$(CC) $(CFLAGS) *.c -o hsh
	./hsh

clean:
	$(RM) hsh .sshell_logging
