/** </src/Exceptions/Except.cpp>
*
*  Written by Enea Scaccabarozzi
*  In date 2022-03-09
* 
*  @description: This file rapresent the definition
*  of the custom Exception class for this project
*  
*  @declaration: See declarations for this file at 
*  </src/Exceptions/Except.h>
*
*/

#include "Except.h"
using IMAGE_ASCII::EXCEPTIONS::Except;

/** Constructor (C++ STL string, C++ STL string, C++ STL string, int).
*
*  @param msg The error message
*  @param file File that throw exception
*  @param func Function that throw exception
*  @param line Line's number that throw exception
*
*/
Except::Except(const string &msg, const string &file, const string &func, int line)
{
    _info = (msg);
    _file = (file);
    _func = (func);
    _line = line;
    _what = "";
}

/** Destructor.
*
*  @description: Virtual to allow for subclassing.
*
*/
Except::~Except() noexcept
{

}

/** Member function what().
*
*  @description: Returns a pointer to the (constant) error description,
*  comprensive of all error's data available 
*
*  @return: A pointer to a const char*. 
*  The underlying memory is in possession of the Except
*  object. Callers must not attempt to free the memory.
*  
*/
const char* Except::what() noexcept
{
    _what = "\t[INFO]: " + _info + "\n" +
    _what += "\t[IN FILE]: " + _file + "\n";
    _what += "\t[IN FUNCTION]: " + _func + "\n";
    _what += "\t[AT LINE]: " + std::to_string(_line) + "\n";

    return _what.c_str();
}