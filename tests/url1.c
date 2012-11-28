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

#include <stdio.h>
#include <nssurl.h>
#include <nss_mutable_string.h>

#define URL_A "http://labs.notsosoft.net:80/test.cgi#anchor"

void die(const char *msg) {
	printf("Dying: %s\n", msg);
	exit(1);
}

int main(void) {
	url_t a;
	mutable_string_t a_str;

	mutable_string_init_with_value(&a_str, URL_A);

	if (!url_init(&a)) {
		die("Failed to init 'a'");
	}

	if (!url_parse(&a, &a_str)) {
		die("Failed to parse URL A");
	}

	url_free(&a);

	return 1;
}