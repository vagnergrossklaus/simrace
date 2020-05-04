#ifndef SIMRACEDEMO_GLOBAL_H
#define SIMRACEDEMO_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMRACEDEMO_LIBRARY)
#define SIMRACEDEMO_EXPORT Q_DECL_EXPORT
#else
#define SIMRACEDEMO_EXPORT Q_DECL_IMPORT
#endif

#define SIMRACE_DEMO_NAMEPACE_BEGIN                                            \
  namespace simrace {                                                          \
  namespace demo {
#define SIMRACE_DEMO_NAMEPACE_END                                              \
  }                                                                            \
  }

#endif // SIMRACEDEMO_GLOBAL_H
