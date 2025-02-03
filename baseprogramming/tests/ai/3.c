#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Дефиниране на структурата Medicine
typedef struct {
    char name[31];         // Наименование на лекарството (30 символа + 1 за нулев терминатор)
    char expirationDate[8];// Дата на годност в формат MM.GGGG (7 символа + 1 за нулев терминатор)
    long long code;        // Код на лекарство (тринадесетцифрено цяло число)
    float price;           // Единична цена (реално число)
    int quantity;          // Налично количество (цяло число)
} Medicine;

// Функция за четене на данни от файл и зареждането им в динамичен масив от структури
Medicine* loadMedicines(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Не може да се отвори файла %s\n", filename);
        exit(1);
    }

    Medicine* medicines = NULL;
    *size = 0;
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        // Увеличаваме размера на масива с една структура
        medicines = (Medicine*)realloc(medicines, (*size + 1) * sizeof(Medicine));

        // Четем данните от реда и ги записваме в новата структура
        sscanf(line, "%30[^;];%7[^;];%lld;%f;%d",
               medicines[*size].name,
               medicines[*size].expirationDate,
               &medicines[*size].code,
               &medicines[*size].price,
               &medicines[*size].quantity);

        (*size)++;
    }

    fclose(file);
    return medicines;
}

// Функция за сравняване на две дати в формат ММ.ГГГГ
bool isEarlierDate(const char* date1, const char* date2) {
    int month1, year1, month2, year2;
    sscanf(date1, "%2d.%4d", &month1, &year1);
    sscanf(date2, "%2d.%4d", &month2, &year2);

    if (year1 < year2) return true;
    if (year1 > year2) return false;
    return month1 < month2;
}

// Функция за намаляване на цените на лекарствата с изтичаща годност
void reducePrices(Medicine* medicines, int size, const char* date) {
    bool found = false;

    for (int i = 0; i < size; i++) {
        if (isEarlierDate(medicines[i].expirationDate, date)) {
            float oldPrice = medicines[i].price;
            medicines[i].price *= 0.8; // Намаляване с 20%
            found = true;
            printf("%s - %s - %.2f лева - %.2f лева\n", medicines[i].name, medicines[i].expirationDate, oldPrice, medicines[i].price);
        }
    }

    if (!found) {
        printf("Няма лекарства, чиято годност изтича преди %s\n", date);
    }
}

void writeToOfferFile(Medicine* medicines, int size, int minQuantity) {
    FILE* file = fopen("offer.bin", "wb");
    if (!file) {
        perror("Грешка при отваряне на файла offer.bin");
        return;
    }

    for (int i = 0; i < size; i++) {
        if (medicines[i].quantity > minQuantity) {
            int nameLength = strlen(medicines[i].name);
            fwrite(&nameLength, sizeof(int), 1, file);                     // Записваме дължината на низа на наименованието
            fwrite(medicines[i].name, sizeof(char), nameLength, file);    // Записваме наименованието
            fwrite(medicines[i].expirationDate, sizeof(char), 7, file);   // Записваме датата на годност
            fwrite(&medicines[i].code, sizeof(long long), 1, file);       // Записваме кода на лекарството
            fwrite(&medicines[i].price, sizeof(float), 1, file);          // Записваме единичната цена
            fwrite(&medicines[i].quantity, sizeof(int), 1, file);         // Записваме наличното количество
        }
    }

    if (fclose(file) != 0) {
        perror("Грешка при затваряне на файла offer.bin");
    }
}

void deleteMedicine(Medicine** medicines, int* size, long long code) {
    bool found = false;
    for (int i = 0; i < *size; i++) {
        if ((*medicines)[i].code == code) {
            found = true;
            // Преместване на останалите елементи
            for (int j = i; j < *size - 1; j++) {
                (*medicines)[j] = (*medicines)[j + 1];
            }
            // Намаляване на размера на динамичния масив
            *medicines = (Medicine*)realloc(*medicines, (*size - 1) * sizeof(Medicine));
            (*size)--;
            printf("Лекарството с код %lld е изтрито.\n", code);
            break;
        }
    }

    if (!found) {
        printf("Лекарство с код %lld не е намерено.\n", code);
    }
}

int main() {
    int size;
    Medicine* medicines = loadMedicines("medicines.txt", &size);

    // Принтиране на прочетените данни за проверка
    for (int i = 0; i < size; i++) {
        printf("Лекарство %d:\n", i + 1);
        printf("  Наименование: %s\n", medicines[i].name);
        printf("  Дата на годност: %s\n", medicines[i].expirationDate);
        printf("  Код: %lld\n", medicines[i].code);
        printf("  Единична цена: %.2f\n", medicines[i].price);
        printf("  Налично количество: %d\n", medicines[i].quantity);
    }

    // Освобождаваме динамичната памет
    free(medicines);

    return 0;
}
