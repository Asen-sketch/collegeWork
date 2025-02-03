#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    float diameter;
    printf("Enter diameter of the circle: ");
    scanf("%f", &diameter);

    float radius = diameter / 2;
    float circumference = 2 * PI * radius;

    printf("Circumference of the circle: %.2f\n", circumference);
    return 0;
}
