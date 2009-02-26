
// -*- C++ -*-
// $Id$
// Definition for Win32 Export directives.
// This file is generated automatically by generate_export_file.pl RM
// ------------------------------
#ifndef RM_IMPL_EXPORT_H
#define RM_IMPL_EXPORT_H

#include "ace/config-all.h"

#if defined (TAO_AS_STATIC_LIBS)
#  if !defined (RM_IMPL_HAS_DLL)
#    define RM_IMPL_HAS_DLL 0
#  endif /* ! RM_IMPL_HAS_DLL */
#else
#  if !defined (RM_IMPL_HAS_DLL)
#    define RM_IMPL_HAS_DLL 1
#  endif /* ! RM_IMPL_HAS_DLL */
#endif

#if defined (RM_IMPL_HAS_DLL) && (RM_IMPL_HAS_DLL == 1)
#  if defined (RM_IMPL_BUILD_DLL)
#    define RM_Impl_Export ACE_Proper_Export_Flag
#    define RM_IMPL_SINGLETON_DECLARATION(T) ACE_EXPORT_SINGLETON_DECLARATION (T)
#    define RM_IMPL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_EXPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  else /* RM_IMPL_BUILD_DLL */
#    define RM_Impl_Export ACE_Proper_Import_Flag
#    define RM_IMPL_SINGLETON_DECLARATION(T) ACE_IMPORT_SINGLETON_DECLARATION (T)
#    define RM_IMPL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK) ACE_IMPORT_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#  endif /* RM_IMPL_BUILD_DLL */
#else /* RM_IMPL_HAS_DLL == 1 */
#  define RM_Impl_Export
#  define RM_IMPL_SINGLETON_DECLARATION(T)
#  define RM_IMPL_SINGLETON_DECLARE(SINGLETON_TYPE, CLASS, LOCK)
#endif /* RM_IMPL_HAS_DLL == 1 */

// Set RM_IMPL_NTRACE = 0 to turn on library specific tracing even if
// tracing is turned off for ACE.
#if !defined (RM_IMPL_NTRACE)
#  if (ACE_NTRACE == 1)
#    define RM_IMPL_NTRACE 1
#  else /* (ACE_NTRACE == 1) */
#    define RM_IMPL_NTRACE 0
#  endif /* (ACE_NTRACE == 1) */
#endif /* !RM_IMPL_NTRACE */

#if (RM_IMPL_NTRACE == 1)
#  define RM_IMPL_TRACE(X)
#else /* (RM_IMPL_NTRACE == 1) */
#  if !defined (ACE_HAS_TRACE)
#    define ACE_HAS_TRACE
#  endif /* ACE_HAS_TRACE */
#  define RM_IMPL_TRACE(X) ACE_TRACE_IMPL(X)
#  include "ace/Trace.h"
#endif /* (RM_IMPL_NTRACE == 1) */

#endif /* RM_IMPL_EXPORT_H */

