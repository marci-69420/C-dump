#include <stdio.h>

struct Student {
    int ID;
    char name[50];
    float GPA;
};

int main () {
    struct Student student1 = {1002, "Charlie", 3.95};
    FILE *file = fopen("students.bin", "w");
    fseek(file, 2, SEEK_SET);
    fwrite(&student1, sizeof(struct Student), 1, file);
    fread(&student1, sizeof(struct Student), 1, file);
    printf("ID: %d, Name: %s, GPA: %.2f\n", student1.ID, student1.name, student1.GPA);
    fclose(file);
    return 0;
}
