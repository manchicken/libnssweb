/*
 * libnssweb - Copyright (C) 2012 Michael D. Stemle, Jr.
 *
 * This file is part of libnssweb.
 *
 * libnssweb is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * libnssweb is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with libnssweb. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __NSSHTTPIO_H__
#define __NSSHTTPIO_H__

#include <stdio.h>

#define HTTPIO_LINE_ENDING "\n"
#define HTTPIO_HEADER_LINE_ENDING "\r\n"
#define HTTPIO_HEADER_FINISH "\r\n\r\n"

extern int httpio_print_line(FILE* stream, const char* output);
extern int httpio_print_header(FILE* stream, const char* field, const char* value);
extern int httpio_finish_headers(FILE* stream);
extern void httpio_finish_output(FILE* stream);

#endif