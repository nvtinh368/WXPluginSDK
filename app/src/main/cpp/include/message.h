//
// Created by Administrator on 2019/4/5.
//

#ifndef WXPLUGINSDK_MESSAGE_H
#define WXPLUGINSDK_MESSAGE_H


#include <jni.h>

class Message {
public:
    static void
    Text(JNIEnv *env, jstring &talker_, jstring &content_, jobject &classLoader);

    static void
    Image(JNIEnv *env, jstring &myWx_, jstring &talker_, jstring &imgPath_, jobject &classLoader);

    static void
    Voice(JNIEnv *env, jstring &talker_, jstring &localFilePath_, jobject &classLoader);

    static void
    Video(JNIEnv *env, jstring &talker_, jobject &videoPath, jobject &context,
          jobject &classLoader);

    static void
    Card(JNIEnv *env, jstring &talker_, jstring &cardOwner_, jobject &classLoader);

    static void
    SubscriptionCard(JNIEnv *env, jstring &talker_, jstring &cardOwner_, jobject &classLoader);

};


#endif //WXPLUGINSDK_MESSAGE_H
