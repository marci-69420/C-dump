#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

typedef struct {
    Node *front;
    Node *rear;
} Queue;

Queue *createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int QueueEmpty(Queue *q)
{
    return (q->front == NULL);
}

void Enqueue(Queue* q, int key) {
    Node* pNew;
    pNew = (Node*)malloc(sizeof(Node));
    pNew->data = key;
    pNew-> next = NULL;

    if (q->rear == NULL) {
        // If the queue is empty, set both front and rear to the new node
        q->front =  pNew;
        q->rear = pNew;
    }else {
        // Otherwise, add the new node after the current rear and update rear
        q->rear->next = pNew;
        q->rear = pNew;}
}

int Dequeue(Queue *q)
{
    Node * first;
    int key = q->front->data;
    first = q->front;
    q->front = q->front->next;
    if (q->front == NULL){ 
        q->rear = NULL;}
    free(first);
    return(key);
}

void print_Queue(Node *start) {  
    Node *temp = start;
    printf("Queue: ");  
    while (temp != NULL) {  
        printf("%d ", temp->data);  
        temp = temp->next;  
    }
}

int main(){
    // create a new queue
    Queue * Q = createQueue();
    int option;
    int value;
    do {
        printf("Menu:\n1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Quit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch (option){
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                
                Enqueue(Q, value);
                printf("Enqueued: %d\n", value);
                break;
            
            case 2:
                if (QueueEmpty(Q)) {
                    printf("Queue is empty. Cannot dequeue.\n");
                } else {
                    int value = Dequeue(Q);
                    printf("Dequeued: %d\n", value);
                }
                break;
            
            case 3:
                if (QueueEmpty(Q)) {
                    printf("Queue is empty. Nothing to print.\n");
                } else {
                    print_Queue(Q->front);
                    printf("\n");
                }
                break;
            
            case 4:
                printf("Exiting program.\n");
                break;            
            default:
                printf("Invalid option. Please choose again.");
        }
        
    } while (option != 4);

    for (Node *current = Q->front; current != NULL; ) {
        Node *nodeToFree = current;
        current = current->next;
        free(nodeToFree);
    }
    free(Q);
}
