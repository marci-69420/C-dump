#include <stdio.h>

int main() {
    double a;
    double b;
    double sum;
    printf("Width: ");
    scanf("%le", &a);
    printf("Height: ");
    scanf("%le", &b);
    sum = a * b;
    printf("Area: %le\n", sum);
    return 0;
}