//
// Created by Administrator on 2019/4/3.
//

#ifndef WXPLUGINSDK_FILETOOLS_H
#define WXPLUGINSDK_FILETOOLS_H


class FileTools {
public:
    static void Copy(const char *src, const char *dest);

    static int GetFileLength(const char *filePath);

};


#endif //WXPLUGINSDK_FILETOOLS_H
