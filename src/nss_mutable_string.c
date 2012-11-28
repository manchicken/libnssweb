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

#include <string.h>
#include <stdlib.h>
#include <nss_mutable_string.h>

inline size_t _calculate_new_size(size_t str_length) {
	return ((str_length + 1) * sizeof(char));
}

mutable_string_t* mutable_string_init(mutable_string_t *target) {
	target->data = NULL;
	target->is_empty = 'Y';
	target->_data_size = 0;

	return mutable_string_resize(target, (INITIAL_MUTABLE_STRING_ALLOCATION*sizeof(char)));
}

mutable_string_t* mutable_string_init_with_value(mutable_string_t *target, const char *value) {
	if (!mutable_string_init(target)) {
		return NULL;
	}

	if (!mutable_string_assign(target, value)) {
		return NULL;
	}

	return target;
}

mutable_string_t* mutable_string_resize(mutable_string_t* target, size_t new_size)
{
	// this check is for security and memory management
	if (new_size > MAXIMUM_MUTABLE_STRING_SIZE) {
		return NULL;
	}

	char *check_ptr = (char*)realloc(target->data, new_size);

	// If we're out of memory, don't trash the existing value, let the caller handle it!
	if (check_ptr == NULL && new_size > 0) {
		return NULL;
	}
	target->data = check_ptr;

	// Handle the string ending stuff...
	if (new_size < target->_data_size) {
		target->data[new_size-1] = '\0';

	} else if (target->length == 0) {
		target->data[0] = '\0';
	}

	target->_data_size = new_size;

	return target;
}

void mutable_string_free(mutable_string_t *target) {
	// Sometimes you get garbage...
	if (!target)
		return;

	free(target->data);
	target->is_empty = 'Y';
	target->_data_size = 0;
	target->length = 0;

	return;
}

mutable_string_t* mutable_string_assign(mutable_string_t *dest, char *src) {
	size_t src_length = strlen(src);
	size_t new_size = _calculate_new_size(src_length);

	// Grow the string if necessary
	if (new_size > dest->_data_size) {
		if (mutable_string_resize(dest,new_size) == NULL) {
			return NULL;
		}

	} // We don't shrink the string!

	strcpy(dest->data, src);
	dest->length = src_length;
	dest->is_empty = 'N';
	dest->_data_size = new_size;

	return dest;
}

mutable_string_t* mutable_string_append(mutable_string_t *dest, char *src) {
	if (mutable_string_is_empty(dest)) {
		return mutable_string_assign(dest, src);
	}

	size_t new_len = strlen(src) + dest->length;
	size_t new_size = _calculate_new_size(new_len);

	// Grow if necessary.
	if (new_size > dest->_data_size) {
		if (mutable_string_resize(dest, new_size) == NULL) {
			return NULL;
		}

	}

	strncat(dest->data, src, MAXIMUM_MUTABLE_STRING_SIZE);
	dest->length = new_len;
	dest->_data_size = new_size;
	dest->is_empty = 'N';

	return NULL;
}

int mutable_string_get_length(mutable_string_t *var) {
	return var->length;
}

short mutable_string_is_empty(mutable_string_t *var) {
	return (var->is_empty == 'Y');
}

char* mutable_string_get_data(mutable_string_t *var) {
	return var->data;
}

mutable_string_t* mutable_string_copy(mutable_string_t *dest, mutable_string_t *src)
{
	return mutable_string_assign(dest, mutable_string_get_data(src));
}
