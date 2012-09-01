#
# libnssweb - Copyright (C) 2012 Michael D. Stemle, Jr.
#
# This file is part of libnssweb.
#
# libnssweb is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# libnssweb is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with libnssweb. If not, see <http://www.gnu.org/licenses/>.

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