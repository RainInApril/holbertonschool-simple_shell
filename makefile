# Compilation for the hsh simple shell requirements are 
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89 -g
RM=rm -rf
BETTY=betty

TARGET=hsh
SRC0=	_getenv.c \
	argarr.c \
	node_func.c \
	save_path.c \
	simple_shell_test.c \
	string_func.c \
	find_command.c \
	can_exec.c \
	fork_exec.c \
	print_error.c

SRC1=	string_func.c \
	temp/main.c \
	argarr.c \
	node_func.c
# shell hsh
all: 0 1

0:
	$(CC) $(CFLAGS) $(SRC0) -o $(TARGET)

1:
	$(CC) $(CFLAGS) $(SRC1) -o $(TARGET)

clean:
	$(RM) *~ \#*\# \.\#* \
	$(TARGET)

betty:
	$(BETTY) $(SRC)
