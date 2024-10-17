CC=gcc
CFLAGS=-Wall -Wextra  -g
EXEC=dsa

all: $(EXEC)

dsa: dsa.o
	$(CC) -o $@ $^
dsa.o: dsa.c
	$(CC) -o $@ -c $(CCFLAGS) $<
clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)


