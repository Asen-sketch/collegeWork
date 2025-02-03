#include <stdio.h>

int main() {
    int x = 10;
    int *ptr;

    ptr = &x;

    printf("Address for int 'x': %p\n", (void*)&x);
    printf("Value of int 'x': %d\n", x);
    printf("'ptr' is declared, pointing to 'x'.\n");
    printf("Address of pointer 'ptr': %p\n", (void*)ptr);
    printf("Value pointed to by 'ptr': %d\n", *ptr);

    return 0;
}
