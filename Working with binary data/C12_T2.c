#include <stdio.h>

void printBinary(unsigned int num){  
    if (num > 1) {
        printBinary(num >> 1);
    }
    // Print the least significant bit
    putchar((num & 1) ? '1' : '0');
}



int main() {
    unsigned int num;
    printf("Enter a non-negative integer: ");
    scanf("%u", &num);
    printf("Binary representation: ");
    printBinary(num);
    printf("\n");
    return 0;
}