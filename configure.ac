AC_INIT([SL], [0.0.1-prealpha], [https://github.com/ponyatov/SL/tree/dev])
AM_INIT_AUTOMAKE([foreign])
# -Wall -Werror 

AC_PROG_CXX
AC_PROG_LEX
AC_PROG_YACC

AC_LANG([C++])

AC_CONFIG_FILES([ Makefile src/Makefile ])
AC_CONFIG_HEADERS([config.h])

AC_CONFIG_SRCDIR([src/cpp.cpp])

#AC_DEFINE([Msz], [0x1000], [VM memory size])

AC_CHECK_PROGS(FLEX, [flex --version])
AC_CHECK_PROGS(BISON, [bison --version])

AC_CHECK_PROG(WX_CONFIG, wx-config, wx-config)
if test x$WX_CONFIG == x; then
	AC_MSG_ERROR([no wxWidgets])
fi

AC_ARG_ENABLE(wx, wxWidgets)
WX_CXXFLAGS=$($WX_CONFIG --cxxflags core)
AC_SUBST([WX_CXXFLAGS])
WX_LIBS=$($WX_CONFIG --libs core)
AC_SUBST([WX_LIBS])

AC_OUTPUT
