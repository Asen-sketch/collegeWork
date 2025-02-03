#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    float score;
};

struct Class {
    struct Student students[50];
    int numStudents;
};

float calculateClassAverage(struct Class class) {
    float totalScore = 0;
    for (int i = 0; i < class.numStudents; i++) {
        totalScore += class.students[i].score;
    }
    return totalScore / class.numStudents;
}

int main() {
    struct Class class;
    class.numStudents = 3;

    printf("Enter data for students:\n");
    for (int i = 0; i < class.numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", class.students[i].name);
        printf("Age: ");
        scanf("%d", &class.students[i].age);
        printf("Score: ");
        scanf("%f", &class.students[i].score);
    }

    float classAverage = calculateClassAverage(class);
    printf("Average score of the class: %.2f\n", classAverage);

    return 0;
}
