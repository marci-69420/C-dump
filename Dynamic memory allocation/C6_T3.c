#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *fp;
    char filename[50];
    char buffer[100];

    printf("Enter the filename:\n");
    scanf("%s", filename);
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    printf("\nReading csv file...\n");

    fgets(buffer, sizeof(buffer), fp);

    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\r\n")] = 0;
        char *year = strtok(line, ",");
        char *first_name = strtok(NULL, ",");
        char *last_name = strtok(NULL, ",");
        char *gender = strtok(NULL, ",");
        
        if (first_name != NULL && last_name != NULL && gender != NULL && year != NULL) {
    
        int birth_year = atoi(year);
        int age = 2100 - birth_year;

        
        printf("Name: %s %s, Gender: %s, Birth Year: %d, Age in 2100: %d\n", first_name, last_name, gender, birth_year, age);
    }
    }

    fclose(fp);
    return 0;
}
