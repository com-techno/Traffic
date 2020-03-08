import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Date;

public class Main {

    private static final int a = 10;

    public static void main(String[] args) {
        SlideShow sh = new SlideShow();
        sh.start();
    }

    static class SlideShow extends Thread{
        void nextPhoto(){System.out.println("lol");}
        public void run(){
            while (true) {
                nextPhoto();
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }





}
