# Compilation for the hsh simple shell requirements are 
# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic -std=gnu89
RM=rm -rf

TARGET=shell
SRC=	_getenv.c \
	argarr.c \
	node_func.c \
	save_path.c \
	simple_shell_test.c \
	string_func.c

# shell hsh
all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	$(RM) *~ \#*\# \.\#* \
	$(TARGET)
