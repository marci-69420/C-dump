#include <stdio.h>
int main() {
    int input = -1;
    int max = 0;
    int inputs = 0;
    int count = 0;
    printf("Enter positive integers (0 to stop):\n");
    while (input != 0) {
        scanf("%d", &input);
        if (input == 0) {
            break;
        }
        count++;
        inputs = inputs + input;
        if (input > max) {
            max  = input;
        }

    }
    printf("Count: %d\n", (count));
    printf("Maximum: %d\n", max);
    float avg = (float)inputs / (count);
    printf("Average: %.2f\n", avg);


    return 0;
}