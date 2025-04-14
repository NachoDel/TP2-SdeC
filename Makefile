# Makefile para compilar tp.c + gini.asm

CC = gcc
ASM = nasm
CFLAGS = -m32 -g
ASFLAGS = -f elf32
LDFLAGS = -m32

all: gini

gini.o: gini.asm
	$(ASM) $(ASFLAGS) gini.asm -o gini.o

tp.o: tp.c
	$(CC) $(CFLAGS) -c tp.c -o tp.o

gini: tp.o gini.o
	$(CC) $(LDFLAGS) -g tp.o gini.o -o gini

clean:
	rm -f *.o gini
