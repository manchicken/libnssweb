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
TESTDIR = ./tests

CC = gcc
AR = ar -cr
RANLIB = ranlib
RM = rm -f

CFLAGS = -fPIC -ggdb3 -I$(INCDIR) -Wall

# Sources
LIBNSSHTTP_SRCS = \
	$(SRCDIR)/nss_mutable_string.c \
	$(SRCDIR)/nsshttp.c \
	$(SRCDIR)/nsshttpio.c \
	$(SRCDIR)/nssurl.c \

LIBNSSTEMPLATE_SRCS = \
	$(SRCDIR)/nsstemplate.c \
	$(SRCDIR)/strmap.c \
	$(SRCDIR)/nss_mutable_string.c \

TESTS_SRCS = \
	$(TESTDIR)/template1.c \
	$(TESTDIR)/url1.c \

# Objects
LIBNSSHTTP_OBJS = \
	$(OBJDIR)/strmap.o \
	$(OBJDIR)/nsshttp.o \
	$(OBJDIR)/nsshttpio.o \
	$(OBJDIR)/nssurl.o \

LIBNSSTEMPLATE_OBJS = \
	$(OBJDIR)/nsstemplate.o \
	$(OBJDIR)/nsstemplate_markup.o \
	$(OBJDIR)/strmap.o \
	$(SRCDIR)/nss_mutable_string.o \

TESTS_OBJS = \
	$(OBJDIR)/template1.o \
	$(OBJDIR)/url1.o \

# Libraries
LIBS = \
	$(LIBDIR)/libnsshttp.a \
	$(LIBDIR)/libnsstemplate.a \

# Binaries
TESTS = \
	$(TESTDIR)/template1.test \
	$(TESTDIR)/url1.test \

# Flags
TESTS_CFLAGS = -L$(LIBDIR) -lc -lnsstemplate -lnsshttp

.PHONY: all
all: $(LIBS) $(TESTS)
	ctags -R -f .tags

# Tests
$(TESTDIR)/template1.test: $(OBJDIR)/template1.o
	$(CC) -o $@ $(TESTS_CFLAGS) $<

$(TESTDIR)/url1.test: $(OBJDIR)/url1.o
	$(CC) -o $@ $(TESTS_CFLAGS) $<

# Libs
$(LIBDIR)/libnsshttp.a: $(LIBNSSHTTP_OBJS)
	$(AR) $@ $(LIBNSSHTTP_OBJS)
	$(RANLIB) $@

$(LIBDIR)/libnsstemplate.a: $(LIBNSSTEMPLATE_OBJS)
	$(AR) $@ $(LIBNSSTEMPLATE_OBJS)
	$(RANLIB) $@

# Other stuff (generic)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

$(OBJDIR)/%.o: $(TESTDIR)/%.c
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:
	$(RM) $(OBJDIR)/*.o $(LIBDIR)/*.a $(TESTS)

.PHONY: tags
tags:
	ctags -R -f .tags
