package lab7;

import java.util.ArrayList;
import java.util.List;

public class AdderPrinter {
    public static void main (String[] args) {
        List<Integer> sharedList = new ArrayList<>();

        Thread adder = new Thread(() -> {
           int count = 0;
           while (true) {
               synchronized (sharedList) {
                   sharedList.add(count++);
               }
               try {
                   Thread.sleep(500);
               } catch (InterruptedException e) {
                   e.printStackTrace();
               }
           }
        });

        Thread printer = new Thread(() -> {
            while (true) {
                synchronized (sharedList) {
                    System.out.println("the list: " + sharedList);
                }
                try {
                    Thread.sleep(3000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        });

        adder.start();
        printer.start();
    }
}
