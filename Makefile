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
AR = ar -cr
RANLIB = ranlib
RM = rm -f

CFLAGS = -fPIC -ggdb3 -I$(INCDIR) -Wall

LIBNSSHTTP_SRCS = $(SRCDIR)/nsshttp.c $(SRCDIR)/nsshttpio.c
LIBNSSTEMPLATE_SRCS = $(SRCDIR)/nsstemplate.c $(SRCDIR)/strmap.c $(SRCDIR)/nss_mutable_string.c

LIBNSSHTTP_OBJS = $(OBJDIR)/nsshttp.o $(OBJDIR)/nsshttpio.o
LIBNSSTEMPLATE_OBJS = $(OBJDIR)/nsstemplate.o $(OBJDIR)/strmap.o $(SRCDIR)/nss_mutable_string.o

LIBS = $(LIBDIR)/libnsshttp.a $(LIBDIR)/libnsstemplate.a
#LIBS = $(LIBDIR)/libnsshttp.a

.PHONY: all
all: $(LIBS)
	ctags -R -f .tags

$(LIBDIR)/libnsshttp.a: $(LIBNSSHTTP_OBJS)
	$(AR) $@ $(LIBNSSHTTP_OBJS)
	$(RANLIB) $@

$(LIBDIR)/libnsstemplate.a: $(LIBNSSTEMPLATE_OBJS)
	$(AR) $@ $(LIBNSSTEMPLATE_OBJS)
	$(RANLIB) $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:
	$(RM) $(OBJDIR)/*.o $(LIBDIR)/*.a

.PHONY: tags
tags:
	ctags -R -f .tags
