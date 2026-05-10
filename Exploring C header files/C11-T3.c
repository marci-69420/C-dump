#include <stdio.h>
#include <stdlib.h>

int main() {
    int mySeed;
    printf("Give me your seed:\n");
    scanf("%d", &mySeed);
    srand(mySeed);
    for (int i = 0; i < 5; i++) {
        printf("%d ", (rand() % 100) + 1);
    }
    printf("\n");
    return 0;
}