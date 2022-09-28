
/* error.c - error functions
 * Copyright (C) 2004 Matthias Czapla <dermatsch@gmx.de>
 *
 * This file is part of cue2toc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 */
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdarg.h>

const char *prog = "program";

/* Fatal error related to system call. Print program name, user supplied
   arguments and the cause for the error. */
void
err_sys(const char *s, ...)
{
	va_list ap;
	int errno_save = errno;

	fprintf(stderr, "%s: ", prog);
	va_start(ap, s);
	vfprintf(stderr, s, ap);
	va_end(ap);
	fprintf(stderr, ": %s\n", strerror(errno_save));

	exit(EXIT_FAILURE);
}

/* Fatal error not related to system call. Print program name and user
   supplied arguments. */
void
err_quit(const char *s, ...)
{
	va_list ap;

	fprintf(stderr, "%s: ", prog);
	va_start(ap, s);
	vfprintf(stderr, s, ap);
	va_end(ap);
	fprintf(stderr, "\n");

	exit(EXIT_FAILURE);
}
