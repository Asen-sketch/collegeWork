#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define SIZE 6

char *M[SIZE]= {
    "1-Input",
    "2-Output",
    "3-Sum",
    "4-Max",
    "5-Sum of even",
    "6-Exit"
};

int* input(int *br, int *mas);
void out(int br, int *mas);
int sum (int br, int *mas);
int sum_even(int br, int *mas);
int max(int br, int *mas);

int main() {
    int cod, n = 0, *p = NULL, flag = 0;

    do {
        for(int i = 0; i < SIZE; i++)
            puts(M[i]);

        printf("Enter code:");
        scanf("%d", &cod);

        switch(cod) {
            case 1:
                p = input(&n, p); flag = 1; break;
            case 2:
                if (flag == 1) out (n, p);
                else printf("Enter first!\n");
                _getch();
                break;
            case 3:
                if (flag == 1) {
                    out(n, p);
                    printf("Sum = %d\n", sum(n, p));
                } else printf("Enter first!");
                _getch();
                break;
            case 4:
                if (flag == 1) {
                    out(n, p);
                    printf("Max = %d\n", max(n, p));
                } else printf("Enter first!");
                _getch();
                break;
            case 5:
                if (flag == 1) {
                    out(n, p);
                    printf("Sum of even = %d\n", sum_even(n, p));
                } else printf("Enter first!");
                _getch();
                break;
            case 6:
                if (p != NULL) {
                    free(p);
                    printf("Memory freed!\n");
                    p = NULL;
                }
                exit(1);
                break;
            default:
                printf("Invalid code!");
                _getch();
            }

            system("cls");
        } while(1);

    return 0;
}

int* input(int *br, int *mas) {
    int k = 0;
    printf("Enter size: "); scanf("%d", &k);
    mas = (int *)malloc(k*sizeof(int));
    if (mas == NULL) {
        printf("No memory."); exit(1);
    }
    for (int i = 0; i<k; i++) {
        printf("[%d] = ", i); scanf("%d", (mas + i));
    }
    *br = k;
    return mas;
}

void out(int br, int *mas) {
    int i;
    for (i = 0; i < br; i++) {
        printf("[%d] = %d\n", i, *(mas+i));
    }
}

int sum(int br, int *mas) {
    int sum = 0, i;
    for (int i = 0; i < br; i++) {
        sum +=*(mas+i);
    }
    return sum;
}

int sum_even(int br, int *mas) {
    int sum = 0;
    for (int i = 0; i < br; i++) {
        if (*(mas + i) % 2 == 0) {
            sum += *(mas + i);
        }
    }
    return sum;
}

int max(int br, int *mas) {
    int m;
    m = mas[0];
    for (int i = 1; i < br; i++) {
        if(*(mas+i) > m) {
            m=*(mas+i);
        }
    }
    return m;
}
