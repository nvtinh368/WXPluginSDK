//
// Created by Administrator on 2019/4/23.
//

#include "include/wxtools.h"
#include "include/systools.h"
#include "include/sharedpreftools.h"
#include "include/md5.h"
#include "include/helper.h"
#include "include/config.h"

const char WECHAT_PACKAGE_NAME[] = "com.tencent.mm";

/**
 *  获取微信 uin
 */
string WXTools::GetUinCode(JNIEnv *env) {

    jobject sharedpreferences_object = SysTools::GetSharedPref(env,
                                                               "com.tencent.mm",
                                                               "system_config_prefs");

    jint uin_code = SharedPrefTools::GetIntValue(env,
                                                 sharedpreferences_object,
                                                 "default_uin");

    char buf[64];
    sprintf(buf, "%d", uin_code);
    jstring uin_jstr = env->NewStringUTF(buf);
    const char *uin_str = env->GetStringUTFChars(uin_jstr, 0);
    string uin_code_str = uin_str;

    env->DeleteLocalRef(sharedpreferences_object);
    env->DeleteLocalRef(uin_jstr);

    return uin_code_str;
}


/**
 *  获取微信当前登录账号的目录 /data/data/com.tencent.mm/MicroMsg/currentDir/
 */
string WXTools::GetCurrentDir(JNIEnv *env) {

    string uin_code = WXTools::GetUinCode(env);
    string prefix = "mm";

    string result = prefix + uin_code;

    string hex_result = MD5(result).hexdigest();

    return hex_result;
}


/**
 * 获取微信 EnMicroMsg.db 数据库密码
 */
string WXTools::GetDBPassword(JNIEnv *env) {

    string imei = SysTools::GetIMEI(env);

    string uin = GetUinCode(env);

    string hex_result = MD5(imei + uin).hexdigest();

    string password = hex_result.substr(0, 7);

    return password;
}


/**
 * 打开微信 EnMicroMsg.db 数据库,返回数据库对象
 */
jobject WXTools::OpenDatabase(JNIEnv *env, jobject &classLoader) {

    string version = SysTools::GetVersion(env, WECHAT_PACKAGE_NAME);
    Config config(version.c_str());

    jclass db_clz = Helper::FindClass(env, config.database_clz_.c_str(), classLoader);

    string dir_name = WXTools::GetCurrentDir(env);
    string db_path = "/data/data/com.tencent.mm/MicroMsg/" + dir_name + "/EnMicroMsg.db";

    jint key = 805306368;

    string password_str = WXTools::GetDBPassword(env);
    jstring psw = env->NewStringUTF(password_str.c_str());
    jclass string_clz = env->FindClass("java/lang/String");
    jmethodID getBytes_mid = env->GetMethodID(string_clz, "getBytes", "()[B");
    jobject password_arr = env->CallObjectMethod(psw, getBytes_mid);

    jclass dbInstance_clz = Helper::FindClass(env, config.database_impl_clz_.c_str(), classLoader);

    jmethodID constructor_mid = Helper::GetConstructor(env, dbInstance_clz,
                                                       config.database_impl_clz_constructor_description_.c_str());
    jobject dbInstance_obj = env->NewObject(dbInstance_clz, constructor_mid);

    jobject sqliteCipher_obj = Helper::GetStaticField(env, dbInstance_clz,
                                                      config.database_impl_clz_cipher_field_.c_str(),
                                                      config.database_impl_clz_cipher_field_description_.c_str());

    jmethodID openDatabase_mid = Helper::GetStaticMethod(env,
                                                         db_clz,
                                                         config.database_clz_open_db_func_.c_str(),
                                                         config.database_clz_open_db_func_description_.c_str());

    jstring dbPath_jstr = env->NewStringUTF(db_path.c_str());
    jobject db_obj = env->CallStaticObjectMethod(db_clz,
                                                 openDatabase_mid,
                                                 dbPath_jstr,
                                                 password_arr,
                                                 sqliteCipher_obj,
                                                 nullptr,
                                                 key,
                                                 dbInstance_obj);

    env->DeleteLocalRef(db_clz);
    env->DeleteLocalRef(psw);
    env->DeleteLocalRef(string_clz);
    env->DeleteLocalRef(password_arr);
    env->DeleteLocalRef(dbInstance_clz);
    env->DeleteLocalRef(dbInstance_obj);
    env->DeleteLocalRef(sqliteCipher_obj);
    env->DeleteLocalRef(dbPath_jstr);
    return db_obj;
}


/**
 *  执行查询语句
 */
jobject WXTools::RawQuery(JNIEnv *env, jobject &classLoader, string &sql, jobjectArray &obj_arr) {

    string version = SysTools::GetVersion(env, WECHAT_PACKAGE_NAME);
    Config config(version.c_str());

    jobject db_obj = OpenDatabase(env, classLoader);

    jclass db_clz = Helper::GetObjectClass(env, db_obj);

    jmethodID rawQuery_mid = env->GetMethodID(db_clz,
                                              config.database_clz_rawquery_func_.c_str(),
                                              config.database_clz_rawquery_func_description_.c_str());

    jstring sql_str = env->NewStringUTF(sql.c_str());

    jobject cursor_obj = env->CallObjectMethod(db_obj, rawQuery_mid, sql_str, obj_arr);

    env->DeleteLocalRef(db_obj);
    env->DeleteLocalRef(db_clz);
    env->DeleteLocalRef(sql_str);
    return cursor_obj;
}
