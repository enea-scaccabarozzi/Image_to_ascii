/** </src/Exceptions/Except.h>
*
*  Written by Enea Scaccabarozzi
*  In date 2022-03-09
* 
*  @description: This file rapresent an header that 
*  implement an exension of C++ STL exception with most 
*  suitable error displayment
*  
*  @definition: See definitions for this file at 
*  </src/Exceptions/Except.cpp>
*
*/

#ifndef EXCEPT_INC_FLAG
#define EXCEPT_INC_FLAG

#include <string>
using std::string;

#include <exception>
using std::exception;

namespace IMAGE_ASCII::EXCEPTIONS
{
    class Except : public std::exception 
    {
    protected: 
        string _info;    /* << Error description */
        string _file;    /* << File that throw exception */
        string _func;    /* << Function that throw exception */
        int _line;       /* << Line's number that throw exception */
        string _what;     /* << Comprensive summary */
        
        public:
            /** Constructor (C++ STL string, C++ STL string, C++ STL string, int).
            *
            *  @param msg The error message
            *  @param file File that throw exception
            *  @param func Function that throw exception
            *  @param line Line's number that throw exception
            *
            */
            Except(const string &msg, const string &file, const string &func, int line);

            /** Destructor.
            *
            *  @description: Virtual to allow for subclassing.
            *
            */
            virtual ~Except() noexcept;

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
            virtual const char* what() noexcept;
        
    };
}

#endif /* EXCEPT_INC_FLAG */