#include <jni.h>
#include <string>
#include <android/log.h>
#include "include/systools.h"
#include "include/message.h"
#include "include/wxtools.h"
#include "include/cursor.h"

#define TAG    "WXPluginSDK"
#define LOGW(...)  __android_log_print(ANDROID_LOG_WARN,TAG,__VA_ARGS__)

using namespace std;

extern "C" {

JNIEXPORT jstring JNICALL
Java_com_jyong_wxpluginsdk_NativeTools_stringFromJNI(JNIEnv *env, jobject instance) {

    LOGW("...");
    string version = SysTools::GetVersion(env, "com.tencent.mm");
    LOGW(" version %s ", version.c_str());
    LOGW("===");

    string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}


JNIEXPORT void JNICALL
Java_com_jyong_wxpluginsdk_NativeTools_text(JNIEnv *env, jclass type, jstring talker_,
                                            jstring content_, jobject classLoader) {

    Message::Text(env, talker_, content_, classLoader);
}

JNIEXPORT void JNICALL
Java_com_jyong_wxpluginsdk_NativeTools_image(JNIEnv *env, jclass type, jstring myWx_,
                                             jstring talker_, jstring imgPath_,
                                             jobject classLoader) {

    Message::Image(env, myWx_, talker_, imgPath_, classLoader);
}

JNIEXPORT void JNICALL
Java_com_jyong_wxpluginsdk_NativeTools_voice(JNIEnv *env, jclass type, jstring talker_,
                                             jstring localFilePath_, jobject classLoader) {

    Message::Voice(env, talker_, localFilePath_, classLoader);
}

JNIEXPORT void JNICALL
Java_com_jyong_wxpluginsdk_NativeTools_video(JNIEnv *env, jclass type, jstring talker_,
                                             jobject videoPath, jobject context,
                                             jobject classLoader) {

    Message::Video(env, talker_, videoPath, context, classLoader);
}

JNIEXPORT void JNICALL
Java_com_jyong_wxpluginsdk_NativeTools_card(JNIEnv *env, jclass type, jstring talker_,
                                            jstring cardOwner_, jobject classLoader) {

    Message::Card(env, talker_, cardOwner_, classLoader);
}

JNIEXPORT void JNICALL
Java_com_jyong_wxpluginsdk_NativeTools_subscriptionCard(JNIEnv *env, jclass type, jstring talker_,
                                                        jstring cardOwner_, jobject classLoader) {
    Message::SubscriptionCard(env, talker_, cardOwner_, classLoader);
}


}