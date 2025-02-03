#include <stdio.h>

int main() {
    int num;
    printf("Enter number: ");
    scanf("%d", &num);
    if (num % 8 > 4) {
        printf("Remainder is bigger than 4!");
    }

    return 0;
}
