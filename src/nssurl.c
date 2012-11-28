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
#include <stdlib.h>

// Housekeeping for endpoints
endpoint_t* endpoint_init(endpoint_t *target) {
	if (!mutable_string_init(&(target->endpoint))) {
		return NULL;
	}

	if (!mutable_string_init(&(target->host))) {
		return NULL;
	}

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
	if (!mutable_string_init(&(target->uri))) {
		return NULL;
	}
	if (!mutable_string_init(&(target->path))) {
		return NULL;
	}
	if (!mutable_string_init(&(target->file))) {
		return NULL;
	}
	if (!mutable_string_init(&(target->anchor))) {
		return NULL;
	}

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
qs_entry_t* qs_entry_init(qs_entry_t *target) {
	if (!mutable_string_init(&(target->key))) {
		return NULL;
	}
	if (!mutable_string_init(&(target->value))) {
		return NULL;
	}

	return target;
}
void qs_entry_free(qs_entry_t *target) {
	if (!target) {
		return;
	}
	mutable_string_free(&(target->key));
	mutable_string_free(&(target->value));

	return;
}

query_string_t* qs_init(query_string_t *target) {
	if (!qs_resize(target, DEFAULT_QS_SIZE)) {
		return NULL;
	}

	return target;
}
void qs_free(query_string_t *target) {
	int entry_idx = 0;

	if (!target) {
		return;
	}

	for (entry_idx = 0; entry_idx < target->entries_len; entry_idx += 1) {
		qs_entry_free(&(target->entries[entry_idx]));
	}

	free(target->entries);
	target->entries_len = 0;

	return;
}

query_string_t* qs_resize(query_string_t *target, int count)
{
	size_t new_size = count * sizeof(qs_entry_t);
	int entry_idx = 0;

	// this check is for security and memory management
	if (count > MAX_QS_SIZE) {
		return NULL;
	}

	qs_entry_t *check_ptr = (qs_entry_t*)realloc(target->entries, new_size);

	// If we're out of memory, don't trash the existing value, let the caller handle it!
	if (check_ptr == NULL && new_size > 0) {
		return NULL;
	}
	target->entries = check_ptr;

	target->entries_len = count;

	for (entry_idx = 0; entry_idx < target->entries_len; entry_idx += 1) {
		if (!qs_entry_init(&(target->entries[entry_idx]))) {
			return NULL;
		}
	}

	return target;
}

int qs_length(query_string_t *target) {
	return target->entries_len;
}


// Work with URLs
url_t* url_parse(url_t *output, mutable_string_t *input) {
	return NULL;
}

mutable_string_t* url_construct(url_t *input) {
	return NULL;
}
