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

#include <nssurl.h>

// Housekeeping for endpoints
endpoint_t* endpoint_init(endpoint_t *target) {
	if (!mutable_string_init(&(target->endpoint)))
		return NULL;

	if (!mutable_string_init(&(target->host)))
		return NULL;

	target->port = 80;
	return target;
}
void endpoint_free(endpoint_t *target) {
	mutable_string_free(&(target->endpoint));
	mutable_string_free(&(target->host));

	return;
}

// Housekeeping for URIs
uri_t* uri_init(uri_t *target) {
	if (!mutable_string_init(&(target->uri)))
		return NULL;
	if (!mutable_string_init(&(target->path)))
		return NULL;
	if (!mutable_string_init(&(target->file)))
		return NULL;
	if (!mutable_string_init(&(target->anchor)))
		return NULL;

	return target;
}
void uri_free(uri_t *target) {
	mutable_string_free(&(target->uri));
	mutable_string_free(&(target->path));
	mutable_string_free(&(target->file));
	mutable_string_free(&(target->anchor));
	return;
}

// Housekeeping for URLs
url_t* url_init(url_t *target) {
	return NULL;
}
void url_free(url_t *target) {
	return;
}

// Housekeeping for Query Strings
query_string_t* qs_init(query_string_t *target) {
	return NULL;
}
void qs_free(query_string_t *target) {
	return;
}

// Work with URLs
url_t* url_parse(url_t *output, mutable_string_t *input) {
	return NULL;
}

mutable_string_t* url_construct(url_t *input) {
	return NULL;
}
