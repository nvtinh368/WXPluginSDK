//
// Created by Administrator on 2019/4/5.
//

#include "include/message.h"
#include "include/helper.h"
#include "include/filetools.h"
#include "include/config.h"
#include "include/systools.h"

using namespace std;

const char WECHAT_PACKAGE_NAME[] = "com.tencent.mm";

void Message::Text(JNIEnv *env, jstring &talker_, jstring &content_, jobject &classLoader) {
    string version = SysTools::GetVersion(env, WECHAT_PACKAGE_NAME);
    Config config(version.c_str());

    jclass entity_clz = Helper::FindClass(env, config.text_message_entity_clz_.c_str(),
                                          classLoader);


    jmethodID constructor_func = Helper::GetConstructor(env, entity_clz,
                                                        config.text_message_entity_constructor_description_.c_str());

    jobject entity_obj = env->NewObject(entity_clz, constructor_func,
                                        talker_, content_, 1);

    jclass boot_clz = Helper::FindClass(env, config.message_boot_clz_.c_str(), classLoader);

    jobjectArray arr = Helper::GetNullParams(env);
    jobject invoke_obj = Helper::CallStaticMethod(env, boot_clz,
                                                  config.message_boot_func_.c_str(), arr);

    jclass invoke_clz = Helper::GetObjectClass(env, invoke_obj);

    jmethodID invoke_func = Helper::GetMethod(env, invoke_clz,
                                              config.message_invoke_func_.c_str(),
                                              config.message_invoke_func_description_.c_str());

    env->CallObjectMethod(invoke_obj, invoke_func, entity_obj, 0);

    env->DeleteLocalRef(entity_clz);
    env->DeleteLocalRef(entity_obj);
    env->DeleteLocalRef(boot_clz);
    env->DeleteLocalRef(arr);
    env->DeleteLocalRef(invoke_obj);
    env->DeleteLocalRef(invoke_clz);
}

void Message::Image(JNIEnv *env, jstring &myWx_, jstring &talker_, jstring &imgPath_,
                    jobject &classLoader) {
    string version = SysTools::GetVersion(env, WECHAT_PACKAGE_NAME);
    Config config(version.c_str());

    jclass entity_clz = Helper::FindClass(env, config.image_message_entity_clz_.c_str(),
                                          classLoader);

    jmethodID constructor_func = Helper::GetConstructor(env,
                                                        entity_clz,
                                                        config.image_message_entity_constructor_description_.c_str());

    jstring nullStr = env->NewStringUTF("");
    jobject entity_obj = env->NewObject(entity_clz, constructor_func,
                                        2, myWx_, talker_, imgPath_,
                                        0, NULL, 0, nullStr,
                                        nullStr, true, 2130837923);

    jclass boot_clz = Helper::FindClass(env, config.message_boot_clz_.c_str(), classLoader);

    jobjectArray arr = Helper::GetNullParams(env);
    jobject invoke_obj = Helper::CallStaticMethod(env, boot_clz, config.message_boot_func_.c_str(),
                                                  arr);

    jclass invoke_clz = Helper::GetObjectClass(env, invoke_obj);

    jmethodID invoke_func = Helper::GetMethod(env, invoke_clz, config.message_invoke_func_.c_str(),
                                              config.message_invoke_func_description_.c_str());

    env->CallObjectMethod(invoke_obj, invoke_func, entity_obj, 0);

    env->DeleteLocalRef(nullStr);
    env->DeleteLocalRef(entity_clz);
    env->DeleteLocalRef(entity_obj);
    env->DeleteLocalRef(boot_clz);
    env->DeleteLocalRef(arr);
    env->DeleteLocalRef(invoke_obj);
    env->DeleteLocalRef(invoke_clz);
}

void Message::Voice(JNIEnv *env, jstring &talker_, jstring &localFilePath_, jobject &classLoader) {
    string version = SysTools::GetVersion(env, WECHAT_PACKAGE_NAME);
    Config config(version.c_str());

    jclass db_clz = Helper::FindClass(env, config.voice_message_db_entity_clz_.c_str(),
                                      classLoader);

    jclass object_clz = env->FindClass("java/lang/Object");

    jobjectArray obj_array = env->NewObjectArray(1, object_clz, NULL);
    env->SetObjectArrayElement(obj_array, 0, talker_);
    jstring fileName = (jstring) Helper::CallStaticMethod(env, db_clz,
                                                          config.voice_message_db_entity_func_.c_str(),
                                                          obj_array);

    jclass path_clz = Helper::FindClass(env, config.voice_message_path_clz_.c_str(), classLoader);

    jmethodID static_func = Helper::GetStaticMethod(env, path_clz,
                                                    config.voice_message_path_func_.c_str(),
                                                    config.voice_message_path_func_description_.c_str());

    jstring targetFilePath = (jstring) env->CallStaticObjectMethod(path_clz,
                                                                   static_func,
                                                                   fileName, true);

    const char *srcPath = env->GetStringUTFChars(localFilePath_, 0);
    const char *destPath = env->GetStringUTFChars(targetFilePath, 0);

    FileTools::Copy(srcPath, destPath);

    jmethodID m_func = Helper::GetStaticMethod(env, path_clz,
                                               config.voice_message_notify_func_.c_str(),
                                               config.voice_message_notify_func_description_.c_str());

    env->CallStaticObjectMethod(path_clz, m_func, fileName,
                                FileTools::GetFileLength(destPath), 0);

    jclass entity_clz = Helper::FindClass(env, config.voice_message_entity_clz_.c_str(),
                                          classLoader);
    jmethodID constructor_func = Helper::GetConstructor(env, entity_clz,
                                                        config.voice_message_entity_constructor_description_.c_str());

    jobject entity_obj = env->NewObject(entity_clz, constructor_func, fileName);

    jclass boot_clz = Helper::FindClass(env, config.message_boot_clz_.c_str(), classLoader);

    jobjectArray obj_array2 = Helper::GetNullParams(env);

    jobject invoke_obj = Helper::CallStaticMethod(env, boot_clz, config.message_boot_func_.c_str(),
                                                  obj_array2);

    jclass invoke_clz = Helper::GetObjectClass(env, invoke_obj);

    jmethodID invoke_func = Helper::GetMethod(env, invoke_clz, config.message_invoke_func_.c_str(),
                                              config.message_invoke_func_description_.c_str());

    env->CallObjectMethod(invoke_obj, invoke_func, entity_obj, 0);

    env->ReleaseStringUTFChars(localFilePath_, srcPath);
    env->ReleaseStringUTFChars(targetFilePath, destPath);

    env->DeleteLocalRef(db_clz);
    env->DeleteLocalRef(object_clz);
    env->DeleteLocalRef(obj_array);
    env->DeleteLocalRef(fileName);
    env->DeleteLocalRef(path_clz);
    env->DeleteLocalRef(targetFilePath);
    env->DeleteLocalRef(entity_clz);
    env->DeleteLocalRef(entity_obj);
    env->DeleteLocalRef(boot_clz);
    env->DeleteLocalRef(obj_array2);
    env->DeleteLocalRef(invoke_obj);
    env->DeleteLocalRef(invoke_clz);
}

void Message::Video(JNIEnv *env, jstring &talker_, jobject &videoPath, jobject &context,
                    jobject &classLoader) {
    string version = SysTools::GetVersion(env, WECHAT_PACKAGE_NAME);
    Config config(version.c_str());

    jclass entity_clz = Helper::FindClass(env, config.video_message_entity_clz_.c_str(),
                                          classLoader);
    jmethodID constructor_func = Helper::GetConstructor(env, entity_clz,
                                                        config.video_message_entity_constructor_description_.c_str());
    jobject entity_obj = env->NewObject(entity_clz, constructor_func, context, videoPath,
                                        NULL, talker_, 2, NULL);

    jclass boot_clz = Helper::FindClass(env, config.video_message_boot_clz_.c_str(), classLoader);

    jclass object_clz = env->FindClass("java/lang/Object");
    jobjectArray obj_array = env->NewObjectArray(2, object_clz, NULL);
    env->SetObjectArrayElement(obj_array, 0, entity_obj);
    env->SetObjectArrayElement(obj_array, 1, env->NewStringUTF("ChattingUI_importMultiVideo"));

    Helper::CallStaticMethod(env, boot_clz, config.video_message_boot_func_.c_str(), obj_array);

    env->DeleteLocalRef(entity_clz);
    env->DeleteLocalRef(entity_obj);
    env->DeleteLocalRef(boot_clz);
    env->DeleteLocalRef(object_clz);
    env->DeleteLocalRef(obj_array);
}

void Message::Card(JNIEnv *env, jstring &talker_, jstring &cardOwner_, jobject &classLoader) {
    string version = SysTools::GetVersion(env, WECHAT_PACKAGE_NAME);
    Config config(version.c_str());

    jclass package_clz = Helper::FindClass(env, config.card_message_package_clz_.c_str(),
                                           classLoader);

    jclass object_clz = env->FindClass("java/lang/Object");
    jobjectArray obj_array = env->NewObjectArray(1, object_clz, NULL);
    env->SetObjectArrayElement(obj_array, 0, cardOwner_);
    jstring packageStr = (jstring) Helper::CallStaticMethod(env, package_clz,
                                                            config.card_message_package_func_.c_str(),
                                                            obj_array);

    jclass entity_clz = Helper::FindClass(env, config.text_message_entity_clz_.c_str(),
                                          classLoader);

    jmethodID constructor_func = Helper::GetConstructor(env, entity_clz,
                                                        config.text_message_entity_constructor_description_.c_str());
    jobject entity_obj = env->NewObject(entity_clz, constructor_func, talker_,
                                        packageStr, 42);

    jclass boot_clz = Helper::FindClass(env, config.message_boot_clz_.c_str(), classLoader);

    jobjectArray arr = Helper::GetNullParams(env);
    jobject invoke_obj = Helper::CallStaticMethod(env, boot_clz, config.message_boot_func_.c_str(),
                                                  arr);

    jclass invoke_clz = Helper::GetObjectClass(env, invoke_obj);

    jmethodID invoke_func = Helper::GetMethod(env, invoke_clz, config.message_invoke_func_.c_str(),
                                              config.message_invoke_func_description_.c_str());

    env->CallObjectMethod(invoke_obj, invoke_func, entity_obj, 0);

    env->DeleteLocalRef(package_clz);
    env->DeleteLocalRef(object_clz);
    env->DeleteLocalRef(obj_array);
    env->DeleteLocalRef(packageStr);
    env->DeleteLocalRef(entity_clz);
    env->DeleteLocalRef(entity_obj);
    env->DeleteLocalRef(boot_clz);
    env->DeleteLocalRef(arr);
    env->DeleteLocalRef(invoke_obj);
    env->DeleteLocalRef(invoke_clz);
}

void Message::SubscriptionCard(JNIEnv *env, jstring &talker_, jstring &cardOwner_,
                               jobject &classLoader) {
    string version = SysTools::GetVersion(env, WECHAT_PACKAGE_NAME);
    Config config(version.c_str());

    jclass boot_clz = Helper::FindClass(env, config.subscription_card_boot_clz_.c_str(),
                                        classLoader);

    jobjectArray null_array = Helper::GetNullParams(env);
    jobject invoke_obj = Helper::CallStaticMethod(env, boot_clz,
                                                  config.subscription_card_boot_func_.c_str(),
                                                  null_array);

    jclass invoke_clz = Helper::GetObjectClass(env, invoke_obj);

    jmethodID subscriptionSend_func = Helper::GetMethod(env, invoke_clz,
                                                        config.subscription_card_send_func_.c_str(),
                                                        config.subscription_card_send_func_description_.c_str());

    env->CallObjectMethod(invoke_obj, subscriptionSend_func, cardOwner_, talker_, (jboolean) true);

    env->DeleteLocalRef(boot_clz);
    env->DeleteLocalRef(null_array);
    env->DeleteLocalRef(invoke_obj);
    env->DeleteLocalRef(invoke_clz);
}
