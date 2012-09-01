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

#ifndef __NSSHTTP_STATUS_H__
#define __NSSHTTP_STATUS_H__

// Information for these 

typedef unsigned short http_status_t;

// OK
#define HTTPSTAT_OK						(http_status_t)200

// Redirection
#define HTTPSTAT_MOVED					(http_status_t)301
#define HTTPSTAT_REDIRECT				(http_status_t)302
#define HTTPSTAT_FOUND 					HTTPSTAT_REDIRECT
#define HTTPSTAT_NOT_MODIFIED			(http_status_t)304

// Non-fatal error
#define HTTPSTAT_BAD_REQUEST			(http_status_t)400
#define HTTPSTAT_UNAUTHORIZED			(http_status_t)401
#define HTTPSTAT_FORBIDDEN				(http_status_t)403
#define HTTPSTAT_FILE_NOT_FOUND			(http_status_t)404
#define HTTPSTAT_NOT_ALLOWED			(http_status_t)

// Fatal error

#endif