//
// Created by Administrator on 2019/4/23.
//

#ifndef WXPLUGINSDK_WXTOOLS_H
#define WXPLUGINSDK_WXTOOLS_H


#include <jni.h>
#include <string>

using namespace std;

class WXTools {
public :
    static string GetUinCode(JNIEnv *env);

    static string GetCurrentDir(JNIEnv *env);

    static string GetDBPassword(JNIEnv *env);

    static jobject OpenDatabase(JNIEnv *env, jobject &classLoader);

    static jobject RawQuery(JNIEnv *env, jobject &classLoader, string &sql, jobjectArray &obj_arr);
};


#endif //WXPLUGINSDK_WXTOOLS_H
