# include <stdio.h>
# include <string.h>
#include <stdlib.h>
#include <stdbool.h>

char asciiToChar(int asciiValue) {
    return (char)asciiValue;
}

int charToAscii(char c) {
    return (unsigned char)c;
}

int main() {

    int choice;
    int ASCII;
    char character;
   
    while (1) {

        printf("Menu:\n");
        printf("1. Convert ASCII value to character\n");
        printf("2. Convert character to ASCII value\n");
        printf("0. Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter an ASCII value:\n");
            scanf("%d", &ASCII);
            character = asciiToChar(ASCII);
            printf("The character for ASCII value %d is '%c'.\n", ASCII, character);
            printf("\n");
            continue;
        
        case 2:
            printf("Enter a character:\n");
            scanf(" %c", &character);
            ASCII = charToAscii(character);
            printf("The ASCII value for character '%c' is %d.\n", character, ASCII);
            printf("\n");
            continue;
        
        case 0:
            printf("Exiting the program. Goodbye!\n");
            return 0;
        
        default:
            printf("Invalid choice.\n");
            break;
        }

    }

    return 0;
}