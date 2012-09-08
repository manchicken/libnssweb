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

#ifndef __NSSWEB_CONFIG_H__
#define __NSSWEB_CONFIG_H__

///// There are no standards on these limits, so I'm making them configurable. Some of these may be a bit long

// The size limit of a query string key
#define CFG_QS_KEY_LENGTH 16

// The size limit of a query string value
#define CFG_QS_VALUE_LENGTH 64

// The maximum number of entries
#define CFG_QS_ENTRY_LIMIT 32

// The size limit for the query string
#define CFG_QUERY_STRING_LIMIT ( ( CFG_QS_KEY_LENGTH + CFG_QS_VALUE_LENGTH ) * CFG_QS_ENTRY_LIMIT )

// The size limit for the REQUEST_URI
#define CFG_REQUEST_URI_LENGTH 256

// The size limit for the Content-type
#define CFG_CONTENT_LENGTH_LIMIT 32

// An HTTP header entity length
#define CFG_HTTP_HEADER_ENTITY_LENGTH 32
#define CFG_HTTP_HEADER_LINE_LENGTH ((CFG_HTTP_HEADER_ENTITY_LENGTH*2)+5)

#define CFG_MAX_BUFFER_LENGTH	4096

#define DEBUG(...) fprintf(stderr, __VA_ARGS__)

#endif