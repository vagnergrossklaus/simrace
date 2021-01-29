#ifndef SIMRACECOMPONENTQML_GLOBAL_H
#define SIMRACECOMPONENTQML_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SIMRACECOMPONENTQML_LIBRARY)
#define SIMRACECOMPONENTQML_EXPORT Q_DECL_EXPORT
#else
#define SIMRACECOMPONENTQML_EXPORT Q_DECL_IMPORT
#endif

#define SIMRACE_CORE_NAMEPACE_BEGIN                                            \
  namespace simrace {                                                          \
  namespace component {                                                        \
  namespace qml {
#define SIMRACE_CORE_NAMEPACE_END                                              \
  }                                                                            \
  }                                                                            \
  }

#endif // SIMRACECOMPONENTQML_GLOBAL_H
