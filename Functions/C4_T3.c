#include <stdio.h>

float celsiusToFahrenheit(float celsius) {

    float fahrenheit = (celsius * 9.0 / 5.0) + 32.0;
    return fahrenheit;
}

int main() {
    printf("Enter temperature in Celsius:\n");
    float celsius;
    scanf("%f", &celsius);
    float fahrenheit = celsiusToFahrenheit(celsius);
    printf("%.2f Celsius is equal to %.2f Fahrenheit\n", celsius, fahrenheit);
    return 0;
}