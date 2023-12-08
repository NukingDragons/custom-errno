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

/*
 * If you do not want to add custom errnos, do NOT make this file in your include directory
 * If you're using a library that does produce this file, it will be included
 * automatically by the "error.h" header.
 * If you're using several libraries that produce this file, you MUST create this file
 * If neither you nor a library you're using include this file, there is a stubbed
 * out "custom_errnos.h" header that has already been created for you
 *
 * This "custom_errnos.h" file should be placed into the first include directory
 * in the search path when compiling, this makes this library completely modular
 * such that libraries using this can be included by including their respective
 * "custom_errnos.h" file(s) here using their absolute path.
 *
 * For example, place this header into the "include/custom_errnos.h" file
 * And then place `#include <path/to/library/include/custom_errnos.h"` into the above file
 * Do this for every library you wish to use that has this header file
 * Then execute: `gcc -Iinclude/ -Ilibrary/include -llibrary test.c -o test`
 *
 * If you do want to add your own custom errnos, the __push_errno_x/__pop_errno_x macros
 * have been provided by the header that will include this file.
 * Do NOT include this header yourself, simply include "error.h" and set your include search
 * path appropriately
 *
 * To append to the custom errnos, the following sequences must be obeyed
 * Adjust these as you need
 */
__push_errno_defs
#undef __CUSTOM_ERRNO_DEFS
#define __CUSTOM_ERRNO_DEFS __pop_errno_defs __CUSTOM_ERRNO_DEFS	\
	EEXAMPLE,														\
	EEXAMPLE2,

__push_errno_strs
#undef __CUSTOM_ERRNO_STRS
#define __CUSTOM_ERRNO_STRS __pop_errno_strs __CUSTOM_ERRNO_STRS	\
	"Example Error 1",												\
	"Example Error 2",
