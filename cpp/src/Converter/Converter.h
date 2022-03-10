/** </src/Converter/Converter.h>
*
*  Written by Enea Scaccabarozzi
*  In date 2022-03-09
* 
*  @description: This file rapresent an header that 
*  implement a class wich is going to handle ascii conversion
*  from image
*  
*  @definition: See definitions for this file at 
*  </src/Converter/Converter.cpp>
*
*/

#ifndef CONVERTER_INC_FLAG
#define CONVERTER_INC_FLAG

#include <Magick++.h>
using Magick::Image;

#include <string>
using std::string;

#include <exception>
using std::exception;

#include<fstream>
using std::ofstream;

#include "../Exceptions/Except.h"
using IMAGE_ASCII::EXCEPTIONS::Except;

#include "Utils/Utils.h"
using IMAGE_ASCII::CONVERTER::UTILS::Utils;

namespace IMAGE_ASCII::CONVERTER 
{

    class Image_to_ascii
    {
    protected:
        string _alphabet;       /* << Array of chars that are used for ascii art */
        string _ascii;          /* << Resultating ascii art */
        Image _img;             /* << Magick++ object for image handling */
        Utils* _utils_handler;   /* << Pointer to custom object for utility functions */

    public:
        /** Constructor 1 ().
        *
        *  @description: Load object with default alphabet
        *
        */
        Image_to_ascii();

        /** Constructor 2 (C++ STL string).
        *
        *  @param alph The used alphabet for conversion
        *
        */
        Image_to_ascii(const string &alph);

        /** Destructor.
        *
        *  @description: Allow memory managment
        *
        */
        ~Image_to_ascii();

        /** Member function load(C++ STL string).
        *
        *  @description: Tries to load image object from file path
        *
        *  @param path File name of imgage to be loaded
        *  @param max_size Side max dimension (both height and widht) 
        *
        *  @return: True if image is correctly loaded,
        *  false otherwise
        *  
        */
        bool load(const string &path, size_t max_size);

        /** Member function run().
        *
        *  @description: Actually convert image to ascii art
        *
        *  @return: True if image is correctly converted,
        *  false otherwise
        *  
        */
        bool run();

        /** Member function save(C++ STL string).
        *
        *  @description: Write converted string to output file
        * 
        *  @param path Path of ot file, it will be overwritten or crated
        *
        *  @return: True if the file is correctly written,
        *  false otherwise
        *  
        */
        bool save(const string &path);


    };

}


#endif /* CONVERTER_INC_FLAG */