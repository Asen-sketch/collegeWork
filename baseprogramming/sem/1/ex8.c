#include <stdio.h>

int main() {
    double bgn, usd, eur, gbp;
    int choice;

    printf("enter bgn: ");
    scanf("%lf", &bgn);

    printf("\n1. usd\n2. eur\n3. gbp\nconvert to?: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            usd = bgn / 1.71;
            printf("bgn to usd: %.2lf", usd);
            break;
        case 2:
            eur = bgn / 1.96;
            printf("bgn to eur: %.2lf", eur);
            break;
        case 3:
            gbp = bgn / 2.28;
            printf("bgn to gbp: %.2lf", gbp);
            break;
        default:
            printf("invalid");
            break;
    }


    return 0;
}
