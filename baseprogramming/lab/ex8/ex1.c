#include <stdio.h>
#include <math.h>

struct Point {
    float x;
    float y;
};

float distance(struct Point p1, struct Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    struct Point points[3];
    printf("Enter coordinates for point 1 (x y): ");
    scanf("%f %f", &points[0].x, &points[0].y);
    printf("Enter coordinates for point 2 (x y): ");
    scanf("%f %f", &points[1].x, &points[1].y);
    printf("Enter coordinates for point 3 (x y): ");
    scanf("%f %f", &points[2].x, &points[2].y);

    float side1 = distance(points[0], points[1]);
    float side2 = distance(points[1], points[2]);
    float side3 = distance(points[2], points[0]);

    printf("Side 1: %.2f\n", side1);
    printf("Side 2: %.2f\n", side2);
    printf("Side 3: %.2f\n", side3);

    return 0;
}
