//
// Created by Administrator on 2019/4/23.
//

#ifndef WXPLUGINSDK_SHAREDPREFTOOLS_H
#define WXPLUGINSDK_SHAREDPREFTOOLS_H

#include <jni.h>

//  SharedPreferences tools
class SharedPrefTools {
public:
    static jint GetIntValue(JNIEnv *env, jobject &spObj, const char *key);
};


#endif //WXPLUGINSDK_SHAREDPREFTOOLS_H
