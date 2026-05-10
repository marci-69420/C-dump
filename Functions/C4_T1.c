#include <stdio.h>

void countUntil() {
    int num;
    printf("Please enter an integer greater than 0:\n");
    scanf("%d", &num);
    if (num <= 0) {
        printf("Stopping: the number must be greater than zero.\n");
        return;
    }

    int sum = 0;
    for (int i = 0; i <= num; i++) {
        sum += i;
    }
    printf("The sum of integers from 0 to %d is: %d\n", num, sum);

}

int main() {
    countUntil();
    return 0;
}