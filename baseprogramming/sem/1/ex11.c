#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

double calculateRectangleArea(struct Point A, struct Point B) {
    double length, width;

    length = fabs(B.x - A.x);
    width = fabs(B.y - A.y);

    return length * width;
}

int main() {
    struct Point A, B;

    printf("enter coordinate A (x, y): ");
    scanf("%lf %lf", &A.x, &A.y);

    printf("enter coordinate B (x, y): ");
    scanf("%lf %lf", &B.x, &B.y);

    double area = calculateRectangleArea(A, B);

    printf("rectangle face is: %.2lf\n", area);

    return 0;
}
