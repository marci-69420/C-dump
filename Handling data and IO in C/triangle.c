#include <stdio.h>

int main() {
    int height;
    printf("Enter the triangle height: ");
    while (scanf("%d", &height) != 1 || height > 20 || height <= 0) {
        printf("Invalid input. Please enter a positive integer (1-20) for the height: ");
        while (getchar() != '\n'); // Clear invalid input
    }
    for (int i = 1; i <= height; i++) {
        for (int j = 0; j < height - i; j++) {
            printf(" ");
        }
        for (int k = 0; k < (i - 1); k++) {
            printf("*");
        }
        printf("*\n");
    }
    return 0;
}