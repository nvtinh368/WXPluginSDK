//
// Created by Administrator on 2019/4/11.
//

#ifndef WXPLUGINSDK_CONFIG_H
#define WXPLUGINSDK_CONFIG_H

#include <string>

using namespace std;

class Config {
public:
    ~Config();

    Config();

    Config(const char *version);

    //  send text message
    string text_message_entity_clz_;
    string text_message_entity_constructor_description_;

    string message_boot_clz_;
    string message_boot_func_;
    string message_invoke_func_;
    string message_invoke_func_description_;

    //  send image message
    string image_message_entity_clz_;
    string image_message_entity_constructor_description_;

    //  send voice message
    string voice_message_db_entity_clz_;
    string voice_message_db_entity_func_;
    string voice_message_path_clz_;
    string voice_message_path_func_;
    string voice_message_path_func_description_;
    string voice_message_notify_func_;
    string voice_message_notify_func_description_;
    string voice_message_entity_clz_;
    string voice_message_entity_constructor_description_;

    //  send video message
    string video_message_entity_clz_;
    string video_message_entity_constructor_description_;
    string video_message_boot_clz_;
    string video_message_boot_func_;

    //  send card
    string card_message_package_clz_;
    string card_message_package_func_;

    //  send subscription card
    string subscription_card_boot_clz_;
    string subscription_card_boot_func_;
    string subscription_card_send_func_;
    string subscription_card_send_func_description_;

    //  database
    string database_clz_;
    string database_impl_clz_;
    string database_impl_clz_constructor_description_;
    string database_impl_clz_cipher_field_;
    string database_impl_clz_cipher_field_description_;
    string database_clz_open_db_func_;
    string database_clz_open_db_func_description_;
    string database_clz_rawquery_func_;
    string database_clz_rawquery_func_description_;

};


#endif //WXPLUGINSDK_CONFIG_H
