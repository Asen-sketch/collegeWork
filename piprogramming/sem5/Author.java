package sem5;

import java.io.PrintWriter;
import java.util.Scanner;

public class Author extends User {
    public Author(String username, String password) {
        super(username, password);
    }

    @Override
    public void showMenu(Library library, PrintWriter writer, Scanner scanner) {
        while (true) {
            writer.println("\nAuthor Menu:");
            writer.println("1. Add Book\n2. Exit");
            writer.print("Choose an option: ");
            String choice = scanner.nextLine();

            switch (choice) {
                case "1":
                    writer.print("Enter book title: ");
                    String title = scanner.nextLine();
                    writer.print("Enter book year: ");
                    int year = Integer.parseInt(scanner.nextLine());
                    synchronized (library) {
                        library.addBook(new Book(title, this.username, year));
                    }
                    writer.println("Book added successfully.");
                    break;

                case "2":
                    return;

                default:
                    writer.println("Invalid choice.");
            }
        }
    }
}
