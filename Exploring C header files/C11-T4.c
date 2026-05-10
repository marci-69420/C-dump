#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int score;
} Athlete;

int compare_athletes(const void *a, const void *b) {
    const Athlete *athleteA = (const Athlete *)a;
    const Athlete *athleteB = (const Athlete *)b;

    if (athleteA->score != athleteB->score) {
        return athleteB->score - athleteA->score;
    } else {
        return strcmp(athleteA->name, athleteB->name); 
    }
}

int main () {
    Athlete athletes[5];

    for (int i = 0; i < 5; i++) {
        printf("Please input %d athlete info:\n", i + 1);
        scanf("%s %d", athletes[i].name, &athletes[i].score);
    }

    qsort(athletes, 5, sizeof(Athlete), compare_athletes);
    
    printf("\nRanking:\n");
    for (int i = 0; i < 5; i++) {
        printf("%s %d\n", athletes[i].name, athletes[i].score);
    }

    return 0;
}