/*
 * My custom errno extension library
 * Copyright (C) 2023  Sabrina Andersen (NukingDragons)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <error.h>
#include <string.h>

// Custom errno strings
// Add the relevant enum values in "error.h"
// The +1 is so that the "Unknown error" string can be allocated
static const char *const __custom_errno_str[(MAX_CUSTOM_ERRNO - INT_MIN) + 1] =
{
	"Unknown argument",
	"Too few arguments",

	// Custom error strings
#ifdef __CUSTOM_ERRNO_STRS
	__CUSTOM_ERRNO_STRS
#endif

	// This needs to be the final error string
	"Unknown error"
};

const char *const errorstr(const int32_t err)
{
	const char *r = 0;

	// Custom errno value
	if (err < 0)
		if (err < (MAX_CUSTOM_ERRNO - INT_MIN))
			r = __custom_errno_str[err - INT_MIN];
		else
			r = __custom_errno_str[MAX_CUSTOM_ERRNO - INT_MIN];
	// Default errno value
	else
		r = strerror(err);

	return r;
}
