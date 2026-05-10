# include <stdio.h>
# include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char inputStr[100];

    printf("Enter a string:\n");
    fgets(inputStr, sizeof(inputStr), stdin);
    inputStr[strcspn(inputStr, "\n")] = '\0';

    reverseString(inputStr);
    printf("Reversed string: %s\n", inputStr);

    return 0;
}