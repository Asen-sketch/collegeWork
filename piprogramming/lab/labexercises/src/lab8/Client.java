package lab8;

import java.io.IOException;
import java.io.PrintStream;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    private String myName;

    public static void main(String args[]) {
        new Client().start();
    }

    private void start() {
        Scanner console = new Scanner(System.in);
        System.out.println("name: ");
        myName = console.nextLine();

        try {
            Socket socket = new Socket("localhost", 21021);
            Scanner in = new Scanner(socket.getInputStream());
            PrintStream out = new PrintStream(socket.getOutputStream());

            Thread writer = new Thread(() -> {
                while (true) {
                    String line = console.nextLine();
                    out.println(myName + ": " + line);
                    if (line.contains("quit")) {
                        try {
                            socket.close();
                        } catch (IOException e) {
                            throw new RuntimeException(e);
                        }
                        break;
                    }
                }
            });

            writer.start();

            while (true) {
                String line = in.nextLine();
                System.out.println(line);
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}
