#include <stdio.h>

int main() {
    printf("Enter 2 integers: ");
    int a, b;
    scanf("%d %d", &a, &b);
    int sum = a + b;
    printf("Sum: %d\n", sum);
    return 0;
}