//Създайте клас Book с полета за година на издаване, заглавие и жанр (enum).
//       Създайте колекция от книги.
//       С помощта на Stream:
//
//       1. Принтирайте всеки елемент с forEach.
//       2. Сортирайте колекцията по година.
//       3. Създайте списък само със заглавията с функцията map.
//       4. Групирайте книгите по жанр с collect(Collectors.groupingBy()).

package lab6;

import java.util.*;
import java.util.stream.Collectors;

public class BookStreamExample {
    public static void main(String[] args) {
        List<Book> books = Arrays.asList(
                new Book(2020, "book1", Genre.FICTION),
                new Book(2023, "book2", Genre.FANTASY),
                new Book(2020, "book4", Genre.FANTASY),
                new Book(2024, "book5", Genre.FANTASY),
                new Book(2019, "book3", Genre.SCIENCE),
                new Book(2019, "book3", Genre.SCIENCE),
                new Book(2019, "book3", Genre.SCIENCE)
        );

        // 1
        books.stream()
                .distinct()
                .forEach(System.out::println);

        // 2
        List<Book> sortedByYear = books.stream()
                .distinct()
                .sorted(Comparator.comparingInt(Book::getYear))
                .collect(Collectors.toList());
        System.out.println("\nyearsort:");
        sortedByYear.forEach(System.out::println);

        // 3
        List<String> titles = books.stream()
                .map(Book::getTitle)
                .distinct()
                .sorted()
                .collect(Collectors.toList());
        System.out.println("\ntitlesort:");
        titles.forEach(System.out::println);

        // 4
        Map<Genre, List<Book>> booksByGenre = books.stream()
                .distinct()
                .collect(Collectors.groupingBy(Book::getGenre));
        System.out.println("\ngenresort:");
        booksByGenre.forEach((genre, booksList) -> {
            System.out.println(genre + ": " + booksList);
        });
    }
}
