#include <stdio.h> // include these in your cheatsheet along with the space%30s[^/n] lifehack
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int id;
    char date[11];
    char name[31];
    char casus[51];
} Treatment;

bool isValidDate(const char* date) {
    int y, m, d;
    return sscanf(date, "%2d.%2d.%4d", &d, &m, &y) == 3 && y >= 1000 && m >= 1 && m <= 12 && d >= 1 && d <= 31;

}

int count_treatment(Treatment* history, int size, const char* casus) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(history[i].casus, casus) == 0) {
            count++;
        }
    }
    return count;
}

Treatment* add_new_treatment(Treatment* history, int* size) {
    Treatment entry;
    printf("enter info for visit\n");
    printf("enter id: ");
    scanf("%d", entry.id);
    printf("enter date (dd.mm.yyyy): ");
    scanf("%10s", entry.date);
    if (!isValidDate(entry.date)) {
        printf("invalid date\n");
        return history;
    }
    printf("enter name: ");
    scanf("%30s", entry.name);
    printf("enter casus: ");
    scanf("%50s", entry.casus);

    Treatment* temp = (Treatment*)realloc(history, (*size + 1) * sizeof(Treatment));
    if (temp == NULL) {
        printf("Error allocating memory\n");
        return history;
    }

    history = temp;
    history[*size] = entry;
    (*size)++;
    return history;
}

int write_text_file(Treatment* history, int size, const char* casus) {
    FILE* file = fopen("illness.txt", "w");
    if (!file) {
        perror("err opening file");
        return -1;
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(history[i].casus, casus) == 0) {
            count++;
            fprintf(file, "Bolnichen prestoi na %s za lechenie na %s: %s\n", history[i].name, history[i].casus, history[i].date);
        }
    }

    if (fclose(file) != 0) {
        perror("err closing file");
    }
    return count;
}

int main() {
    FILE* file = fopen("history.bin", "rb");
    if (!file) {
        perror("file open fail");
        return -1;
    }

    int n;
    if (fread(&n, sizeof(int), 1, file) != 1) {
        perror("err reading count");
        if (fclose(file) != 0) {
            perror("file close fail");
        }
        return -1;
    }

    Treatment* history = (Treatment*)malloc(n * sizeof(Treatment));
    if (history == NULL) {
        perror("memory alloc fail");
        if (fclose(file) != 0) {
            perror("file close fail");
        }
        return -1;
    }

    if (fread(history, sizeof(Treatment), n, file) != n) {
        perror("err filling array");
        free(history);
        if (fclose(file) != 0) {
            perror("file close fail");
        }
        return -1;
    }

    if (fclose(file) != 0) {
        perror("file close fail");
        return -1;
    }

    free(history);
    return 0;
}

