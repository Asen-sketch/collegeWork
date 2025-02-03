#include <stdio.h>

int main() {
    int x = 2, n = 0;

    while (x <= 100) {
        x = 2 * x + 10;
        n++;
    }

    printf("The first x_n > 100 is x_%d = %d\n", n, x);
    return 0;
}
