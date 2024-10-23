CC=gcc
CFLAGS=-Wall -Wextra  -g
EXEC=dsa
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

dsa: $(OBJ)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) -o $@ -c $(CCFLAGS) $<
# dsa.o: dsa.c
	# $(CC) -o $@ -c $(CCFLAGS) $<
#
# linkedList.o: linkedList.c
# 	$(CC) -o $@ -c $(CCFLAGS) $<
clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)


