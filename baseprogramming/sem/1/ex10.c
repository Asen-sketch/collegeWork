#include <stdio.h>
#include <math.h>

int main() {
    double angle_degrees;
    double angle_radians;
    double sin_value, cos_value, tan_value, cotan_value;

    printf("enter angle: ");
    scanf("%lf", &angle_degrees);

    angle_radians = angle_degrees * (M_PI / 180);

    sin_value = sin(angle_radians);
    cos_value = cos(angle_radians);
    tan_value = tan(angle_radians);
    cotan_value = 1.0 / tan_value;

    printf("sin: %.6lf\n", sin_value);
    printf("cosin: %.6lf\n", cos_value);
    printf("tan: %.6lf\n", tan_value);
    printf("cotan: %.6lf\n", cotan_value);

    return 0;
}
