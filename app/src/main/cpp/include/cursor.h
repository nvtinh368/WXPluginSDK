//
// Created by Administrator on 2019/4/24.
//

#ifndef WXPLUGINSDK_CURSOR_H
#define WXPLUGINSDK_CURSOR_H


#include <jni.h>

class Cursor {
public:
    static jint GetCount(JNIEnv *env, jobject &cursor_obj);

    static jboolean MoveToNext(JNIEnv *env, jobject &cursor_obj);

    static jstring GetString(JNIEnv *env, jobject &cursor_obj, jint &key);

    static jint GetColumnIndex(JNIEnv *env, jobject &cursor_obj, const char *key);

    static void Close(JNIEnv *env, jobject &cursor_obj);
};


#endif //WXPLUGINSDK_CURSOR_H
