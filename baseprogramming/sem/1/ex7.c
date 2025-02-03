#include <stdio.h>
#include <math.h>

int main() {
    double angle, rad;

    printf("enter angle: ");
    scanf("%lf", &angle);

    rad = angle * (M_PI/180);
    printf("angle in radians: %.2lf", rad);

    return 0;
}
