#include <stdio.h>

int strLength(char *str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    char greet[20] = "Hello!";
    int len = strLength(greet);
    printf("%d", len);
    return 0;
}


