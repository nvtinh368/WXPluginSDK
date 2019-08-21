package com.jyong.wxpluginsdk;


import android.content.Context;
import android.util.Log;

import java.io.File;
import java.util.List;

public class NativeTools {
    public static native String stringFromJNI();

    public static void load(Context context,String pkgName) {
        if (context == null) {
            return;
        }
        try {
            Context soContext = context.createPackageContext(pkgName, Context.CONTEXT_IGNORE_SECURITY);
            String nativeLibDir = soContext.getApplicationInfo().nativeLibraryDir;
            nativeLibDir = nativeLibDir + File.separator + "libwxpluginsdk.so";
            System.load(nativeLibDir);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public static native void text(String talker, String content, ClassLoader classLoader);

    public static native void image(String myWx, String talker, String imgPath, ClassLoader classLoader);

    public static native void voice(String talker, String localFilePath, ClassLoader classLoader);

    public static native void video(String talker, List<String> videoPath, Context context, ClassLoader classLoader);

    public static native void card(String talker, String cardOwner, ClassLoader classLoader);

    public static native void subscriptionCard(String talker,String cardOwner,ClassLoader classLoader);

}
