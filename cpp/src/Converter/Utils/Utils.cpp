/** </src/Converter/Utils/Utils.cpp>
*
*  Written by Enea Scaccabarozzi
*  In date 2022-03-09
* 
*  @description: This file rapresent the definition
*  of the Utils class
*  
*  @declaration: See declarations for this file at 
*  </src/Converter/Utils/Utils.h>
*
*/

#include "Utils.h"
using IMAGE_ASCII::CONVERTER::UTILS::Utils;

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
bool Utils::resize_img(Image &img, size_t size)
{
    try
    {
        if (img.columns() <= size && img.rows() <= size)
            return true;

        size_t scale_factor = (img.columns() > img.rows()) ? img.columns() / size : img.rows() / size;

        img.resize(Magick::Geometry(img.columns() / scale_factor, img.rows() / scale_factor));
    } catch ( exception &error_) 
    {
        return false;
    }

    return true;
}


