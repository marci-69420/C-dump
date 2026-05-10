#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void toUpperCase(char *str) {
    while (*str) {
        *str = toupper((unsigned char)*str);
        str++;
    }
}

void toLowerCase(char *str) {
    while (*str) {
        *str = tolower((unsigned char)*str);
        str++;
    }
}

void (*stringFunctions[])(char*) = {toUpperCase, toLowerCase};

int main() {
    char str[100];
    int choice;

    printf("Enter a string:\n");
    fgets(str, sizeof(str), stdin);

    printf("Choose operation:\n1. Uppercase\n2. Lowercase\nEnter your choice:\n");
    scanf("%d", &choice);

    if (choice == 1) {
        stringFunctions[choice - 1](str);
        printf("Processed String: %s\n", str);
    } else if (choice == 2) {
        stringFunctions[choice - 1](str);
        printf("Processed String: %s\n", str);
    } else {
        printf("Invalid choice!\n");
    }

    return 0;
}