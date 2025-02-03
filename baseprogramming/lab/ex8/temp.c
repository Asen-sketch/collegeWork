#include <stdio.h>
#include <string.h>
struct Books {
 char title[50];
 char author[50];
 char subject[100];
 int book_id;
};
void printBook( struct Books *book );
int main( ) {
 struct Books Book1;
 struct Books Book2;
 strcpy( Book1.title, "C Programming");
 strcpy( Book1.author, "Spiridon Haralampiev");
 strcpy( Book1.subject, "C Programming Tutorial");
 Book1.book_id = 6495407;
 /* book 2 specification */
 strcpy( Book2.title, "BPE materials");
 strcpy( Book2.author, "Haralampi Spiridonov");
 strcpy( Book2.subject, "Materials for BPE subject");
 Book2.book_id = 6495700;
 /* print Book1 info by passing address of Book1 */
 printBook( &Book1 );
 /* print Book2 info by passing address of Book2 */
 printBook( &Book2 );
 return 0;
}
void printBook( struct Books *book ) {
 printf( "Book title : %s\n", book->title);
 printf( "Book author : %s\n", book->author);
 printf( "Book subject : %s\n", book->subject);
 p
