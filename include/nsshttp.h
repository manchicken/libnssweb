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

#include <stdio.h>

#include <nssweb_config.h>
#include <nssweb_types.h>
#include <nsshttp_status.h>
#include <nsshttp_content_type.h>

// Definition of strings used in the protocol
typedef struct {
	char key[CFG_QS_KEY_LENGTH];
	int key_len;

	char value[CFG_QS_VALUE_LENGTH];
	int value_len;
} qs_entry_t;

#define INIT_QS_ENTRY_T(X)				\
	do {								\
		(X).key[0] = '\0';				\
		(X).key_len = 0;				\
		(X).value[0] = '\0';			\
		(X).value_len = 0;				\
	} while(0)


typedef struct {
	qs_entry_t entries[CFG_QS_ENTRY_LIMIT];
	int entries_len;
} query_string_t;

#define INIT_QUERY_STRING_T(X)			\
	do {								\
		INIT_QS_ENTRY_T(X.entries[0]);	\
		X.entries_len = 0;				\
	} while(0)


typedef struct {
	char request_uri[CFG_REQUEST_URI_LENGTH];
} http_request_header_t;

#define INIT_HTTP_REQUEST_HEADER_T(X)	\
	do {								\
		X.request_uri[0] = '\0';		\
	} while(0)


typedef struct {
	http_status_t status;
	char content_type[CFG_CONTENT_LENGTH_LIMIT];
} http_response_header_t;

#define INIT_HTTP_RESPONSE_HEADER_T(X)				\
	do {											\
		INIT_HTTP_STATUS_T((X).status);				\
		INIT_HTTP_CONTENT_TYPE((X).content_type);	\
	} while(0)

#define HTTP_ERRSTR_LENGTH			4096
#define HTTP_ERROR_SOURCE_CLIENT	1
#define HTTP_ERROR_SOURCE_SERVER	2
#define HTTP_UNKNOWN_ERROR			"Unknown error"
#define HTTP_ERROR_FATAL_YES		1
#define HTTP_ERROR_FATAL_NO			0
typedef struct {
	char errstr[HTTP_ERRSTR_LENGTH];
	int errnum;
	int error_source;
	int is_fatal;
} http_error_t;
#define INIT_HTTP_ERROR_T(X)							\
	do {												\
		(X).errstr[0] = '\0';							\
		(X).errnum = 0;									\
		(X).error_source = HTTP_ERROR_SOURCE_SERVER;	\
		(X).is_fatal = HTTP_ERROR_FATAL_NO;				\
	} while(0)

#define PATH_LENGTH 256
typedef struct {
	http_error_t err;
	query_string_t query_string;
	http_request_header_t request_header;
	http_response_header_t response_header;
	FILE* stream;

	char script_file[PATH_LENGTH];
	char script_path[PATH_LENGTH];
} http_context_t;

#define INIT_HTTP_CONTEXT_T(X)								\
	do {													\
		INIT_HTTP_ERROR_T((X).err);							\
		INIT_QUERY_STRING_T((X).query_string);				\
		INIT_HTTP_REQUEST_HEADER_T((X).request_header);		\
		INIT_HTTP_RESPONSE_HEADER_T((X).response_header);	\
		(X).stream = (FILE*)NULL;							\
		(X).script_file[0] = '\0';							\
		(X).script_path[0] = '\0';							\
	} while(0)

// Here are some header values
#define HTTP_HEADER_STATUS			"Status"
#define HTTP_HEADER_CONTENT_TYPE	"Content-type"

#define ENV_SCRIPT_FILENAME			"SCRIPT_FILENAME"

// Set up the HTTP context and session
extern continue_t http_init(http_context_t *ctx, FILE* stream);

extern void http_set_status(http_context_t *ctx, http_status_t to_assign);
extern void http_set_content_type(http_context_t *ctx, const char* cnt_type);

// Output some content
extern continue_t http_output(http_context_t *ctx, const char* output);

// Clean up
extern continue_t http_finish(http_context_t *ctx);

// Error out
extern void http_die(http_context_t *ctx, char* errmsg);

#endif