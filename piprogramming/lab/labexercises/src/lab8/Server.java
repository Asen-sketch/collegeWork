package lab8;

import java.io.IOException;
import java.io.PrintStream;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Server {
    private List<PrintStream> clients;

    private Server() {
        clients = new ArrayList<>();
    }

    public static void main (String args[]) {
        new Server().start();
    }

    private void start() {
        try {
            ServerSocket socket = new ServerSocket(21021);

            while (true) {
                Socket client = socket.accept();

                new Thread(() -> {
                    try {
                        Scanner in = new Scanner(client.getInputStream());
                        PrintStream out = new PrintStream(client.getOutputStream());

                        synchronized (clients) {
                            clients.add(out);
                        }

                        while(true) {
                            String line = in.nextLine();
                            if (line.contains("quit")) {
                                in.close();
                                out.close();
                                synchronized (clients) {
                                    clients.remove(out);
                                }
                                client.close();
                                break;
                            }

                            synchronized (clients) {
                                for (PrintStream e : clients) {
                                    e.println(line);
                                }
                            }
                        }
                    } catch (IOException e) {
                        synchronized (clients) {
                            clients.removeIf(out -> out.checkError());
                        }
                    }
                }).start();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }
}

// zabelejka - ne e dobra praktika da ze polzva samiq resurs. Molq napravi otdelen resurs/obect/mutex ZA DA GO PRAVISH PO DOBRE