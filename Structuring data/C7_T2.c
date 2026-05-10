#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *first; // Pointer to the start of the list
    Node *last;  // Pointer to the end of the list
} List;

List * create(){
    List *L;
    L = (List*)malloc(sizeof(List));
    return L;
}

void add(List *L, int value) {
    Node* pNew;
    pNew = (Node*)malloc(sizeof(Node));
    pNew->data = value;
    pNew->next = NULL;
    if (L->last == NULL) {
        L->first = pNew;
    } else {
        L->last->next = pNew;
    }
    L->last = pNew;
}

int find_max(List *L) {
    int max = L->first->data;
    int pos = 0;
    Node *currentNode = L->first;
    while (currentNode != NULL) {
        pos++;
        if (currentNode->data > max) {
            max = currentNode->data;
        }
        currentNode = currentNode->next;
    }
    return max;
}


int main() {
    List *L =create();
    L->first = NULL;
    L->last = NULL;
    int n;
    int value;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i=0; i <n; i++) {
        scanf("%d", &value);
        add(L, value);
    }

    printf("\nThe maximum value is: %d\n", find_max(L));    

    for (Node *current = L->first; current != NULL; ) {
        Node *nodeToFree = current;
        current = current->next;
        free(nodeToFree);
    }
    free(L);

    return 0;
}

