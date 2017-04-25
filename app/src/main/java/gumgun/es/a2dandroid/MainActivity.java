package gumgun.es.a2dandroid;

import android.app.Activity;
import android.content.pm.ActivityInfo;
import android.content.res.AssetManager;
import android.os.Bundle;
import android.support.v4.view.MotionEventCompat;
import android.view.MotionEvent;
import android.view.Surface;
import android.view.SurfaceView;
import android.view.SurfaceHolder;


public class MainActivity extends Activity implements SurfaceHolder.Callback
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        setRequestedOrientation(ActivityInfo.SCREEN_ORIENTATION_PORTRAIT);
        setContentView(R.layout.activity_main);
        SurfaceView surfaceView = (SurfaceView)findViewById(R.id.surfaceview);
        surfaceView.getHolder().addCallback(this);
    }

    @Override
    public boolean onTouchEvent(MotionEvent event){

        int action = MotionEventCompat.getActionMasked(event);

        switch(action) {
            case (MotionEvent.ACTION_DOWN) :
                OnPress();
                return true;
            default :
                return super.onTouchEvent(event);
        }
    }

    @Override
    protected void onStart()
    {
        super.onStart();
        OnStart();
        SetAssetManager(getAssets());
    }

    @Override
    protected void onResume()
    {
        super.onResume();
        OnResume();
    }

    @Override
    protected void onPause()
    {
        super.onPause();
        OnPause();
    }

    @Override
    protected void onStop()
    {
        super.onStop();
        OnStop();
    }

    public void surfaceChanged(SurfaceHolder holder, int format, int w, int h)
    {
        SetSurface(holder.getSurface());
    }

    public void surfaceCreated(SurfaceHolder holder)
    {

    }

    public void surfaceDestroyed(SurfaceHolder holder)
    {
        SetSurface(null);
    }

    public static native void OnStart();
    public static native void OnResume();
    public static native void OnPause();
    public static native void OnStop();
    public static native void OnPress();
    public static native void SetSurface(Surface surface);
    public static native void SetAssetManager(AssetManager manager);

    static
    {
        System.loadLibrary("native-lib");
    }

}