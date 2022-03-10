/** </src/Converter/Converter.cpp>
*
*  Written by Enea Scaccabarozzi
*  In date 2022-03-09
* 
*  @description: This file rapresent the definition
*  of the Converter class
*  
*  @declaration: See declarations for this file at 
*  </src/Converter/Converter.h>
*
*/

#include "Converter.h"
using IMAGE_ASCII::CONVERTER::Image_to_ascii;

/** Constructor 1 ().
*
*  @description: Load object with default alphabet
*
*/
Image_to_ascii::Image_to_ascii()
{
    _alphabet = " .,:;ox%#@";
    _utils_handler = new Utils;
    _ascii = "";
}

/** Constructor 2 (C++ STL string).
*
*  @param alph The used alphabet for conversion
*
*/
Image_to_ascii::Image_to_ascii(const string &alph)
{
    _alphabet = alph;
    _utils_handler = new Utils;
    _ascii = "";
}

/** Destructor.
*
*  @description: Allow memory managment
*
*/
Image_to_ascii::~Image_to_ascii()
{
    delete _utils_handler;
}

/** Member function load(S++ STL string).
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
bool Image_to_ascii::load(const string &path, size_t max_size)
{
    try
    {
        _img.read(path);
        _utils_handler->resize_img(_img, max_size);
    }
    catch (const exception &error_)
    {
        throw(Except("Couldn't load image file correctly", "/src/Converter/Converter.cpp", "Image_to_ascii.load(std::string&, unsigned int)", 54));
        return false;
    }
    return true;
}

/** Member function run().
*
*  @description: Actually convert image to ascii art
*
*  @return: True if image is correctly converted,
*  false otherwise
*  
*/
bool Image_to_ascii::run()
{
    try
    {
        _img.modifyImage();
        for (size_t row = 0; row <= _img.rows(); row++)
        {
            for (size_t col = 0; col <= _img.columns(); col++)
            {
                Magick::ColorRGB px = _img.pixelColor(col, row);
                size_t intensity = (0.3 * px.red() * 255) + (0.59 * px.green() * 255) + (0.11 * px.blue() * 255);
                _ascii += _alphabet[(255 - intensity) * _alphabet.length() / 256];
            }
            _ascii += '\n';
        }
    }
    catch (const exception &error_)
    {
        throw(Except("Couldn't convert image correctly", "/src/Converter/Converter.cpp", "Image_to_ascii.run()", 89));
        return false;
    }
    return true;
}

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
bool Image_to_ascii::save(const string &path)
{
    try
    {
        ofstream file;
        file.open(path);

        file << _ascii;

        file.close();
    }
    catch (const exception &error_)
    {
        throw(Except("Couldn't write to output file correctly", "/src/Converter/Converter.cpp", "Image_to_ascii.save(std::string&)", 132));
        return false;
    }
    return true;
}
