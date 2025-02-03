#include <stdio.h>
#include <math.h>

float areaSquare(float side) {
    return side * side;
}

float areaRectangle(float length, float width) {
    return length * width;
}

float areaTriangle(float base, float height) {
    return 0.5 * base * height;
}

float areaCircle(float radius) {
    return M_PI * radius * radius;
}

int main() {
    int choice;
    float x1, x2, result;

    printf("Enter shape (1-square, 2-rectangle, 3-right triangle, 4-circle): ");
    scanf("%d", &choice);

    printf("Enter parameters: ");
    if(choice == 1 || choice == 4) {
        scanf("%f", &x1);
    } else {
        scanf("%f %f", &x1, &x2);
    }

    switch(choice) {
        case 1:
            result = areaSquare(x1);
            printf("Square\n");
            break;
        case 2:
            result = areaRectangle(x1, x2);
            printf("Rectangle\n");
            break;
        case 3:
            result = areaTriangle(x1, x2);
            printf("Right Triangle\n");
            break;
        case 4:
            result = areaCircle(x1);
            printf("Circle\n");
            break;
        default:
            printf("INVALID\n");
            return 1;
    }

    printf("Face: %.2f\n", result);

    return 0;
}
