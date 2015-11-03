#ifndef POLYHEDRON_DEMO_H
#define POLYHEDRON_DEMO_H

#include <QtCore/qglobal.h>

#ifdef polyhedron_demo_EXPORTS
#  define POLYHEDRON_DEMO_EXPORT Q_DECL_EXPORT
#else
#  define POLYHEDRON_DEMO_EXPORT Q_DECL_IMPORT
#endif

#include <QApplication>
#include <QScopedPointer>

struct Polyhedron_demo_impl;

class POLYHEDRON_DEMO_EXPORT Polyhedron_demo : public QApplication
{
  bool d_ptr_is_initialized; /// can be false during a call to `notify()`
  QScopedPointer<Polyhedron_demo_impl> d_ptr;
public:
  /*!
   * Constructor : calls the constructor of QApplication
   */
  Polyhedron_demo(int& argc, char **argv,
                  QString application_name = "Polyhedron_3 demo",
                  QString main_window_title = "CGAL Polyhedron demo");

  /*!
   * Catches unhandled exceptions from all the widgets
   */
  bool notify(QObject* receiver, QEvent* event);

  /*! After a call to `do_not_catch_exceptions()`, unhandled exceptions are
      no longer caught
   */
  void do_not_catch_exceptions();

  /*! Call `QApplication::exec()` unless the main window is already closed
   */
  int try_exec();
}; // end class Polyhedron_demo

#endif // POLYHEDRON_DEMO_H
