#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    char delim[] = "a" "e" "i" "o" "u" "A" "E" "I" "O" "U";
    char *token;


    printf("Please enter a string:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    printf("Splitting the string by vowels:\n");
    token = strtok(str, delim);
     while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, delim);
    }

    return 0;
}