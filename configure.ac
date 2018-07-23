AC_INIT([SL], [0.0.1-prealpha], [https://github.com/ponyatov/SL/tree/dev])
AM_INIT_AUTOMAKE([foreign])
# -Wall -Werror 

AC_PROG_CXX
AC_PROG_LEX
AC_PROG_YACC

AC_CONFIG_FILES([ Makefile src/Makefile ])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_SRCDIR([src/cpp.cpp])

#AC_DEFINE([Msz], [0x1000], [VM memory size])

AC_CHECK_PROGS(FLEX, [flex --version])
AC_CHECK_PROGS(BISON, [bison --version])

AC_CHECK_PROG(HAVE_WX_CONFIG, wx-config, yes, no)
if test x$HAVE_WX_CONFIG == xno; then
	AC_MSG_ERROR([no wxWidgets])
fi
if test x$HAVE_WX_CONFIG == xyes; then
	AC_ARG_ENABLE(wx, wxWidgets)
fi

#PKG_CHECK_MODULES(WX, [wx])
#AC_CHECK_HEADER([wx/wx.h])

AC_OUTPUT
