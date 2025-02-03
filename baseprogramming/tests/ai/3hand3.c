#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[31];
    char expiry[8];
    long long code;
    float price;
    int count;
} Medicine;

Medicine* loadMeds(const char* filename, int* size) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("err opening file");
        exit(1);
    }

    Medicine* meds = NULL;
    char buff[100];
    *size = 0;

    while (fgets(buff, sizeof(buff), file)) {
        meds = (Medicine*)realloc(meds, (*size+1) * sizeof(Medicine));
        sscanf(buff, "%30[^;];%7[^;];%lld;%f;%d", meds[*size].name, meds[*size].expiry, &meds[*size].code, &meds[*size].price, &meds[*size].count);
        (*size)++;
    }
    if (fclose(file) != 0) {
        perror("close fail");
    }
    return meds;
}

bool isEarlier(const char* date1, const char* date2) {
    int y1, m1, y2, m2;
    sscanf(date1, "%2d.%4d", &m1, &y1);
    sscanf(date2, "%2d.%4d", &m2, &y2);
    if (y1 < y2) return true;
    if (y1 > y2) return false;
    return m1 < m2;
}

void discount(Medicine* meds, int size, const char* date) {
    bool found = false;
    for (int i = 0; i < size; i++) {
        if(isEarlier(meds[i].expiry, date)) {
            found = true;
            float oldprice = meds[i].price;
            meds[i].price *= 0.8;
            printf("%s-%s-%.2f leva-%.2f leva", meds[i].name, meds[i].expiry, oldprice, meds[i].price);
        }
    }
    if (!found) {
        printf("none found");
    }
}

void writeToOffer(Medicine* meds, int size, int minCount) {
    FILE* file = ("offer.bin", "wb");
    if (!file) {
        perror("no file found");
        return;
    }

    for (int i = 0; i < size; i++) {
        if (meds[i].count > minCount) {
            length = strlen(meds[i].name);
            fwrite(&length, sizeof(int), 1, file);
            fwrite(meds[i].name, sizeof(char), length, file);
            fwrite(meds[i].expiry, sizeof(char), 7, file);
            fwrite(&meds[i].code, sizeof(long long), 1, file);
            fwrite(&meds[i].price, sizeof(float), 1, file);
            fwrite(&meds[i].count, sizeof(int), 1, file);
        }
    }
    if (fclose(file) != 0) {
        perror("file close error");
    }
}

void delMed(Medicine** meds, int* size, long long code) {
    bool found = false;
    for (int i = 0; i < *size; i++) {
        if ((*meds)[i].code == code) {
            found = true;
            for (int j = i; j < *size - 1; j++) {
                (*meds)[j] = (*meds)[j + 1];
            }
            Medicine* temp = (Medicine*)realloc(*meds, (*size - 1) * sizeof(Medicine));
            if (temp == NULL && *size > 1) {
                perror("Reallocation failed");
                exit(EXIT_FAILURE);  // Handle error appropriately
            }
            *meds = temp;
            (*size)--;
            break;
        }
    }
    if (!found) {
        printf("none found\n");
    }
}

int main() {
    return 0;
}
