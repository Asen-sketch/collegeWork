package sem5;

import java.io.PrintWriter;
import java.util.Scanner;

public class Reader extends User {
    public Reader(String username, String password) {
        super(username, password);
    }

    @Override
    public void showMenu(Library library, PrintWriter writer, Scanner scanner) {
        while (true) {
            writer.println("\nReader Menu:");
            writer.println("1. View Available Books\n2. Borrow Book\n3. Exit");
            writer.print("Choose an option: ");
            String choice = scanner.nextLine();

            switch (choice) {
                case "1":
                    synchronized (library) {
                        library.listBooks(writer);
                    }
                    break;

                case "2":
                    writer.print("Enter book title to borrow: ");
                    String bookTitle = scanner.nextLine();
                    synchronized (library) {
                        library.borrowBook(bookTitle, writer);
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
