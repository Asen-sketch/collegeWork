#include <stdio.h>

int main() {
    double cel, far;

    printf("insert degrees celsius: ");
    scanf("%lf", &cel);

    far = cel*(9.0/5)+32;

    printf("\ndegrees fahrenheit: %.2lf", far);

    return 0;
}
