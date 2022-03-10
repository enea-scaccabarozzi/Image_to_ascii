#include <Magick++.h>
#include <iostream>

using namespace std;

void resize(Magick::Image &img){
  cout << "Image.width(): " << img.columns() << endl;
  cout << "Image.height(): " << img.rows() << endl;

  if (img.columns() <= 100 && img.rows() <= 200)
    return;

  size_t scale_factor = (img.columns() > img.rows()) ? img.columns() / 200 : img.rows() / 200;

  img.resize(Magick::Geometry(img.columns() / scale_factor, img.rows() / scale_factor));

  cout << "[NEW]  Image.width(): " << img.columns() << endl;
  cout << "[NEW]  Image.height(): " << img.rows() << endl;

  return;
}

string convert(Magick::Image &img, string &str){
  cout << "[>>] Starting conversion..." << endl;
  cout << "Image width: " << img.columns()<< endl;
  cout << "Image height: " << img.rows() << endl;
  cout << "Image channels: " << img.channels() << endl;

  img.modifyImage();
  
  string alphabet = " .,:;ox%#@";

  str = "";

  for ( int row = 0; row <= img.rows(); row++ ){
    for ( int column = 0; column <= img.columns(); column++ ){
      Magick::ColorRGB px = img.pixelColor( column, row );
      int intensity = (0.3*px.red()*255) + (0.59*px.green()*255) + (0.11*px.blue()*255);
      //cout << "I[" << column << ";" << row << "]:" << intensity << " -> " << alphabet[(255-intensity)*alphabet.length()/256] << endl;
      str += alphabet[(255-intensity)*alphabet.length()/256]; 
      // std::cout << "P[" << column << ";" << row << "]:  R= " << (int)(px.red()*255) << " G= " << (int)(px.green()*255) <<" B: " << (int)(px.blue()*255) << std::endl;
    }
    str += '\n';
  }

  return "";
}

void print_to_file(string &str){
  cout<<str<<endl;

  return;
}

int main(){
  try
  {
    Magick::Image img;
    img.read("../../Cat.jpg");

    resize(img);

    string result;
    convert(img, result);

    print_to_file(result);
  }
  catch ( const exception &error_ )
  {
    cerr << "Caught exception: " << error_.what() << endl;
    return 1;
  }

  return 0;
}
