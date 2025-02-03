class Book:
    def __init__(self, title, author, genre, publication_year, price):
        self.title = title
        self.author = author
        self.genre = genre
        self.publication_year = publication_year
        self.price = price
    
    def display_info(self):
        print(f"{self.title} | {self.author} | {self.genre} | {self.publication_year} | ${self.price}")

books = [Book('kniga','avtor','fentazi',2003, 15),Book('book','author','fantasy',2023, 25),Book('buch','author','phantasie',1999, 35),
         Book('livre','author','phantasie',2003, 55),Book('nz','nz','nz',2010, 15)]

def sort_by_year(books):
    books.sort(key=lambda x: x.publication_year)

def list_by_genre(books, genre):
    ls = list(filter(lambda x: x.genre == genre, books))
    if len(ls) == 0:
        print("No such book.")
    else:
        for x in ls:
            x.display_info()

def search_by_author(books, author_name):
    ls = list(filter(lambda x: x.author == author_name, books))
    if len(ls) == 0:
        print("No such book.")
    else:
        for x in ls:
            x.display_info()

def most_expensive_book(books):
    most = books[0]
    for x in books:
        if most.price < x.price:
            most = x
    most.display_info()

def recent_publication(books, year):
    ls = list(filter(lambda x: x.publication_year > year, books))
    if len(ls) == 0:
        print("No such books.")
    else:
        for x in ls:
            x.display_info()