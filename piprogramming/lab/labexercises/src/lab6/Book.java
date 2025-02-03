package lab6;


import java.util.Objects;

class Book {
    private int year;
    private String title;
    private Genre genre;

    public Book(int year, String title, Genre genre) {
        this.year = year;
        this.title = title;
        this.genre = genre;
    }

    public int getYear() {
        return year;
    }

    public String getTitle() {
        return title;
    }

    public Genre getGenre() {
        return genre;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Book book = (Book) o;
        return year == book.year &&
                Objects.equals(title, book.title) &&
                genre == book.genre;
    }

    @Override
    public int hashCode() {
        int result = Integer.hashCode(year);
        result = 31 * result + (title != null ? title.hashCode() : 0);
        result = 31 * result + (genre != null ? genre.hashCode() : 0);
        return result;
    }


    @Override
    public String toString() {
        return "Book{" + "year=" + year + ", title='" + title + "', genre=" + genre + '}';
    }
}
