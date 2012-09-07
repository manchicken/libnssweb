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

#include <nsstemplate_markup.h>
#include <strmap.h>

static StrMap *_tpl_symbols;

char* markup_find_token(const char *buffer, const char *token) {
	if (buffer == NULL || strnlen(buffer, NST_MAX_BUFFER) == 0) {
		return NULL;
	}

	return strnstr(buffer, token, NST_MAX_BUFFER);
}

const char* markup_which_token_is_this(const char *buffer) {
	
	if (strncmp(chunk, NST_MARKUPSTART_LEFT,
		strlen(NST_MARKUPSTART_LEFT)) == 0)
	{
		return NST_MARKUPSTART_LEFT;

	} else if (strncmp(chunk, NST_MARKUPSTART_RIGHT,
		strlen(NST_MARKUPSTART_RIGHT)) == 0)
	{
		return NST_MARKUPSTART_RIGHT;

	} else if (strncmp(chunk, NST_MARKUPSTOP_LEFT,
		strlen(NST_MARKUPSTOP_LEFT)) == 0)
	{
		return NST_MARKUPSTOP_LEFT;

	} else if (strncmp(chunk, NST_MARKUPSTOP_RIGHT,
		strlen(NST_MARKUPSTOP_RIGHT)) == 0)
	{
		return NST_MARKUPSTOP_RIGHT;
	}

	return NULL;
}

// void handle_keyword_if_start(template_context_t *ctx, char *instruction) {
// 	return;
// }