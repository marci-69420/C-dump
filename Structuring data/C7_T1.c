# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct {
    char name[50];
    float score;
} Student;

float average(Student** students, size_t n) {
    float sum = 0.0;
    for (size_t i = 0; i < n; i++) {
        sum += students[i]->score;
    }
    return sum / n;
}

Student* create_student(const char* name, float score) {

    Student* new_student = (Student*)malloc(sizeof(Student));
    if (new_student == NULL) {
        puts("Memory allocation failed");
        return NULL; 
    }

    strcpy(new_student->name, name);
    new_student->score = score;
    return new_student;
}


int main() {

    printf("Enter the number of students: ");
    int n;
    scanf("%d", &n);

    Student** students = (Student**)malloc(n * sizeof(Student*));
    if (students == NULL) {
        puts("Memory allocation failed");
        return 1;
    }

    for (int i =0; i < n; i++) {
        char name[50];
        float score;

        printf("Enter name for student %d: ", i+1);
        scanf("%s", name);
        printf("Enter score for student %d: ", i+1);
        scanf("%f", &score);

        students[i] = create_student(name, score);
    }

    float avg = average(students, n);
    printf("\nThe average score of %d students is: %.2f\n", n, avg);

    free(students);
    return 0;
}