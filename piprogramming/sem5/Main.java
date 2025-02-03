package sem5;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Library library = new Library();
        int port = 12345;

        try (ServerSocket serverSocket = new ServerSocket(port)) {
            System.out.println("Library server is running on port " + port);

            while (true) {
                Socket clientSocket = serverSocket.accept();
                System.out.println("Client connected.");

                new Thread(() -> handleClient(clientSocket, library)).start();
            }
        } catch (IOException e) {
            System.out.println("Server error: " + e.getMessage());
        }
    }

    private static void handleClient(Socket clientSocket, Library library) { // 68 uchilishte
        try (
                InputStream input = clientSocket.getInputStream();
                OutputStream output = clientSocket.getOutputStream();
                Scanner scanner = new Scanner(input);
                PrintWriter writer = new PrintWriter(output, true)
        ) {
            while (true) {
                writer.println("\nLibrary System");
                writer.println("1. Register");
                writer.println("2. Login");
                writer.println("3. Exit");
                writer.print("Choose an option: ");

                String choice = scanner.nextLine();

                switch (choice) {
                    case "1":
                        writer.print("Enter user type (Librarian/Reader/Author): ");
                        String type = scanner.nextLine();
                        writer.print("Enter username: ");
                        String username = scanner.nextLine();
                        writer.print("Enter password: ");
                        String password = scanner.nextLine();

                        try {
                            User user = switch (type.toLowerCase()) {
                                case "librarian" -> new Librarian(username, password);
                                case "reader" -> new Reader(username, password);
                                case "author" -> new Author(username, password);
                                default -> throw new IllegalArgumentException("Invalid user type.");
                            };
                            synchronized (library) {
                                library.registerUser(user);
                            }
                            writer.println("User registered successfully.");
                        } catch (Exception e) {
                            writer.println("Error: " + e.getMessage());
                        }
                        break;

                    case "2":
                        writer.print("Enter username: ");
                        String uname = scanner.nextLine();
                        writer.print("Enter password: ");
                        String pass = scanner.nextLine();

                        User user;
                        synchronized (library) {
                            user = library.login(uname, pass);
                        }

                        if (user != null) {
                            user.showMenu(library, writer, scanner);
                        } else {
                            writer.println("Invalid login credentials.");
                        }
                        break;

                    case "3":
                        writer.println("Exiting...");
                        return;

                    default:
                        writer.println("Invalid choice.");
                }
            }
        } catch (IOException e) {
            System.out.println("Client error: " + e.getMessage());
        }
    }
}
