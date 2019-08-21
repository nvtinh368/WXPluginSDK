

cmake_minimum_required(VERSION 3.4.1)


add_library(
             wxpluginsdk

             SHARED

             src/main/cpp/cursor.cpp
             src/main/cpp/md5.cpp
             src/main/cpp/sharedpreftools.cpp
             src/main/cpp/systools.cpp
             src/main/cpp/wxtools.cpp
             src/main/cpp/config.cpp
             src/main/cpp/filetools.cpp
             src/main/cpp/helper.cpp
             src/main/cpp/message.cpp
             src/main/cpp/native.cpp )


find_library(
              log-lib

              log )

target_link_libraries(
                       wxpluginsdk

                       ${log-lib} )