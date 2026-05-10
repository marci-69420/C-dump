#include <stdio.h>

typedef struct Student {
    char name[50];
    int marks[5];  // Array to store marks in 5 subjects
    void (*show)(struct Student);
    float (*countGPA)(struct Student);
} Student;


void show(Student s) {
    printf("\nStudent Name: %s", s.name);
    printf("Student's grade:\n");
    for (int i = 0; i < 5; i++) {
        printf("Course %d: %d\n", i + 1, s.marks[i]);
    }
}

float countGPA(Student s) {
    int total = 0;
    for (int i = 0; i < 5; i++) {
        total += s.marks[i];
    }
    return (float)total / 5.0;
}

void ConstructStudent(Student *s) {
    printf("Enter student name:\n");
    fgets(s->name, sizeof(s->name), stdin);

    printf("Enter grade for 5 courses.\n");
    for (int i=0; i <5 ; i++) {
        printf("Course %d: ", i + 1);
        scanf("%d", &s->marks[i]);
    }
    s->show = show;
    s->countGPA = countGPA;

}


int main() {
    Student s1;

    ConstructStudent(&s1);
    s1.show(s1);
    printf("GPA: %.2f\n", s1.countGPA(s1));

    return 0;
}