#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int capacity = 4;
    int *numbers = (int *)malloc(capacity * sizeof(int));

    if (numbers == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    int count = 0;
    int number = 0;
    printf("Enter a number (-1 to stop):\n");
    while (number != -1) {
        printf("Enter a number:\n");
        scanf("%d", &number);
        count++;
        if (number != -1) {
            numbers[count - 1] = number;
        }

        if (count == (capacity*0.75)) {
            capacity *= 2;
            int *temp = (int *)realloc(numbers, capacity * sizeof(int));
            if (temp == NULL) {
                printf("Memory reallocation failed\n");
                free(numbers);
                return 1;
            }
            numbers = temp;

            printf("The array size increases to %d.\n", capacity);
        }
    }
    
    printf("Final array (with %d elements): ", (count-1));
    for (int i = 0; i < count - 1; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    free(numbers);

    return 0;
}