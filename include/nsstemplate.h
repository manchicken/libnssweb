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

#ifndef __NSSTEMPLATE_H__
#define __NSSTEMPLATE_H__

#include <stdio.h>
#include <stdlib.h>
#include <nssweb_types.h>

static char path_separator = '/';

#define TPL_FILE_PATH_LENGTH 	256
#define TPL_BUFFER_LENGTH		2048
#define TPL_ERRSTR_LENGTH		(TPL_BUFFER_LENGTH + 1025)

#define ERR_FATAL_YES			1
#define ERR_FATAL_NO			0

#define ERR_TPL_CONTENT_YES		1
#define ERR_TPL_CONTENT_NO		0

typedef struct {
	short is_fatal;
	short is_template_content;
	int errnum;
	char errstr[TPL_ERRSTR_LENGTH];
} template_error_t;

#define INIT_TEMPLATE_ERROR_T(X)						\
	do {												\
		(X).errstr[0] = '\0';							\
		(X).is_fatal = ERR_FATAL_NO;					\
		(X).is_template_content = ERR_TPL_CONTENT_NO;	\
		(X).errnum = 0;									\
	} while(0)

typedef struct {
	char base_path[TPL_FILE_PATH_LENGTH];
	char template_file[TPL_FILE_PATH_LENGTH];
	FILE* instream;
	char *buffer;
	template_error_t err;
} template_context_t;

#define INIT_TEMPLATE_CONTEXT_T(X)						\
	do {												\
		(X).base_path[0] = '\0';						\
		(X).template_file[0] = '\0';					\
		(X).instream = NULL;							\
		(X).buffer = malloc(2 * sizeof(char));			\
		(X).buffer[0] = '\0';							\
		INIT_TEMPLATE_ERROR_T((X).err);					\
	} while(0)

#define TEMPLATE_CHECK_ERROR(X)	((X).err.errstr[0] == '\0')

extern continue_t template_init(
	template_context_t* ctx,
	char* path,
	const char* template_file
);

extern continue_t template_finish(template_context_t *ctx);

#endif