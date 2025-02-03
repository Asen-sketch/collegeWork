#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    char date[11]; // dd.mm.yyyy
    char name[31];
    char casus[51];
} Treatment;

int count_treatment (Treatment* history, int n, const char* name, const char* casus) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(history[i].name, name) == 0 && strcmp(history[i].casus, casus) == 0) { //strcmp for strings only !!!
            count++;
        }
    }

    return count;
}

bool isValidDate(const char* date) {
    int y, m, d;
    sscanf(date, "%2d.%2d.%4d", &d, &m, &y);
    return y >= 1000 && m >= 1 && m <= 12 && d >= 1 && d <= 31;
}

Treatment* add_new_treatment(Treatment *history, int *size) {
    Treatment entry;
    printf("id: ");
    scanf("%d", &entry.id);
    printf("enter date (dd.mm.yyyy");
    scanf("%10s", entry.date);
    if (!isValidDate(entry.date)) {
        printf("invalid date");
        return history;
    }
    printf("enter name: ");
    scanf("%30s", entry.name);
    printf("casus: ");
    scanf("%50s", entry.casus);

    (*size)++;
    Treatment *temp = (Treatment*)realloc(history, (*size) * sizeof(Treatment));
    if (temp == NULL) {
        perror("memory alloc fail");
        (*size)--;
        return history;
    }
    history = temp;
    history[(*size)-1] = entry;
    return history;
}

int write_text_file(Treatment* history, int size, const char* casus) {
    int count = 0;
    FILE* file = fopen("illness.txt", "w");
    if (!file) {
        perror("err opening file");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if (strcmp(history[i].casus, casus) == 0) {
            fprintf(file, "Болничен пресой на %s за лечение на %s: %s", history[i].name, history[i].casus, history[i].date);
            count++;
        }
    }
    fclose(file);
    return count;
}

int main() {
    FILE* file = fopen("history.bin", "br");
    if (!file) {
        perror("err opening file");
        return -1;
    }

    int n;
    if (fread(&n, sizeof(int), 1, file) != 1) { //when reading from binary files you must know the amount to write to the array, the first 4 bytes say that
        perror("err reading count");
        fclose(file);
        return -1;
    }

    Treatment* history = (Treatment*)malloc(n * sizeof(Treatment));
    if (history == NULL) {
        perror("memory alloc fail");
        fclose(file);
        return -1;
    }

    if (fread(history, sizeof(Treatment), n, file) != n) {
        perror("err reading file");
        free(history);
        fclose(file);
        return -1;
    }

    free(history); //never forget freeing and closing files
    fclose(file);
    return 0;
}
