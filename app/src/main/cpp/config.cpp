//
// Created by Administrator on 2019/4/11.
//

#include "include/config.h"

Config::Config(const char *version) {

    if (strcmp(version, "6.6.7") == 0) {
        this->text_message_entity_clz_ = "com.tencent.mm.modelmulti.i";
        this->text_message_entity_constructor_description_ = "(Ljava/lang/String;Ljava/lang/String;I)V";

        this->message_boot_clz_ = "com.tencent.mm.model.au";
        this->message_boot_func_ = "DF";
        this->message_invoke_func_ = "a";
        this->message_invoke_func_description_ = "(Lcom/tencent/mm/ab/l;I)Z";

        this->image_message_entity_clz_ = "com.tencent.mm.ak.l";
        this->image_message_entity_constructor_description_ = "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;ILcom/tencent/mm/ab/f;ILjava/lang/String;Ljava/lang/String;ZI)V";

        this->voice_message_db_entity_clz_ = "com.tencent.mm.modelvoice.q";
        this->voice_message_db_entity_func_ = "om";
        this->voice_message_path_clz_ = "com.tencent.mm.modelvoice.q";
        this->voice_message_path_func_ = "O";
        this->voice_message_path_func_description_ = "(Ljava/lang/String;Z)Ljava/lang/String;";
        this->voice_message_notify_func_ = "m";
        this->voice_message_notify_func_description_ = "(Ljava/lang/String;II)Z";
        this->voice_message_entity_clz_ = "com.tencent.mm.modelvoice.f";
        this->voice_message_entity_constructor_description_ = "(Ljava/lang/String;)V";

        this->video_message_entity_clz_ = "com.tencent.mm.pluginsdk.model.j";
        this->video_message_entity_constructor_description_ = "(Landroid/content/Context;Ljava/util/List;Landroid/content/Intent;Ljava/lang/String;ILcom/tencent/mm/pluginsdk/model/j$a;)V";
        this->video_message_boot_clz_ = "com.tencent.mm.sdk.f.e";
        this->video_message_boot_func_ = "a";

        this->card_message_package_clz_ = "com.tencent.mm.ui.contact.y";
        this->card_message_package_func_ = "aaP";
    }

    if (strcmp(version, "7.0.3") == 0) {
        this->text_message_entity_clz_ = "com.tencent.mm.modelmulti.h";
        this->text_message_entity_constructor_description_ = "(Ljava/lang/String;Ljava/lang/String;I)V";

        this->message_boot_clz_ = "com.tencent.mm.model.av";
        this->message_boot_func_ = "Pw";
        this->message_invoke_func_ = "a";
        this->message_invoke_func_description_ = "(Lcom/tencent/mm/ah/m;I)Z";

        this->image_message_entity_clz_ = "com.tencent.mm.as.l";
        this->image_message_entity_constructor_description_ = "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;ILcom/tencent/mm/ah/g;ILjava/lang/String;Ljava/lang/String;ZI)V";

        this->voice_message_db_entity_clz_ = "com.tencent.mm.modelvoice.q";
        this->voice_message_db_entity_func_ = "uo";
        this->voice_message_path_clz_ = "com.tencent.mm.modelvoice.q";
        this->voice_message_path_func_ = "T";
        this->voice_message_path_func_description_ = "(Ljava/lang/String;Z)Ljava/lang/String;";
        this->voice_message_notify_func_ = "o";
        this->voice_message_notify_func_description_ = "(Ljava/lang/String;II)Z";
        this->voice_message_entity_clz_ = "com.tencent.mm.modelvoice.f";
        this->voice_message_entity_constructor_description_ = "(Ljava/lang/String;)V";

        this->video_message_entity_clz_ = "com.tencent.mm.pluginsdk.model.j";
        this->video_message_entity_constructor_description_ = "(Landroid/content/Context;Ljava/util/List;Landroid/content/Intent;Ljava/lang/String;ILcom/tencent/mm/pluginsdk/model/j$a;)V";
        this->video_message_boot_clz_ = "com.tencent.mm.sdk.g.d";
        this->video_message_boot_func_ = "post";

        this->card_message_package_clz_ = "com.tencent.mm.ui.contact.z";
        this->card_message_package_func_ = "aqn";

        this->subscription_card_boot_clz_ = "com.tencent.mm.plugin.messenger.a.g";
        this->subscription_card_boot_func_ = "bKf";
        this->subscription_card_send_func_ = "q";
        this->subscription_card_send_func_description_ = "(Ljava/lang/String;Ljava/lang/String;Z)V";
    }

    if (strcmp(version, "7.0.4") == 0) {

        this->text_message_entity_clz_ = "com.tencent.mm.modelmulti.h";
        this->text_message_entity_constructor_description_ = "(Ljava/lang/String;Ljava/lang/String;I)V";

        this->message_boot_clz_ = "com.tencent.mm.model.aw";
        this->message_boot_func_ = "Rg";
        this->message_invoke_func_ = "a";
        this->message_invoke_func_description_ = "(Lcom/tencent/mm/ai/m;I)Z";

        this->image_message_entity_clz_ = "com.tencent.mm.at.l";
        this->image_message_entity_constructor_description_ = "(ILjava/lang/String;Ljava/lang/String;Ljava/lang/String;ILcom/tencent/mm/ai/g;ILjava/lang/String;Ljava/lang/String;ZI)V";

        this->voice_message_db_entity_clz_ = "com.tencent.mm.modelvoice.q";
        this->voice_message_db_entity_func_ = "uP";
        this->voice_message_path_clz_ = "com.tencent.mm.modelvoice.q";
        this->voice_message_path_func_ = "U";
        this->voice_message_path_func_description_ = "(Ljava/lang/String;Z)Ljava/lang/String;";
        this->voice_message_notify_func_ = "o";
        this->voice_message_notify_func_description_ = "(Ljava/lang/String;II)Z";
        this->voice_message_entity_clz_ = "com.tencent.mm.modelvoice.f";
        this->voice_message_entity_constructor_description_ = "(Ljava/lang/String;)V";

        this->video_message_entity_clz_ = "com.tencent.mm.pluginsdk.model.j";
        this->video_message_entity_constructor_description_ = "(Landroid/content/Context;Ljava/util/List;Landroid/content/Intent;Ljava/lang/String;ILcom/tencent/mm/pluginsdk/model/j$a;)V";
        this->video_message_boot_clz_ = "com.tencent.mm.sdk.g.d";
        this->video_message_boot_func_ = "post";

        this->card_message_package_clz_ = "com.tencent.mm.ui.contact.z";
        this->card_message_package_func_ = "arT";

        this->subscription_card_boot_clz_ = "com.tencent.mm.plugin.messenger.a.g";
        this->subscription_card_boot_func_ = "bOk";
        this->subscription_card_send_func_ = "q";
        this->subscription_card_send_func_description_ = "(Ljava/lang/String;Ljava/lang/String;Z)V";

        this->database_clz_ = "com.tencent.wcdb.database.SQLiteDatabase";
        this->database_impl_clz_ = "com.tencent.mm.cd.f";
        this->database_impl_clz_constructor_description_ = "()V";
        this->database_impl_clz_cipher_field_ = "kIB";
        this->database_impl_clz_cipher_field_description_ = "Lcom/tencent/wcdb/database/SQLiteCipherSpec;";
        this->database_clz_open_db_func_ = "openDatabase";
        this->database_clz_open_db_func_description_ = "(Ljava/lang/String;[BLcom/tencent/wcdb/database/SQLiteCipherSpec;Lcom/tencent/wcdb/database/SQLiteDatabase$CursorFactory;ILcom/tencent/wcdb/DatabaseErrorHandler;)Lcom/tencent/wcdb/database/SQLiteDatabase;";
        this->database_clz_rawquery_func_ = "rawQuery";
        this->database_clz_rawquery_func_description_ = "(Ljava/lang/String;[Ljava/lang/Object;)Lcom/tencent/wcdb/Cursor;";
    }

}

Config::~Config() {

}

Config::Config() {

}
