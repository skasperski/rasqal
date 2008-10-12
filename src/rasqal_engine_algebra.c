/* -*- Mode: c; c-basic-offset: 2 -*-
 *
 * rasqal_engine.c - Rasqal query engine
 *
 * Copyright (C) 2004-2008, David Beckett http://www.dajobe.org/
 * Copyright (C) 2004-2005, University of Bristol, UK http://www.bristol.ac.uk/
 * 
 * This package is Free Software and part of Redland http://librdf.org/
 * 
 * It is licensed under the following three licenses as alternatives:
 *   1. GNU Lesser General Public License (LGPL) V2.1 or any newer version
 *   2. GNU General Public License (GPL) V2 or any newer version
 *   3. Apache License, V2.0 or any newer version
 * 
 * You may not use this file except in compliance with at least one of
 * the above three licenses.
 * 
 * See LICENSE.html or LICENSE.txt at the top of this package for the
 * complete terms and further detail along with the license texts for
 * the licenses in COPYING.LIB, COPYING and LICENSE-2.0.txt respectively.
 * 
 * 
 */

#ifdef HAVE_CONFIG_H
#include <rasqal_config.h>
#endif

#ifdef WIN32
#include <win32_rasqal_config.h>
#endif

#include <stdio.h>
#include <string.h>
#ifdef HAVE_STDLIB_H
#include <stdlib.h>
#endif
#include <stdarg.h>

#include "rasqal.h"
#include "rasqal_internal.h"


typedef struct {
  rasqal_query* query;
  rasqal_query_results* query_results;
} rasqal_engine_algebra_data;



static int
rasqal_query_engine_algebra_execute_init(void* ex_data,
                                         rasqal_query* query,
                                         rasqal_query_results* query_results,
                                         int flags,
                                         rasqal_engine_error *error_p)
{
  rasqal_engine_algebra_data* execution_data;

  execution_data=(rasqal_engine_algebra_data*)ex_data;

  /* initialise the execution_data fields */
  execution_data->query = query;
  execution_data->query_results = query_results;

  return 0;
}


static raptor_sequence*
rasqal_query_engine_algebra_get_all_rows(void* ex_data,
                                         rasqal_engine_error *error_p)
{
  return NULL;
}


static rasqal_row*
rasqal_query_engine_algebra_get_row(void* ex_data,
                                    rasqal_engine_error *error_p)
{
  return NULL;
}


static int
rasqal_query_engine_algebra_execute_finish(void* ex_data,
                                           rasqal_engine_error *error_p)
{
  return 1;
}


static void
rasqal_query_engine_algebra_finish_factory(rasqal_query_execution_factory* factory)
{
  return;
}


const rasqal_query_execution_factory rasqal_query_engine_algebra =
{
  /* .name=                */ "rasqal query algebra query engine",
  /* .execution_data_size= */ sizeof(rasqal_engine_algebra_data),
  /* .execute_init=        */ rasqal_query_engine_algebra_execute_init,
  /* .get_all_rows=        */ rasqal_query_engine_algebra_get_all_rows,
  /* .get_row=             */ rasqal_query_engine_algebra_get_row,
  /* .execute_finish=      */ rasqal_query_engine_algebra_execute_finish,
  /* .finish_factory=      */ rasqal_query_engine_algebra_finish_factory
};