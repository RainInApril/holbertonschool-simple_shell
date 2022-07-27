# Compilation for the hsh simple shell requirements are 
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89
RM=rm -rf

TARGET=shell
SRC=

# shell hsh
all:
	$(CC) $(CFLAGS) *.c -o hsh
	./hsh

clean:
	$(RM) hsh .sshell_logging
