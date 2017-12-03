#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
#AC_INIT([FULL-PACKAGE-NAME], [VERSION], [BUG-REPORT-ADDRESS])
AC_INIT([ShuanglongServer], [1.0])
AC_CONFIG_SRCDIR([src/main.cpp])
AM_INIT_AUTOMAKE
AC_CONFIG_HEADERS([config.h])

# enable debug or release feature
AC_ARG_ENABLE([debug],
              [AS_HELP_STRING([--enable-debug],[output debug log(default is no)])],
              [if test "$enableval"=="yes"; then
                   AC_DEFINE([DEBUG],[1],[Define if --enable-debug])
               else
                   AC_DEFINE([DEBUG],[0],[Define if --disable-debug])
               fi
              ],
              [AC_DEFINE([DEBUG],[0],[Define if need to output debug log])])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB

# Checks for libraries.

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 src/utils/Makefile])
AC_OUTPUT
