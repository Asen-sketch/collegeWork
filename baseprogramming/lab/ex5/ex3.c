#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void printLetterCounts(int counts[26]) {
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 0) {
            printf("%c: %d\n", 'a' + i, counts[i]);
        }
    }
}

int main() {
    char str[MAX_LENGTH];
    int letterCounts[26] = {0};
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);
    str[strcspn(str, "\n")] = '\0';
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            letterCounts[str[i] - 'a']++;
        } else if (str[i] >= 'A' && str[i] <= 'Z') {
            letterCounts[str[i] - 'A']++;
        }
    }
    printf("Letter counts:\n");
    printLetterCounts(letterCounts);
    return 0;
}
