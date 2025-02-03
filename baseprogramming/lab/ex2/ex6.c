#include <stdio.h>

double f(double x) {
    return x * x - 4;
}

int main() {
    double start, end;

    printf("Enter start of interval: ");
    scanf("%lf", &start);

    printf("Enter end of interval: ");
    scanf("%lf", &end);

    printf("Values of func f(x) = x*x - 4 in interval [%lf, %lf]:\n", start, end);
    for (double x = start; x <= end; x += 0.01) {
        printf("f(%.2lf) = %.2lf\n", x, f(x));
    }

    return 0;
}
