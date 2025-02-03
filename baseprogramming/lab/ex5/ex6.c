#include <stdio.h>
#include <string.h>

int main() {
    const int max_len = 100;
    char str[max_len];
    printf("Enter a string: ");
    fgets(str, max_len, stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
    printf("Uppercase: %s\n", str);
    return 0;
}
