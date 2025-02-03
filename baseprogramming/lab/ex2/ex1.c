#include <stdio.h>

int main() {
    int cnt;
    printf("Enter a number: ");
    scanf("%d", &cnt);
    int i = 0;

    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", i);
        }
        printf("\n");
    }
    return 0;
}
