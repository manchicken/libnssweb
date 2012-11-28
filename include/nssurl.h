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

#ifndef __NSSURL_H__
#define __NSSURL_H__

#include <nss_mutable_string.h>

typedef enum {
	HTTP,
	HTTPS,
	FTP,
	SFTP
} scheme_t;

typedef struct {
	mutable_string_t endpoint;

	mutable_string_t host;
	unsigned short port;
} endpoint_t;

typedef struct {
	mutable_string_t uri;

	mutable_string_t path;
	mutable_string_t file;
	mutable_string_t anchor;
} uri_t;

// Definition of strings used in the protocol
typedef struct {
	mutable_string_t key;
	mutable_string_t value;
} qs_entry_t;

typedef struct {
	qs_entry_t *entries;
	int entries_len;
} query_string_t;

typedef struct {
	mutable_string_t url;

	scheme_t proto_scheme;

	endpoint_t endpoint;

	uri_t uri;

	query_string_t query_string;
} url_t;

// Housekeeping for endpoints
endpoint_t* endpoint_init(endpoint_t *target);
void endpoint_free(endpoint_t *target);

// Housekeeping for URIs
uri_t* uri_init(uri_t *target);
void uri_free(uri_t *target);

// Housekeeping for Query Strings
query_string_t* qs_init(query_string_t *target);
void qs_free(query_string_t *target);

// Housekeeping for URLs
url_t* url_init(url_t *target);
void url_free(url_t *target);

// Work with URLs
url_t* url_parse(url_t *output, mutable_string_t *input);
mutable_string_t* url_construct(url_t *input);

#endif