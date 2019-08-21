//
// Created by Administrator on 2019/4/24.
//

#include "include/cursor.h"

jint Cursor::GetCount(JNIEnv *env, jobject &cursor_obj) {

    jclass cursor_clz = env->FindClass("android/database/Cursor");

    jmethodID getCount_mid = env->GetMethodID(cursor_clz, "getCount", "()I");

    jint count = env->CallIntMethod(cursor_obj, getCount_mid);

    env->DeleteLocalRef(cursor_clz);
    return count;
}


jboolean Cursor::MoveToNext(JNIEnv *env, jobject &cursor_obj) {

    jclass cursor_clz = env->FindClass("android/database/Cursor");

    jmethodID moveToNext_mid = env->GetMethodID(cursor_clz, "moveToNext", "()Z");

    jboolean result = env->CallBooleanMethod(cursor_obj, moveToNext_mid);

    env->DeleteLocalRef(cursor_clz);
    return result;
}


jstring Cursor::GetString(JNIEnv *env, jobject &cursor_obj, jint &key) {
    jclass cursor_clz = env->FindClass("android/database/Cursor");

    jmethodID getString_mid = env->GetMethodID(cursor_clz, "getString", "(I)Ljava/lang/String;");

    jstring result = (jstring) env->CallObjectMethod(cursor_obj, getString_mid, key);

    env->DeleteLocalRef(cursor_clz);
    return result;
}


jint Cursor::GetColumnIndex(JNIEnv *env, jobject &cursor_obj, const char *key) {
    jclass cursor_clz = env->FindClass("android/database/Cursor");

    jmethodID getColumnIndex_mid = env->GetMethodID(cursor_clz,
                                                    "getColumnIndex",
                                                    "(Ljava/lang/String;)I");

    jstring name = env->NewStringUTF(key);
    jint result = env->CallIntMethod(cursor_obj, getColumnIndex_mid, name);

    env->DeleteLocalRef(cursor_clz);
    env->DeleteLocalRef(name);
    return result;
}


void Cursor::Close(JNIEnv *env, jobject &cursor_obj) {
    jclass cursor_clz = env->FindClass("android/database/Cursor");

    jmethodID close_mid = env->GetMethodID(cursor_clz,
                                           "close",
                                           "()V");

    env->CallObjectMethod(cursor_obj, close_mid);

    env->DeleteLocalRef(cursor_clz);
}


