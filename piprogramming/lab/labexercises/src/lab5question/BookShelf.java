package lab5question;

import java.util.LinkedList;
import java.util.Queue;

public class BookShelf {
    private Queue<String> books;

    public BookShelf() {
        books = new LinkedList<>();
    }

    public void addBook(String book) {
        books.add(book);
    }

    public String takeBook() {
        if (books.isEmpty()) {
            return "no book";
        }
        return books.poll();
    }

    public static void main(String[] args) {
        var shelf = new BookShelf();
        shelf.addBook("Книга 1");
        var book = shelf.takeBook(); // Връща "Книга 1"
        System.out.println(book);
    }
}

