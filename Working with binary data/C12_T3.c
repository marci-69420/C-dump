#include <stdio.h>

int isBitPalindrome(unsigned int num) {
    unsigned int original = num;
    unsigned int reversed = 0;
    while (num > 0) {
        reversed = (reversed << 1) | (num & 1);
        num >>= 1;
    }

    if (original == reversed) {
        return 1;
    } else {
        return 0;
    }

}

int main() {
    unsigned int number;
    printf("Enter a non-negative integer: ");
    if (scanf("%u", &number) == 1) {
        if (isBitPalindrome(number)) {
            printf("Palindrome\n");
        } else {
            printf("Not palindrome\n");
        }
    }

    return 0;
}