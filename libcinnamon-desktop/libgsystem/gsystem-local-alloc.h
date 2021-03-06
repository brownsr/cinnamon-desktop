/* -*- mode: C; c-file-style: "gnu"; indent-tabs-mode: nil; -*-
 *
 * Copyright (C) 2012 Colin Walters <walters@verbum.org>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street - Suite 500,
 * Boston, MA 02110-1335, USA.
 */

#ifndef __GSYSTEM_LOCAL_ALLOC_H__
#define __GSYSTEM_LOCAL_ALLOC_H__

#include <gio/gio.h>

G_BEGIN_DECLS

void gs_local_free (void *loc);
void gs_local_obj_unref (void *loc);
void gs_local_variant_unref (void *loc);
void gs_local_ptrarray_unref (void *loc);
void gs_local_hashtable_unref (void *loc);

#define gs_lfree __attribute__ ((cleanup(gs_local_free)))
#define gs_lobj __attribute__ ((cleanup(gs_local_obj_unref)))
#define gs_lvariant __attribute__ ((cleanup(gs_local_variant_unref)))
#define gs_lptrarray __attribute__ ((cleanup(gs_local_ptrarray_unref)))
#define gs_lhash __attribute__ ((cleanup(gs_local_hashtable_unref)))

G_END_DECLS

#endif
