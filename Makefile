SRCDIR = ./src
INCDIR = ./include
OBJDIR = ./obj
LIBDIR = ./lib

CC = gcc
RM = rm -f

CCFLAGS = -ggdb3

SRCS_C = $(SRCDIR)/nsshttp.c
OBJS = $(SRCS_C:.c=.o)
LIBS = $(LIBDIR)/libnssweb.a

.PHONY: all
all: $LIBDIR/libnssweb.a

$LIBDIR/libnssweb.a: $OBJDIR/nsshttp.o

$OBJDIR/nsshttp.o: $SRCDIR/nsshttp.c

.PHONY: clean
clean:
	$(RM) 