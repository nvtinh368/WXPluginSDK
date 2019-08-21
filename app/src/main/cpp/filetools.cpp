//
// Created by Administrator on 2019/4/3.
//

#include "include/filetools.h"
#include <fstream>

using namespace std;

int FileTools::GetFileLength(const char *filePath) {
    ifstream f(filePath, ifstream::binary);

    if (f.is_open()) {
        ifstream::pos_type old = f.tellg();

        f.seekg(0, ifstream::beg);
        ifstream::pos_type start = f.tellg();

        f.seekg(0, ifstream::end);
        ifstream::pos_type end = f.tellg();

        f.seekg(old);
        f.close();
        return (int) (end - start);
    }
    return 0;
}

void FileTools::Copy(const char *src, const char *dest) {

    fstream src_file(src, ios::binary | ios::in | ios::ate);
    int fileLength = FileTools::GetFileLength(src);

    char *imgData = new char[fileLength];

    src_file.seekg(0);
    src_file.read(imgData, fileLength);

    fstream dest_file(dest, ios::binary | ios::out);
    dest_file.write(imgData, fileLength);


    src_file.close();
    dest_file.close();

    delete[] imgData;
}


