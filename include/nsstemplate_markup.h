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

#ifndef __NSSTEMPLATE_MARKUP_H__
#define __NSSTEMPLATE_MARKUP_H__

#define NST_MACROSTART_LEFT		"<%"
#define NST_MACROSTART_RIGHT	"%>"
#define NST_MACROSTOP_LEFT		"<%/"
#define NST_MACROSTOP_RIGHT		"%>"

#define NST_KEYWORD_IF_START		"if"
#define NST_KEYWORD_IF_ELSE			"else"
#define NST_KEYWORD_IF_STOP			"endif"
#define NST_KEYWORD_LOOP_CONDITION	"condition"
#define NST_KEYWORD_LOOP_START		"loop"
#define NST_KEYWORD_LOOP_STOP		"endloop"

#define NST_OPERATOR_ASSIGN		":="
#define NST_OPERATOR_EQ			"=="

#define NST_MAX_BUFFER_SIZE		4096

void handle_keyword_if_start(template_context_t *ctx, char *)


#endif