package sem5;

import java.io.*;
import java.net.*;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;

public class LibraryServer {
    private static final int PORT = 12345;

    public static void main(String[] args) {
        Library library = new Library();
        ExecutorService executor = Executors.newFixedThreadPool(10); // Limit to 10 concurrent clients.

        try (ServerSocket serverSocket = new ServerSocket(PORT)) {
            System.out.println("Library server is running on port " + PORT);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("New client connected: " + clientSocket.getInetAddress());
                executor.execute(new ClientHandler(clientSocket, library));
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            executor.shutdown();
        }
    }
}
