package sem5;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Library {
    private final String booksFile = "books.bin";
    private final String usersFile = "users.bin";
    private final List<Book> books;
    private final List<User> users;

    public Library() {
        this.books = loadBooks();
        this.users = loadUsers();
    }

    @SuppressWarnings("unchecked")
    private synchronized List<Book> loadBooks() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(booksFile))) {
            return (List<Book>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return new ArrayList<>();
        }
    }

    @SuppressWarnings("unchecked")
    private synchronized List<User> loadUsers() {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(usersFile))) {
            return (List<User>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            return new ArrayList<>();
        }
    }

    private synchronized void saveBooks() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(booksFile))) {
            oos.writeObject(books);
        } catch (IOException e) {
            System.out.println("Error saving books.");
        }
    }

    private synchronized void saveUsers() {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(usersFile))) {
            oos.writeObject(users);
        } catch (IOException e) {
            System.out.println("Error saving users.");
        }
    }

    public synchronized void addBook(Book book) {
        books.add(book);
        saveBooks();
    }

    public synchronized void removeBook(String title, PrintWriter writer) {
        if (books.removeIf(book -> book.getTitle().equalsIgnoreCase(title))) {
            saveBooks();
            writer.println("Book removed successfully.");
        } else {
            writer.println("Book not found.");
        }
    }

    public synchronized void listBooks(PrintWriter writer) {
        if (books.isEmpty()) {
            writer.println("No books available.");
        } else {
            books.stream()
                    .filter(Book::isAvailable)
                    .forEach(book -> writer.println(book));
        }
    }

    public synchronized boolean borrowBook(String title, PrintWriter writer) {
        for (Book book : books) {
            if (book.getTitle().equalsIgnoreCase(title) && book.isAvailable()) {
                book.setAvailable(false);
                saveBooks();
                writer.println("Book borrowed successfully.");
                return true;
            }
        }
        writer.println("Book not available.");
        return false;
    }

    public synchronized void registerUser(User user) {
        users.add(user);
        saveUsers();
    }

    public synchronized User login(String username, String password) {
        return users.stream()
                .filter(user -> user.getUsername().equals(username) && user.validatePassword(password))
                .findFirst()
                .orElse(null);
    }
}
