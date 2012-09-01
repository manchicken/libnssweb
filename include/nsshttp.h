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

#ifndef __NSSHTTP_H__
#define __NSSHTTP_H__

#include <nssweb_config.h>
#include <nssweb_types.h>
#include <nsshttp_status.h>

// Definition of strings used in the protocol
typedef struct {
	char key[CFG_QS_KEY_LENGTH];
	int key_len;

	char value[CFG_QS_VALUE_LENGTH];
	int value_len;
} qs_entry_t;

#define INIT_QS_ENTRY_T(X)				\
	(X).key[0] = '\0';					\
	(X).key_len = 0;					\
	(X).value[0] = '\0';				\
	(X).value_len = 0;

typedef struct {
	qs_entry_t entries[CFG_QS_ENTRY_LIMIT];
	int entries_len;
} query_string_t;

typedef struct {
	char request_uri[CFG_REQUEST_URI_LENGTH];
} http_request_header_t;

typedef struct {
	http_status_t status;
	http_status_line_t status_line;
} http_response_header_t;

typedef struct {
	query_string_t query_string;
	http_request_header_t request_header;
	http_response_header_t response_header;
} http_context_t;

extern continue_t http_init(http_context_t *ctx);

#endif