package sem5;

import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class ClientHandler implements Runnable {
    private final Socket clientSocket;
    private final Library library;

    public ClientHandler(Socket clientSocket, Library library) {
        this.clientSocket = clientSocket;
        this.library = library;
    }

    @Override
    public void run() {
        try (InputStream input = clientSocket.getInputStream();
             OutputStream output = clientSocket.getOutputStream();
             Scanner scanner = new Scanner(input);
             PrintWriter writer = new PrintWriter(output, true)) {

            writer.println("Welcome to the Library System!");

            while (true) {
                writer.println("1. Register\n2. Login\n3. Exit\nChoose an option: ");
                String choice = scanner.nextLine();

                switch (choice) {
                    case "1":
                        writer.println("Enter user type (Librarian/Reader/Author): ");
                        String type = scanner.nextLine();
                        writer.println("Enter username: ");
                        String username = scanner.nextLine();
                        writer.println("Enter password: ");
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
                        writer.println("Enter username: ");
                        String uname = scanner.nextLine();
                        writer.println("Enter password: ");
                        String pass = scanner.nextLine();

                        User user;
                        synchronized (library) {
                            user = library.login(uname, pass);
                        }
                        if (user != null) {
                            handleUserSession(writer, scanner, user);
                        } else {
                            writer.println("Invalid login credentials.");
                        }
                        break;

                    case "3":
                        writer.println("Goodbye!");
                        return;

                    default:
                        writer.println("Invalid choice.");
                }
            }
        } catch (IOException e) {
            System.out.println("Client disconnected: " + e.getMessage());
        }
    }

    private void handleUserSession(PrintWriter writer, Scanner scanner, User user) {
        if (user instanceof Librarian librarian) {
            librarian.showMenu(library, writer, scanner);
        } else if (user instanceof Reader reader) {
            reader.showMenu(library, writer, scanner);
        } else if (user instanceof Author author) {
            author.showMenu(library, writer, scanner);
        }
    }
}
