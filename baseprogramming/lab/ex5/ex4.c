#include <stdio.h>
#define MAX_LENGTH 100

int strcmp(char str1[MAX_LENGTH], char str2[MAX_LENGTH]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] > str2[i]) {
            return 1;
        } else if (str1[i] < str2[i]) {
            return -1;
        }
        i++;
    }
    if (str1[i] == '\0' && str2[i] == '\0') {
        return 0;
    } else if (str1[i] == '\0' && str2[i] != '\0') {
        return -1;
    }
    return 1;
}

int main() {
    char str1[MAX_LENGTH], str2[MAX_LENGTH];
    printf("Enter the first string: ");
    scanf("%s", str1);
    printf("Enter the second string: ");
    scanf("%s", str2);
    if (strcmp(str1, str2) == 0) {
        printf("The strings are equal.\n");
    } else if (strcmp(str1, str2) < 0) {
        printf("The first string is less than the second string.\n");
    } else {
        printf("The first string is greater than the second string.\n");
    }
    return 0;
}
