#include <stdio.h>

int main() {
    char symbol;

    printf("enter symbol to chart with: ");
    scanf(" %c", &symbol);

    printf("triangle:\n");
    for(int i = 1; i <= 5; i++) {
        for(int j = 1; j <= 5 - i; j++) {
            printf(" ");
        }
        for(int k = 1; k <= (2 * i - 1); k++) {
            if(k == 1 || k == (2 * i - 1))
                printf("%c", symbol);
            else
                printf(" ");
        }
        printf("\n");
    }

    for (int i = 1; i <= 9; i++) {
        printf("%c", symbol);
    }

    printf("\nupside down triangle:\n");

    for (int i = 1; i <= 9; i++) {
        printf("%c", symbol);
    }
    printf("\n");

    for(int i = 5; i >= 1; i--) {
        for(int j = 1; j <= 5 - i; j++) {
            printf(" ");
        }
        for(int k = 1; k <= (2 * i - 1); k++) {
            if(k == 1 || k == (2 * i - 1))
                printf("%c", symbol);
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
