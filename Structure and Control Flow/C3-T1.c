# include <stdio.h>
int main() {
    float used_kwh;
    printf("How much electricity did you use this month?\n");
    scanf("%f", &used_kwh);
    float cost = 0.0;
    // Tier 1: 0-500 kWh = 0.18 EUR/kWh
    if (used_kwh <= 500) {
        cost = used_kwh * 0.18;
    } else if (used_kwh <= 1000) {
        // Tier 2: 501-1000 kWh = 0.21 EUR/kWh
        cost = (500 * 0.18) + ((used_kwh - 500) * 0.21);
    } else {
        // Tier 3: >1000 kWh = 0.25 EUR/kWh
        cost = (500 * 0.18) + (500 * 0.21) + ((used_kwh - 1000) * 0.25);
    }

    printf("Total electricity bill this month is: %.2f EUR\n", cost);

    return 0;
}