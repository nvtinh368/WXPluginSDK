//
// Created by Administrator on 2019/3/31.
//

#ifndef TESTJNI_HELPER_H
#define TESTJNI_HELPER_H

#include <jni.h>

class Helper {
public:
    static jclass FindClass(JNIEnv *env, const char *className, const jobject &classLoader);

    static jobject
    CallStaticMethod(JNIEnv *env, const jclass &targetClass, const char *methodName,
                     const jobjectArray &params);

    static jmethodID
    GetConstructor(JNIEnv *env, jclass &targetClass, const char *description);

    static jmethodID
    GetMethod(JNIEnv *env, jclass &targetClass, const char *methodName, const char *description);

    static jmethodID
    GetStaticMethod(JNIEnv *env, jclass &targetClass, const char *methodName,
                    const char *description);

    static jclass
    GetObjectClass(JNIEnv *env, jobject &obj);

    static jobject
    GetStaticField(JNIEnv *env, jclass &clz, const char *fieldName, const char *description);

    static jobjectArray GetNullParams(JNIEnv *env);
};


#endif //TESTJNI_HELPER_H
