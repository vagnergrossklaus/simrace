#ifndef SIMRACECORE_GLOBAL_H
#define SIMRACECORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMRACECORE_LIBRARY)
#define SIMRACECORE_EXPORT Q_DECL_EXPORT
#else
#define SIMRACECORE_EXPORT Q_DECL_IMPORT
#endif

#define SIMRACE_CORE_NAMEPACE_BEGIN namespace simrace { namespace core {
#define SIMRACE_CORE_NAMEPACE_END } }

#endif // SIMRACECORE_GLOBAL_H
