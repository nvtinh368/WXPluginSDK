//
// Created by Administrator on 2019/4/23.
//

#include "include/sharedpreftools.h"

jint SharedPrefTools::GetIntValue(JNIEnv *env, jobject &spObj, const char *key) {

    jclass spClz = env->GetObjectClass(spObj);

    jmethodID getInt = env->GetMethodID(spClz, "getInt", "(Ljava/lang/String;I)I");

    jint result = env->CallIntMethod(spObj, getInt, env->NewStringUTF(key), 0);

    env->DeleteLocalRef(spClz);
    return result;
}
