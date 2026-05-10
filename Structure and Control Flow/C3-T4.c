#include <stdio.h>
#include <string.h>
int main() {
    char str[200];
    int vowelCount = 0;
    int characterCount = 0;

    printf("Enter a sentence:\n");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        characterCount++;

        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
            ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            vowelCount++;
        }
    }
    

    

    printf("Number of vowels: %d\n", vowelCount);
    printf("Number of characters: %d\n", characterCount);

    return 0;
}