package sem5;

import java.io.PrintWriter;
import java.util.Scanner;

public class Librarian extends User {
    public Librarian(String username, String password) {
        super(username, password);
    }

    @Override
    public void showMenu(Library library, PrintWriter writer, Scanner scanner) {
        while (true) {
            writer.println("\nLibrarian Menu:");
            writer.println("1. Add Book\n2. Remove Book\n3. Exit");
            writer.print("Choose an option: ");
            String choice = scanner.nextLine();

            switch (choice) {
                case "1":
                    writer.print("Enter book title: ");
                    String title = scanner.nextLine();
                    writer.print("Enter book author: ");
                    String author = scanner.nextLine();
                    writer.print("Enter book year: ");
                    int year = Integer.parseInt(scanner.nextLine());
                    synchronized (library) {
                        library.addBook(new Book(title, author, year));
                    }
                    writer.println("Book added successfully.");
                    break;

                case "2":
                    writer.print("Enter book title to remove: ");
                    String bookTitle = scanner.nextLine();
                    synchronized (library) {
                        library.removeBook(bookTitle, writer);
                    }
                    break;

                case "3":
                    return;

                default:
                    writer.println("Invalid choice.");
            }
        }
    }
}
