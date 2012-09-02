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

#include <nsstemplate.h>
#include <assert.h>
#include <sys/errno.h>
#include <string.h>

void template_set_error_to_errno(
	template_context_t* ctx,
	short is_fatal,
	short is_template_content)
{
	template_error_t *ptr = &(ctx->err);
	INIT_TEMPLATE_ERROR_T(*ptr);
	ptr->errnum = errno;
	strerror_r(errno, ptr->errstr, TPL_ERRSTR_LENGTH);

	return;
}

continue_t template_init(
	template_context_t* ctx,
	char* path,
	const char* template_file)
{
	INIT_TEMPLATE_CONTEXT_T(*ctx);
	strcpy(ctx->base_path, path);
	sprintf(ctx->template_file, "%s%c%s", path, path_separator, template_file);

	ctx->instream = fopen(ctx->template_file, "r");

	// If we don't
	if (ctx->instream == NULL) {
		template_set_error_to_errno(ctx, ERR_FATAL_YES, ERR_TPL_CONTENT_NO);
		return CONTINUE_NO;
	}

	return CONTINUE_YES;
}

continue_t template_finish(template_context_t *ctx) {
	// Close the stream if it's open.
	if (ctx->instream != NULL) {
		if (fclose(ctx->instream) == EOF) {
			template_set_error_to_errno(ctx, ERR_FATAL_YES, ERR_TPL_CONTENT_NO);
			return CONTINUE_NO;
		}
	}

	return CONTINUE_YES;
}