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

#ifndef __NSSHTTP_CONTENT_TYPE_H__
#define __NSSHTTP_CONTENT_TYPE_H__

#include <nssweb_config.h>


#define HTTP_CONTENT_TYPE_SET(dest,val)	strcpy(dest, val)

#define CONTENT_TYPE_TEXT_PLAIN		"text/plain"
#define CONTENT_TYPE_TEXT_HTML		"text/html"

#define INIT_HTTP_CONTENT_TYPE(X) strcpy(X,CONTENT_TYPE_TEXT_PLAIN)

#endif