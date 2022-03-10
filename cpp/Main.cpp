#include <iostream>
using std::cerr;
using std::endl;
using std::exception;

#include "src/Image_to_ascii.h"
using IMAGE_ASCII::CONVERTER::Image_to_ascii;
using IMAGE_ASCII::EXCEPTIONS::Except;

int main()
{
  try
  {
    Image_to_ascii Converter;
    Converter.load("../../Cat.jpg", 120);

    Converter.run();

    Converter.save("out.txt");

  } catch (Except &error_)
  {
    cerr << "[RUNTIME ERROR]: " << endl;
    cerr << error_.what() << endl;
  }
}