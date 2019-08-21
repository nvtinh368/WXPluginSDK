#include "include/systools.h"
#include <android/log.h>

#define TAG    "WXPluginSDK"
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,TAG,__VA_ARGS__)


/**
 * 获取应用版本
 */
string SysTools::GetVersion(JNIEnv *env, const char *pkgName) {

    jobject context_obj = GetContext(env, pkgName);

    jclass context_clz = env->GetObjectClass(context_obj);

    jmethodID getPackageManager_func =
            env->GetMethodID(context_clz, "getPackageManager",
                             "()Landroid/content/pm/PackageManager;");

    jclass object_clz = env->FindClass("java/lang/Object");
    jobjectArray obj_array = env->NewObjectArray(0, object_clz, NULL);

    jobject packageManager_obj = env->CallObjectMethod(context_obj,
                                                       getPackageManager_func,
                                                       obj_array);

    jclass packageManager_clz = env->GetObjectClass(packageManager_obj);

    jmethodID getPackageInfo_func =
            env->GetMethodID(packageManager_clz, "getPackageInfo",
                             "(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");

    jobject packageInfo_obj = env->CallObjectMethod(packageManager_obj,
                                                    getPackageInfo_func,
                                                    env->NewStringUTF(pkgName), 0);

    jclass packageInfo_clz = env->GetObjectClass(packageInfo_obj);

    jfieldID versionName_field = env->GetFieldID(packageInfo_clz, "versionName",
                                                 "Ljava/lang/String;");

    jstring versionName = (jstring) env->GetObjectField(packageInfo_obj,
                                                        versionName_field);

    const char *version = env->GetStringUTFChars(versionName, 0);
    std::string version_ = version;
    env->ReleaseStringUTFChars(versionName, version);

    env->DeleteLocalRef(context_obj);
    env->DeleteLocalRef(context_clz);
    env->DeleteLocalRef(object_clz);
    env->DeleteLocalRef(obj_array);
    env->DeleteLocalRef(packageManager_obj);
    env->DeleteLocalRef(packageManager_clz);
    env->DeleteLocalRef(packageInfo_obj);
    env->DeleteLocalRef(packageInfo_clz);
    return version_;
}


/**
 * 获取系统当前的context
 */
jobject SysTools::GetSystemContext(JNIEnv *env) {

    jclass activityThread_clz = env->FindClass("android/app/ActivityThread");
    jmethodID currentActivityThread_func = env->GetStaticMethodID(activityThread_clz,
                                                                  "currentActivityThread",
                                                                  "()Landroid/app/ActivityThread;");

    jobject at_obj = env->CallStaticObjectMethod(activityThread_clz,
                                                 currentActivityThread_func);

    jmethodID getSystemContext_func = env->GetMethodID(activityThread_clz,
                                                       "getSystemContext",
                                                       "()Landroid/app/ContextImpl;");

    jobject context_obj = env->CallObjectMethod(at_obj, getSystemContext_func);

    env->DeleteLocalRef(activityThread_clz);
    env->DeleteLocalRef(at_obj);
    return context_obj;
}


/**
 * 获取指定包名的context
 */
jobject SysTools::GetContext(JNIEnv *env, const char *pkgName) {
    jobject context_obj = SysTools::GetSystemContext(env);

    jclass context_clz = env->GetObjectClass(context_obj);

    jmethodID createPackageContext_func =
            env->GetMethodID(context_clz, "createPackageContext",
                             "(Ljava/lang/String;I)Landroid/content/Context;");

    jobject wxContext_obj = env->CallObjectMethod(context_obj,
                                                  createPackageContext_func,
                                                  env->NewStringUTF(pkgName), 2);

    env->DeleteLocalRef(context_obj);
    env->DeleteLocalRef(context_clz);
    return wxContext_obj;
}


/**
 * 获取指定包名的 sharedpreferences
 */
jobject SysTools::GetSharedPref(JNIEnv *env, const char *pkgName, const char *sharedPrefName) {
    jobject wxContext = GetContext(env, pkgName);

    jclass context_clz = env->GetObjectClass(wxContext);

    jmethodID getSharedPreferences_mid = env->GetMethodID(context_clz,
                                                          "getSharedPreferences",
                                                          "(Ljava/lang/String;I)Landroid/content/SharedPreferences;");

    jobject spObj = env->CallObjectMethod(wxContext,
                                          getSharedPreferences_mid,
                                          env->NewStringUTF(sharedPrefName),
                                          0);

    env->DeleteLocalRef(wxContext);
    env->DeleteLocalRef(context_clz);
    return spObj;
}


/**
 * 获取 imei
 */
string SysTools::GetIMEI(JNIEnv *env) {
    jobject context_obj = GetSystemContext(env);

    jclass context_clz = env->GetObjectClass(context_obj);

    jmethodID getSystemService_mid = env->GetMethodID(context_clz,
                                                      "getSystemService",
                                                      "(Ljava/lang/String;)Ljava/lang/Object;");

    jstring phone_jstr = env->NewStringUTF("phone");

    jobject telManager_obj = env->CallObjectMethod(context_obj, getSystemService_mid, phone_jstr);

    jclass telManager_clz = env->FindClass("android/telephony/TelephonyManager");

    jmethodID getDeviceId_mid = env->GetMethodID(telManager_clz, "getDeviceId",
                                                 "()Ljava/lang/String;");

    jstring imei_temp = (jstring) env->CallObjectMethod(telManager_obj, getDeviceId_mid);

    const char *imei_str = env->GetStringUTFChars(imei_temp, 0);
    string imei = imei_str;

    env->DeleteLocalRef(context_obj);
    env->DeleteLocalRef(context_clz);
    env->DeleteLocalRef(phone_jstr);
    env->DeleteLocalRef(telManager_obj);
    env->DeleteLocalRef(telManager_clz);
    env->DeleteLocalRef(imei_temp);
    return imei;
}
