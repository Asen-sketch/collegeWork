#include <stdio.h>

int main() {
    double in, mm, cm, dm, m;
    int choice;

    printf("enter inches: ");
    scanf("%lf", &in);

    printf("\n1. milimeters\n2. centimeters\n3. decimeters\n4. meters\nconvert to?: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            mm = in * 25.4;
            printf("%.2lf in = %.2lf mm", in, mm);
            break;
        case 2:
            cm = in * 2.54;
            printf("%.2lf in = %.2lf cm", in, cm);
            break;
        case 3:
            dm = in * 0.254;
            printf("%.2lf in = %.2lf dm", in, dm);
            break;
        case 4:
            m = in * 0.0254;
            printf("%.2lf in = %.2lf m", in, m);
            break;
        default:
            printf("invalid");
            break;
    }
    return 0;
}
