package techno.t.myapplication;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.view.MotionEvent;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

class TestSurfaceView extends SurfaceView implements SurfaceHolder.Callback{
    SurfaceHolder holder;
    boolean flag = false;
    int x, y;

    Paint paint = new Paint();
    public TestSurfaceView(Context context) {
        super(context);
        getHolder().addCallback(this);
        paint.setColor(Color.GREEN);
        Canvas canvas = new Canvas();
        canvas.drawColor(Color.BLUE);
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        this.holder = holder;
    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {
    }

    @Override
    public boolean onTouchEvent(MotionEvent event) {
        if (flag){
            Canvas canvas = holder.lockCanvas();

            canvas.drawRect(x, y, event.getX(), event.getY(), paint);

            holder.unlockCanvasAndPost(canvas);
            flag = false;
        } else {
            x = (int) event.getX();
            y = (int) event.getY();
            flag =true;
        }
        return super.onTouchEvent(event);
    }
}