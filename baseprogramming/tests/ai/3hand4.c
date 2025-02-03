#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// best attempt so far, sure for 100p
typedef struct {
    char name[31];
    char expiry[8];
    long long code; //this bitch hungry taking 10 nums
    float price;
    int count;
} Medicine;

bool isEarlier(const char* date1, const char* date2) {
    int m1, m2, y1, y2;
    sscanf(date1, "%2d.%4d", &m1, &y1);
    sscanf(date2, "%2d.%4d", &m2, &y2);
    if (y1 < y2) return true;
    if (y1 > y2) return false;
    return m1 < m2;
}

void discount(Medicine* meds, int size, const char* date) {
    for (int i = 0; i < size; i++) {
        if (isEarlier(meds[i].expiry, date)) {
            float oldPrice = meds[i].price;
            meds[i].price *= 0.8;
            printf("%s-%s-%.2f leva-%.2f leva", meds[i].name, meds[i].expiry, oldPrice, meds[i].price);
        }
    }
}

void writeToOffer(Medicine* meds, int size, int minCount) {
    FILE* file = fopen("offer.bin", "wb");
    if (!file) {
        perror("err opening file");
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        if (meds[i].count > minCount) {
            int len = strlen(meds[i].name);
            fwrite(&len, sizeof(int), 1, file);
            fwrite(meds[i].name, sizeof(char), len, file);
            fwrite(meds[i].expiry, sizeof(char), 8, file); // YEAH THESE TAKE NULL TERMS TOO LMAO
            fwrite(&meds[i].code, sizeof(long long), 1, file);
            fwrite(&meds[i].price, sizeof(float), 1, file);
            fwrite(&meds[i].count, sizeof(int), 1, file);
        }
    }
    if (fclose(file) != 0) {
        perror("err closing file");
    }
}

void delMed(Medicine** meds, int* size, long long code) { //arrays always use pointers, pointer after type, pointer before varname, do (*ptr) before actions
    bool found = false;

    for (int i = 0; i < *size; i++) {
        if ((*meds)[i].code == code) {
            found = true;
            for (int j = i; j < (*size)-1; j++) {
                (*meds)[j] = (*meds)[j+1];
            }
            Medicine* temp = (Medicine*)realloc(*meds, (*size - 1) * sizeof(Medicine));
            if (temp == NULL && *size > 1) {
                perror("memory alloc fail");
                exit(1);
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

Medicine* loadMeds(const char* filename, int* size) {
    FILE* file = fopen("medicines.txt", "r");
    if (!file) {
        perror("err opening file");
        exit(1);
    }

    Medicine* meds = NULL;
    char buff[100];
    *size = 0;

    while (fgets(buff, sizeof(buff), file)) {
        Medicine* temp = (Medicine*)realloc(meds, (*size + 1) * sizeof(Medicine));
        if (temp == NULL) {
            perror("memory realloc fail");
            free(meds);
            fclose(file);
            exit(1);
        }
        meds = temp;
        sscanf(buff, "%30[^;];%7[^;];%lld;%f;%d", meds[*size].name, meds[*size].expiry, &meds[*size].code, &meds[*size].price, &meds[*size].count);
        (*size)++;
    }
    if (fclose(file) != 0) {
        perror("err closing file");
    }
    return meds;
}

int main() {
    return 0; //missed a few lines did i lol
}
