#include <stdio.h>

int main() {
    double a, b, h, area;

    printf("enter upper base (a): ");
    scanf("%lf", &a);
    printf("enter lower base (b): ");
    scanf("%lf", &b);
    printf("enter height (h): ");
    scanf("%lf", &h);

    area = (a + b) * h / 2;

    printf("face of trapezoid: %.2lf\n", area);

    return 0;
}
