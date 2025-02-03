#include <stdio.h>

int main() {
    char symbol;

    printf("enter symbol to build with: ");
    scanf("%c", &symbol);

    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= 10; j++) {
            if (i == 1 || i == 5 || j == 1 || j == 10) {
                printf("%c", symbol);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
