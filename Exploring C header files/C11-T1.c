#include <stdio.h>
#include <time.h>

int main() {
    long a, b;
    printf("Please input two integers:\n");
    scanf("%ld %ld", &a, &b);
    time_t start_time = (time_t)a;
    time_t end_time = (time_t)b;
    printf("Start: %s", ctime(&start_time));
    printf("Duration: %.2f seconds\n", difftime(end_time, start_time));
    return 0;
}