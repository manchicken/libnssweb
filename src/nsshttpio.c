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

#include <nsshttpio.h>

int httpio_print_header(FILE* stream, const char* field, const char* value) {
	return fprintf(stream, "%s: %s%s", field, value, HTTPIO_HEADER_LINE_ENDING);
}

int httpio_finish_headers(FILE* stream) {
	return fputs(HTTPIO_HEADER_FINISH, stream);
}

void httpio_finish_output(FILE* stream) {
	fputs(HTTPIO_HEADER_LINE_ENDING, stream);
	fputs(HTTPIO_HEADER_LINE_ENDING, stream);

	return;
}