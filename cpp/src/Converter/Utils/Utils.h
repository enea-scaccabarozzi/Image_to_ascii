/** </src/Converter/Utils/Utils.h>
*
*  Written by Enea Scaccabarozzi
*  In date 2022-03-09
* 
*  @description: This file rapresent an header that 
*  implement a class wich is going to handle utility
*  functions that make easier the conversion for the
*  Conversion object 
*  
*  @definition: See definitions for this file at 
*  </src/Converter/Utils/Utils.cpp>
*
*/

#ifndef UTILS_INC_FLAG
#define UTILS_INC_FLAG

#include <Magick++.h>
using Magick::Image;
using Magick::Geometry;

#include <exception>
using std::exception;

namespace IMAGE_ASCII::CONVERTER::UTILS
{
    class Utils
    {
    protected:

    public:
        /** Member function resize_img(Magick::Image, size_t).
        *
        *  @description: Resize input image keeping aspect ratio to
        *  a size also given in input
        *
        *  @param img Magick::Image object to be resized
        *  @param size Max dimension to resize
        *
        *  @return: True if image is correctly resized,
        *  false otherwise
        *  
        */
        bool resize_img(Image &img, size_t size);
    };
    

}


#endif /* UTILS_INC_FLAG */