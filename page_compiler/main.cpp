/*!
 * @file main.cpp
 *
 * @brief PageCompiler is a command line tool that translates HTML files (and
 * other kinds of files) into C++ code, more precisely, subclasses of
 * Poco::Net::HTTPRequestHandler.
 *
 * @details The source files can contain special directives that allow embedding 
 * of C++ code. The syntax of these directives is based on the syntax used for Java
 * Server Pages (JSP), Active Server Pages (ASP) or Embedded JavaScript (EJS)
 * templating.
 * This makes PageCompiler a C++-based HTML templating system. Since the
 * translation of the HTML template into a C++ class happens at compile time,
 * runtime performance is excellent.
 *
 * Link:
 * https://pocoproject.org/docs/PageCompilerUserGuide.html
 * 
 * @todo Understand functionality. =)
 */
#include "PageCompiler.hpp"

POCO_APP_MAIN(CompilerApp)