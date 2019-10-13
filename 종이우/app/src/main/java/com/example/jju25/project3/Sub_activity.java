package com.example.jju25.project3;

import android.Manifest;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.hardware.Camera;
import android.media.MediaPlayer;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class Sub_activity extends AppCompatActivity {
    boolean flag = false;
    private Camera mCamera = null;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sub_activity);

    }
    @Override
    protected  void onDestroy()
    {
        super.onDestroy();
        mCamera.release();
    }

    public void onButton1Clicked(View v)
    {
        int permissionCheck = ContextCompat.checkSelfPermission(Sub_activity.this,Manifest.permission.CAMERA);
        if(permissionCheck== PackageManager.PERMISSION_DENIED){
            ActivityCompat.requestPermissions(Sub_activity.this,new String[]{Manifest.permission.CAMERA},0);

        }else {
            mCamera = Camera.open();
            Camera.Parameters param = mCamera.getParameters();
            param.setFlashMode(Camera.Parameters.FLASH_MODE_TORCH);
            mCamera.setParameters(param);
            mCamera.startPreview();
            if (!flag) {
                new AlertDialog.Builder(this)
                        .setTitle("알림팝업")
                        .setMessage("팝업창의 내용입니다.\n\n TEST!!")
                        .setNeutralButton("닫기", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialog, int which) {
                                        Camera.Parameters param = mCamera.getParameters();
                                        param.setFlashMode(Camera.Parameters.FLASH_MODE_OFF);
                                        mCamera.setParameters(param);
                                        mCamera.startPreview();
                                        flag = true;
                                    }
                                }

                        ).show();
            } else {
                Context c = v.getContext();
                final MediaPlayer m = MediaPlayer.create(c, R.raw.ohio);
                m.start();
                new AlertDialog.Builder(this)
                        .setTitle("경고팝업")
                        .setMessage("삐용삐용><\n\n TEST!!")
                        .setNeutralButton("닫기", new DialogInterface.OnClickListener() {
                                    @Override
                                    public void onClick(DialogInterface dialog, int which) {
                                        flag = false;
                                        Camera.Parameters param = mCamera.getParameters();
                                        param.setFlashMode(Camera.Parameters.FLASH_MODE_OFF);
                                        mCamera.setParameters(param);
                                        mCamera.startPreview();
                                        m.stop();
                                        m.release();
                                    }
                                }

                        ).show();

                m.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                    @Override
                    public void onCompletion(MediaPlayer mp) {
                        mp.stop();
                        mp.start();
                    }
                });
            }
        }
    }
    public void onButton1Clicked2(View v)
    {
        Intent intent = new Intent(getApplicationContext(),MapsActivity.class);
        startActivity(intent);
    }
    public void onButton1Clicked3(View v)
    {
        if(!flag)
        {
            new AlertDialog.Builder(this)
                    .setTitle("알림팝업")
                    .setMessage("팝업창의 내용입니다.\n\n TEST!!")
                    .setNeutralButton("닫기", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog, int which) {
                                    flag = true;
                                }
                            }

                    ).show();
        }
        else{
            Context c = v.getContext();
            final MediaPlayer m = MediaPlayer.create(c, R.raw.bell);
            m.start();
            new AlertDialog.Builder(this)
                    .setTitle("경고팝업")
                    .setMessage("삐용삐용><\n\n TEST!!")
                    .setNeutralButton("닫기", new DialogInterface.OnClickListener() {
                                @Override
                                public void onClick(DialogInterface dialog, int which) {
                                    flag = false;
                                    m.stop();
                                    m.release();
                                }
                            }

                    ).show();

            m.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
                @Override
                public void onCompletion(MediaPlayer mp) {
                    mp.stop();
                    mp.start();
                }
            });
        }

    }
    @Override
    public void onRequestPermissionsResult(int requestCode,
                                           @NonNull String[] permissions,@NonNull int[] grantResults) {
        if(requestCode==0){
            if(grantResults[0]==0){
                Toast.makeText(this,"카메라 권환이 승인됨",Toast.LENGTH_SHORT).show();
            }
        }else{
            Toast.makeText(this,"카메라 권환이 거절 되었습니다. 카메라를 이용하려면 권환을 승인해주십시오.",Toast.LENGTH_SHORT).show();

        }
    }

}
