package sem4;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Task4 {

    public static class Book implements Serializable {
        private String title;
        private String author;

        public Book(String title, String author) {
            this.title = title;
            this.author = author;
        }

        @Override
        public String toString() {
            return "Book{" +
                    "title='" + title + '\'' +
                    ", author='" + author + '\'' +
                    '}';
        }
    }

    public static void main(String[] args) {
        String fileName = "books.ser";

        List<Book> books = new ArrayList<>();
        books.add(new Book("book1", "author1"));
        books.add(new Book("book2", "author2"));
        books.add(new Book("book3", "author3"));

        serializeBooks(fileName, books);

        List<Book> deserializedBooks = deserializeBooks(fileName);

        System.out.println("Deserialized books:");
        for (Book book : deserializedBooks) {
            System.out.println(book);
        }
    }

    public static void serializeBooks(String fileName, List<Book> books) {
        try (ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream(fileName))) {
            oos.writeObject(books);
            System.out.println("Books have been serialized to " + fileName);
        } catch (IOException e) {
            System.err.println("Error during serialization: " + e.getMessage());
        }
    }

    public static List<Book> deserializeBooks(String fileName) {
        try (ObjectInputStream ois = new ObjectInputStream(new FileInputStream(fileName))) {
            return (List<Book>) ois.readObject();
        } catch (IOException | ClassNotFoundException e) {
            System.err.println("Error during deserialization: " + e.getMessage());
            return new ArrayList<>();
        }
    }
}
