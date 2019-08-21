//
// Created by Administrator on 2019/4/2.
//

#include "include/helper.h"


//  调用 xposed findClass 方法
jclass Helper::FindClass(JNIEnv *env, const char *className, const jobject &classLoader) {

    //  find xposed class
    jclass xposedHelpers_clz = env->FindClass("de/robv/android/xposed/XposedHelpers");

    //  get xposed method "findClass" mid
    //  method description : cd clz.class location , then input cmd : javap -s clzName
    jmethodID findClass_func = env->GetStaticMethodID(xposedHelpers_clz,
                                                      "findClass",
                                                      "(Ljava/lang/String;Ljava/lang/ClassLoader;)Ljava/lang/Class;");

    //  execute xposed findClass method
    jclass target_clz = (jclass) env->CallStaticObjectMethod(xposedHelpers_clz,
                                                             findClass_func,
                                                             env->NewStringUTF(className),
                                                             classLoader);
    env->DeleteLocalRef(xposedHelpers_clz);
    return target_clz;
}


//  调用 xposed callStaticMethod
jobject Helper::CallStaticMethod(JNIEnv *env, const jclass &targetClass, const char *methodName,
                                 const jobjectArray &params) {

    jclass xposedHelper_clz = env->FindClass("de/robv/android/xposed/XposedHelpers");

    jmethodID callStaticMethod_func = env->GetStaticMethodID(xposedHelper_clz,
                                                             "callStaticMethod",
                                                             "(Ljava/lang/Class;Ljava/lang/String;[Ljava/lang/Object;)Ljava/lang/Object;");

    jobject target_obj = env->CallStaticObjectMethod(xposedHelper_clz,
                                                     callStaticMethod_func,
                                                     targetClass,
                                                     env->NewStringUTF(methodName),
                                                     params);
    env->DeleteLocalRef(xposedHelper_clz);
    return target_obj;
}

//  获取构造函数的签名
jmethodID
Helper::GetConstructor(JNIEnv *env, jclass &targetClass, const char *description) {
    return env->GetMethodID(targetClass, "<init>", description);
}

//  获取方法的签名
jmethodID Helper::GetMethod(JNIEnv *env, jclass &targetClass, const char *methodName,
                            const char *description) {
    return env->GetMethodID(targetClass, methodName, description);
}

//  根据对象获取类
jclass Helper::GetObjectClass(JNIEnv *env, jobject &obj) {
    return env->GetObjectClass(obj);
}

//  获取静态方法的签名
jmethodID Helper::GetStaticMethod(JNIEnv *env, jclass &targetClass, const char *methodName,
                                  const char *description) {
    return env->GetStaticMethodID(targetClass, methodName, description);
}

jobject
Helper::GetStaticField(JNIEnv *env, jclass &clz, const char *fieldName, const char *description) {
    jfieldID target_field = env->GetStaticFieldID(clz, fieldName, description);
    jobject target_obj = env->GetStaticObjectField(clz, target_field);
    return target_obj;
}

/**
 * 返回一个空的数组
 * @param env
 * @return
 */
jobjectArray Helper::GetNullParams(JNIEnv *env) {
    jclass object_clz = env->FindClass("java/lang/Object");
    jobjectArray arr = env->NewObjectArray(0, object_clz, NULL);
    env->DeleteLocalRef(object_clz);
    return arr;
}

