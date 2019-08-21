#ifndef WXPLUGINSDK_SYSTOOLS_H
#define WXPLUGINSDK_SYSTOOLS_H


#include <jni.h>
#include <string>

using namespace std;

class SysTools {
public:
    static jobject GetSystemContext(JNIEnv *env);

    static jobject GetContext(JNIEnv *env, const char *pkgName);

    static string GetVersion(JNIEnv *env, const char *pkgName);

    static jobject GetSharedPref(JNIEnv *env, const char *pkgName, const char *sharedPrefName);

    static string GetIMEI(JNIEnv *env);
};


#endif //WXPLUGINSDK_SYSTOOLS_H
