#include <stdio.h>

int wordCount(char *str) {
    int count = 0;
    int inWord = 0;
    while (*str != '\0') {
        if (*str == ' ') {
            if (inWord) {
                count++;
                inWord = 0;
            }
        } else {
            inWord = 1;
        }
        str++;
    }
    if (inWord) {
        count++;
    }
    return count;
}

int main() {
    char text[] = "quick brown fox jumped over lazy dog";
    int count = wordCount(text);
    printf("word num: %d", count);
    return 0;
}
