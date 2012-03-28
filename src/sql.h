/* OpenVAS Manager
 * $Id$
 * Description: Headers for OpenVAS Manager: the SQL library.
 *
 * Authors:
 * Matthew Mundell <matthew.mundell@greenbone.net>
 *
 * Copyright:
 * Copyright (C) 2012 Greenbone Networks GmbH
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2,
 * or, at your option, any later version as published by the Free
 * Software Foundation
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef OPENVAS_MANAGER_SQL_H
#define OPENVAS_MANAGER_SQL_H

#include "manage.h"  /* For iterator_t. */

#include <sqlite3.h>
#include <glib.h>

extern sqlite3 *
task_db;

gchar *
sql_nquote (const char *, size_t);

gchar *
sql_quote (const char *);

gchar *
sql_insert (const char *);

void
sql (char * sql, ...);

void
sql_quiet (char * sql, ...);

int
sql_x (unsigned int, unsigned int, char *, va_list, sqlite3_stmt **);

int
sql_int (unsigned int, unsigned int, char *, ...);

char *
sql_string (unsigned int, unsigned int, char *, ...);

int
sql_int64 (long long int * ret, unsigned int, unsigned int, char *, ...);

void
sql_make_uuid (sqlite3_context *, int argc, sqlite3_value **);

void
sql_hosts_contains (sqlite3_context *, int argc, sqlite3_value **);

void
sql_clean_hosts (sqlite3_context *, int argc, sqlite3_value **);

void
sql_uniquify (sqlite3_context *, int argc, sqlite3_value **);

void
sql_iso_time (sqlite3_context *, int argc, sqlite3_value **);

void
sql_now (sqlite3_context *, int argc, sqlite3_value **);

void
sql_rename_column (const char *, const char *, const char *, const char *);


/* Iterators. */

void
init_iterator (iterator_t*, const char*, ...);

long long int
iterator_int64 (iterator_t*, int);

const char*
iterator_string (iterator_t*, int);

const char*
iterator_column_name (iterator_t*, int);

int
iterator_column_count (iterator_t*);

void
cleanup_iterator (iterator_t*);

gboolean
next (iterator_t*);

#endif /* not OPENVAS_MANAGER_SQL_H */
