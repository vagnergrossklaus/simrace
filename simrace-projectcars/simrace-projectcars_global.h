#ifndef SIMRACEPROJECTCARS_GLOBAL_H
#define SIMRACEPROJECTCARS_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMRACEPROJECTCARS_LIBRARY)
#define SIMRACEPROJECTCARS_EXPORT Q_DECL_EXPORT
#else
#define SIMRACEPROJECTCARS_EXPORT Q_DECL_IMPORT
#endif

#define SIMRACE_PROJECTCARS_NAMEPACE_BEGIN                                     \
  namespace simrace {                                                          \
  namespace projectcars {
#define SIMRACE_PROJECTCARS_NAMEPACE_END                                       \
  }                                                                            \
  }

#endif // SIMRACEPROJECTCARS_GLOBAL_H
