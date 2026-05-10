#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    FILE *fp;
    fp = fopen("chap6_task4_output.txt", "w");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        printf("Enter name (without spaces):\n");
        char name[50];
        scanf("%s", name);
        printf("Enter age:\n");
        int age;
        scanf("%d", &age);
        printf("Enter gender:\n");
        char gender[10];
        scanf("%s", gender);

        fprintf(fp, "%s,%d,%s\n", name, age, gender);

        printf("Do you want to enter another record? (y/n):\n");
        scanf(" %c", &choice);
    }

    printf("Data saved successfully to chap6_task4_output.txt.\n");

    fclose(fp);
    return 0;
}