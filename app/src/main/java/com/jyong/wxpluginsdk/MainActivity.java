package com.jyong.wxpluginsdk;

import android.app.Activity;
import android.content.Context;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends Activity {



    private final String TAG = "wxpluginsdk";

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                try {
                    Context wxContext = getApplicationContext().createPackageContext("com.tencent.mm", Context.CONTEXT_IGNORE_SECURITY);
                    String aa = "aaaa";
                    byte[] data = aa.getBytes();
                } catch (PackageManager.NameNotFoundException e) {
                    e.printStackTrace();
                }

            }
        });
    }

}
