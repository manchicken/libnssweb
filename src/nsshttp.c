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

#define __NSSHTTP_C__

#include <nsshttp.h>
#include <nsshttpio.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

continue_t http_init(http_context_t *ctx, FILE* stream) {
	INIT_HTTP_CONTEXT_T(*ctx);
	ctx->stream = stream;

	// Let's init the environment a bit.
	char *script_filename = getenv(ENV_SCRIPT_FILENAME);
	if (script_filename == NULL) {
		http_die(ctx, "Ack! No SCRIPT_FILENAME environment variable!");
	}

	return CONTINUE_YES;
}

void http_set_status(http_context_t *ctx, http_status_t to_assign) {
	http_status_t *ptr = &(ctx->response_header.status);
	ptr->status = to_assign.status;
	strcpy(ptr->line, to_assign.line);

	return;
}

void http_set_content_type(http_context_t *ctx, const char* cnt_type) {
	strcpy(ctx->response_header.content_type, cnt_type);

	return;
}


continue_t http_output(
	http_context_t *ctx,
	const char* output
) {
	if (ctx->response_header.status.status == HTTPSTAT_NO_STATUS) {
		http_set_status(ctx, HTTP_STATUS_OK); // No news is good news, yeah?
		httpio_print_header(
			ctx->stream,
			HTTP_HEADER_STATUS,
			HTTPSTAT_GET_LINE(ctx->response_header.status)
		);
	}

	// Output headers
	httpio_print_header(ctx->stream, HTTP_HEADER_CONTENT_TYPE, ctx->response_header.content_type);

	// Done with headers...
	httpio_finish_headers(ctx->stream);

	fputs(output, ctx->stream);

	return CONTINUE_YES;
}

continue_t http_finish(http_context_t *ctx) {
	httpio_finish_output(ctx->stream);

	return CONTINUE_YES;
}

void http_die(http_context_t *ctx, char* errmsg) {
	char *use_msg = errmsg;

	if (errmsg == NULL && ctx->err.errstr[0] == '\0') {
		use_msg = HTTP_UNKNOWN_ERROR;
	} else if (errmsg == NULL) {
		use_msg = ctx->err.errstr;
	}

	if (HTTPSTAT_IS_NO_STATUS(ctx->response_header.status)) {
		http_set_status(ctx, HTTP_STATUS_INTERNAL_SERVER_ERROR);
	}
	http_output(ctx, use_msg);

	exit(ctx->err.is_fatal); // Going down!
}