

#include <iostream>
#include <fstream>
#include "crc32c.h"
using namespace std;

int main(int argc, char* argv[]) {

    if (argc == 1) {
        cout<<"please input filepath!"<<endl;
        exit(1);
    }
    //cout<<"file: "<<argv[1]<<endl;
    const string filename = argv[1];
        char * buffer;
        long size;
        ifstream in (filename, ios::in|ios::binary|ios::ate);
        size = in.tellg();
        in.seekg (0, ios::beg);
        buffer = new char [size];
        in.read (buffer, size);
        in.close();
//        cout << "the complete file is in a buffer: "<<buffer<<endl;
//    cout<<"size: "<<size<<endl;

//  const std::uint8_t buffer1[] = {1, 0, 0, 0};
//  const std::uint8_t buffer2[] = {1, 0, 0, 0, 0, 0};
  std::uint32_t result;



  // Process a raw buffer.
  result = crc32c::Crc32c(buffer, size);
          delete[] buffer;

  //cout<<result<<endl;

  // Process a std::string.
  //std::string string = "12345678";
//  string.resize(4);
  //result = crc32c::Crc32c(string);

  cout<<result<<endl;

  // If you have C++17 support, process a std::string_view.
// std::string_view string_view(string);
//  result = crc32c::Crc32c(string_view);

  return 0;
}
