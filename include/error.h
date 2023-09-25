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

#ifndef _ERROR_H_
#define _ERROR_H_

#include <stdint.h>
#include <errno.h>
#include <limits.h>

// Helpers for the custom_errnos.h file
#define __push_errno_defs	_Pragma("push_macro(\"__CUSTOM_ERRNO_DEFS\")")
#define __pop_errno_defs	_Pragma("pop_macro(\"__CUSTOM_ERRNO_DEFS\")")
#define __push_errno_strs	_Pragma("push_macro(\"__CUSTOM_ERRNO_STRS\")")
#define __pop_errno_strs	_Pragma("pop_macro(\"__CUSTOM_ERRNO_STRS\")")

// Define this as nothing so that the rules in the next include work properly
#undef __CUSTOM_ERRNO_DEFS
#define __CUSTOM_ERRNO_DEFS
#undef __CUSTOM_ERRNO_STRS
#define __CUSTOM_ERRNO_STRS

// Custom errnos
// Sets the error enums with __CUSTOM_ERRNO_DEFS
// Sets the error strings with __CUSTOM_ERRNO_STRS
#include <custom_errnos.h>

// Custom errno values
// Add the relevant strings in "error.c"
enum __custom_errno_enum
{
	// Start of the custom errno values, set to INT_MIN for logic later on
	// These errors have been used enough between different programs to deserve being permanent
	EUNKARG = INT_MIN,
	ETOOFEW,

	// Custom errno defs
#ifdef __CUSTOM_ERRNO_DEFS
	__CUSTOM_ERRNO_DEFS
#endif

	// End of the custom errno values
	MAX_CUSTOM_ERRNO,
	ESUCCESS = 0
};

// Macro the assist in setting errno, if and only if it's not already set
#define set_errno(err)	(errno = (errno != 0) ? errno : err)

// The error.c file shouldn't be built into a library, but the above enum is fine to populate and use
// When in a library, define __CUSTOM_ERRNO_LIBRARY at compile time
#ifndef __CUSTOM_ERRNO_LIBRARY
// Custom errno string handler, passes through to default errno handler when needed
const char *const errorstr(const int32_t err);
#endif

#endif
