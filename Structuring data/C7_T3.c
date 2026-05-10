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

void reverse(List *L) {
    Node *prev = NULL;
    Node *Next = NULL;
    Node *current = L->first;
    Node *temp = L->first;

    while (current != NULL) {
        Next = current->next;
        current->next = prev;
        prev = current;
        current = Next;

    }

    L->last = temp;
    L->first = prev;

}


int main() {
    List *L =create();
    L->first = NULL;
    L->last = NULL;
    int n;
    int value;

    printf("Enter the number of integers: ");
    scanf("%d", &n);
    printf("Enter %d integers: ", n);
    int numbers[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }
    for (int i = 0; i <n; i++) {
        add(L, numbers[i]);
    }
    printf("\n");
    Node *current = L->first;
    printf("Original list: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }

    reverse(L);
    current = L->first;
    printf("\nReversed list: ");
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
    for (Node *current = L->first; current != NULL; ) {
        Node *nodeToFree = current;
        current = current->next;
        free(nodeToFree);
    }
    free(L);

    return 0;
}