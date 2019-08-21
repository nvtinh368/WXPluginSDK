package com.jyong.wxpluginsdk;

import android.app.Activity;
import android.content.Context;
import android.database.Cursor;
import android.os.Environment;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

import java.io.File;
import java.lang.reflect.Constructor;
import java.nio.charset.Charset;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;

import de.robv.android.xposed.IXposedHookLoadPackage;
import de.robv.android.xposed.XC_MethodHook;
import de.robv.android.xposed.XposedHelpers;
import de.robv.android.xposed.callbacks.XC_LoadPackage;

import static de.robv.android.xposed.XposedHelpers.callMethod;
import static de.robv.android.xposed.XposedHelpers.callStaticMethod;

public class Init implements IXposedHookLoadPackage {

    public final static String TAG = "WXPluginSDK";

    @Override
    public void handleLoadPackage(final XC_LoadPackage.LoadPackageParam loadPackageParam) throws Throwable {


        if (loadPackageParam.packageName.contains("com.tencent.mm")) {
            Log.w(TAG, "handleLoadPackage: init plugin ");

            Context mContext = (Context) callMethod(callStaticMethod(XposedHelpers.findClass("android.app.ActivityThread", null), "currentActivityThread", new Object[0]), "getSystemContext", new Object[0]);
            NativeTools.load(mContext, "com.jyong.wxpluginsdk");

            XposedHelpers.findAndHookMethod("com.tencent.mm.ui.LauncherUI",
                    loadPackageParam.classLoader,
                    "onCreateOptionsMenu",
                    Menu.class,
                    new XC_MethodHook() {
                        @Override
                        protected void afterHookedMethod(MethodHookParam param) throws Throwable {
                            final Activity activity = (Activity) param.thisObject;

                            if (activity != null) {
                                Menu menu = (Menu) param.args[0];
                                menu.add(0, 5623, 0, "SendText");
                                menu.add(0, 5624, 0, "SendImage");
                                menu.add(0, 5625, 0, "SendVoice");
                                menu.add(0, 5627, 0, "SendVideo");
                                menu.add(0, 5628, 0, "SendCard");
                                menu.add(0, 5631, 0, "SendSubscriptionCard");

                                for (int i = 0; i < menu.size(); i++) {
                                    MenuItem item = menu.getItem(i);
                                    if (item.getTitle().toString().equals("SendText")) {
                                        item.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
                                            @Override
                                            public boolean onMenuItemClick(MenuItem item) {
                                                Log.w(TAG, "onMenuItemClick: SendText ");
                                                NativeTools.text("talker_wxid", "你好啊", loadPackageParam.classLoader);
                                                return false;
                                            }
                                        });
                                    } else if (item.getTitle().toString().equals("SendImage")) {
                                        item.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
                                            @Override
                                            public boolean onMenuItemClick(MenuItem item) {
                                                Log.w(TAG, "onMenuItemClick: SendImage ");
                                                String path = Environment.getExternalStorageDirectory().getPath() + File.separator + "ma.jpg";
                                                NativeTools.image("my_wxid", "talker_wxid", path, loadPackageParam.classLoader);
                                                return false;
                                            }
                                        });
                                    } else if (item.getTitle().toString().equals("SendVoice")) {
                                        item.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
                                            @Override
                                            public boolean onMenuItemClick(MenuItem item) {
                                                Log.w(TAG, "onMenuItemClick: SendVoice ");
                                                String path = Environment.getExternalStorageDirectory().getPath() + File.separator + "aa.amr";
                                                NativeTools.voice("talker_wxid", path, loadPackageParam.classLoader);
                                                return false;
                                            }
                                        });
                                    } else if (item.getTitle().toString().equals("SendVideo")) {
                                        item.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
                                            @Override
                                            public boolean onMenuItemClick(MenuItem item) {
                                                List<String> list = new ArrayList<>();
                                                String path = Environment.getExternalStorageDirectory().getPath() + File.separator + "haha.mp4";
                                                list.add(path);
                                                NativeTools.video("talker_wxid", list, activity, loadPackageParam.classLoader);
                                                return false;
                                            }
                                        });
                                    } else if (item.getTitle().toString().equals("SendCard")) {
                                        item.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
                                            @Override
                                            public boolean onMenuItemClick(MenuItem item) {
                                                NativeTools.card("talker_wxid", "my_wxid", loadPackageParam.classLoader);
                                                return false;
                                            }
                                        });
                                    } else if (item.getTitle().toString().equals("SendSubscriptionCard")) {
                                        item.setOnMenuItemClickListener(new MenuItem.OnMenuItemClickListener() {
                                            @Override
                                            public boolean onMenuItemClick(MenuItem item) {
                                                NativeTools.subscriptionCard("talker_wxid", "wxid_subscription", loadPackageParam.classLoader);
                                                return false;
                                            }
                                        });
                                    }
                                }
                            }
                        }

                    });
        }

    }
}
