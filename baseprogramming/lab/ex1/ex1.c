#include <stdio.h>
#include <math.h>

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);

    double mul = a * b;
    double div = a / b;
    double rem = fmod(a, b);

    printf("Multiplication: %.2lf * %.2lf = %.2lf\n", a, b, mul);
    printf("Division: %.2lf / %.2lf = %.2lf\n", a, b, div);
    printf("Remainder of %.2lf / %.2lf = %.2lf\n", a, b, rem);

    return 0;
}
