#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int birthYear;
    char firstName[50];
    char lastName[50];
    char gender[20];
} Person;

void sortRecordsByBirthYear(Person people[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (people[j].birthYear > people[j + 1].birthYear) {
                Person temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    char filename[50];
    char buffer[256];

    printf("Enter the file name to be read:\n");
    scanf("%s", filename);
    
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    printf("\nReading csv file...\n");
    fgets(buffer, sizeof(buffer), fp);

    Person people[500];
    int recordCount = 0;

    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        line[strcspn(line, "\r\n")] = 0;
        char *year = strtok(line, ",");
        char *first_name = strtok(NULL, ",");
        char *last_name = strtok(NULL, ",");
        char *gender = strtok(NULL, ",");
        
        if (first_name != NULL && last_name != NULL && gender != NULL && year != NULL) {
            int birthYear = atoi(year);
            strcpy(people[recordCount].firstName, first_name);
            strcpy(people[recordCount].lastName, last_name);
            strcpy(people[recordCount].gender, gender);
            people[recordCount].birthYear = birthYear;
            recordCount++;
            
        }
    }
    fclose(fp);


    sortRecordsByBirthYear(people, recordCount);

    printf("\nSorted Records (by Birth Year):\n");

    for (int i = 0; i < recordCount; i++) {
        printf("Birth Year: %d, Name: %s %s, Gender: %s\n", people[i].birthYear,
            people[i].firstName, people[i].lastName, people[i].gender);
    }
    return 0;
}