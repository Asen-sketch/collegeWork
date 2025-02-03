#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double calculateTriangleArea(struct Point A, struct Point B, struct Point C) {
    double area;

    area = 0.5 * fabs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));

    return area;
}

int main() {
    struct Point A, B, C;

    printf("enter point A (x, y): ");
    scanf("%lf %lf", &A.x, &A.y);

    printf("enter point B (x, y): ");
    scanf("%lf %lf", &B.x, &B.y);

    printf("enter point C (x, y): ");
    scanf("%lf %lf", &C.x, &C.y);

    double area = calculateTriangleArea(A, B, C);

    printf("area of formed triangle: %.2lf\n", area);

    return 0;
}
