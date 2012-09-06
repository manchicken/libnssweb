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

mutable_string_t* mutable_string_init(mutable_string_t *target) {
	target->data = NULL;
	target->is_empty = 'Y';
	target->_data_size = 0;

	return 	mutable_string_resize(target, (INITIAL_MUTABLE_STRING_ALLOCATION*sizeof(char)));
}

mutable_string_t* mutable_string_resize(mutable_string_t* target, size_t new_size) {
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
	free(target->data);
	target->is_empty = 'Y';
	target->_data_size = 0;
	target->length = 0;

	return;
}

mutable_string_t* mutable_string_assign(mutable_string_t *dest, char *src) {
	size_t src_length = strlen(src);

	// Grow the string if necessary
	if (src_length > dest->_data_size) {
		if (mutable_string_resize(dest,(src_length+1)*sizeof(char)) == NULL) {
			return NULL;
		}

		dest->_data_size = src_length+1;
	} // We don't shrink the string!

	strcpy(dest->data, src);
	dest->length = src_length;

	return dest;
}

mutable_string_t* mutable_string_append(mutable_string_t *dest, char *src) {
	return NULL;
}

int mutable_string_get_length(mutable_string_t *var) {
return 0;
}

short mutable_string_is_empty(mutable_string_t *var) {
return 0;
}

char* mutable_string_get_data(mutable_string_t *var) {
return NULL;
}

mutable_string_t* mutable_string_clone(mutable_string_t *var) {
return NULL;
}

mutable_string_t* mutable_string_copy(mutable_string_t *dest, mutable_string_t *src) {
return NULL;
}
