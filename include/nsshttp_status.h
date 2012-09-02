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

// If you're looking for where I'm getting these values, look here:
// http://www.w3.org/Protocols/rfc2616/rfc2616-sec10.html

#ifndef __NSSHTTP_STATUS_H__
#define __NSSHTTP_STATUS_H__

// Information for these 
#define HTTP_STATUS_LINE_LENGTH 32
#define INIT_HTTP_STATUS_CODE_T(X) X = 0
#define INIT_HTTP_STATUS_LINE_T(X) X[0] = '\0'

typedef struct {
	short status;
	char line[HTTP_STATUS_LINE_LENGTH];
} http_status_t;

#define INIT_HTTP_STATUS_T(X)				\
	do {									\
		INIT_HTTP_STATUS_CODE_T(X.status);	\
		INIT_HTTP_STATUS_LINE_T(X.line);	\
	} while(0)
#define MAKE_HTTP_STATUS(status,line) (http_status_t){status,line}
#define HTTPSTAT_GET_LINE(X)				(X.line)

#define HTTPSTAT_NO_STATUS					0
#define HTTPSTATLINE_NO_STATUS				"0 No Status"
#define HTTPSTAT_IS_NO_STATUS(X)			((X).status == HTTPSTAT_NO_STATUS)


// OK
#define HTTPSTAT_OK							200
#define HTTPSTATLINE_OK						"200 OK"
#define HTTP_STATUS_OK \
	MAKE_HTTP_STATUS(HTTPSTAT_OK,HTTPSTATLINE_OK)

// Redirection
#define HTTPSTAT_MOVED						301
#define HTTPSTAT_REDIRECT					302
#define HTTPSTAT_FOUND 						HTTPSTAT_REDIRECT
#define HTTPSTAT_NOT_MODIFIED				304

// Non-fatal error
#define HTTPSTAT_BAD_REQUEST				400
#define HTTPSTAT_UNAUTHORIZED				401
#define HTTPSTAT_FORBIDDEN					403
#define HTTPSTAT_FILE_NOT_FOUND				404
#define HTTPSTAT_NOT_ALLOWED				405
#define HTTPSTAT_LENGTH_REQUIRED			411
#define HTTPSTAT_REQUEST_ENTITY_TOO_LARGE	413
#define HTTPSTAT_REQUEST_URI_TOO_LONG		414

// Fatal error
#define HTTPSTAT_INTERNAL_SERVER_ERROR		500
#define HTTPSTATLINE_INTERNAL_SERVER_ERROR	"500 Internal Server Error"
#define HTTP_STATUS_INTERNAL_SERVER_ERROR	\
	MAKE_HTTP_STATUS(\
		HTTPSTAT_INTERNAL_SERVER_ERROR,\
		HTTPSTATLINE_INTERNAL_SERVER_ERROR\
	)

#define HTTPSTAT_NOT_IMPLEMENTED			501
#define HTTPSTAT_SERVICE_UNAVAILABLE		503
#define HTTPSTAT_HTTP_VERSION_NOT_SUPPORTED	505



#endif
