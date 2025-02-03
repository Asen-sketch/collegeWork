#include <stdio.h>

int main() {
    int N, K;
    int count = 0;

    printf("Enter nums N and K: ");
    scanf("%d %d", &N, &K);

    printf("Enter %d more numbers: ", N);
    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d", &num);
        if (num > K && num % 3 == 0) {
            count++;
        }
    }

    printf("Count of nums greater than %d and divisble by 3, is: %d\n", K, count);

    return 0;
}
