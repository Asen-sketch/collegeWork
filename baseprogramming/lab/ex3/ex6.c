#include <stdio.h>

void sum(int num1, int num2, int *res) {
    *res = num1 + num2;
}
void diff(int num1, int num2, int *res) {
    *res = num1 - num2;
}
void prod(int num1, int num2, int *res) {
    *res = num1 * num2;
}
void div(int num1, int num2, float *res) {
    *res = (float)num1/num2;
}

int main() {
    int x = 10, y = 5;
    int sum_res, diff_res, prod_res;
    float div_res;

    sum(x, y, &sum_res);
    printf("Sum of %d and %d is %d\n", x, y, sum_res);

    diff(x, y, &diff_res);
    printf("Difference between %d and %d is %d\n", x, y, diff_res);

    prod(x, y, &prod_res);
    printf("Product between %d and %d is %d\n", x, y, prod_res);

    div(x, y, &div_res);
    printf("Quotient of %d and %d is %.2f\n", x, y, div_res);
}
