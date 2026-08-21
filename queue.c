#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct queue {
    node *front;
    node *rear;
    int size;
}queue;

queue* create_queue() {
    queue *q = (queue*)malloc(sizeof(queue));
    if (!q)
        return NULL;

    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}

int isEmpty(queue *q) {
    return q->size == 0;
}

void enqueue(queue *q, int value) {
    node *new_node = (node*)malloc(sizeof(node));

    if (!new_node)
        return;

    new_node->data = value;
    new_node->next = NULL;

    if (isEmpty(q)) {
        q->front = new_node;
        q->rear = new_node;
    } else {
        q->rear->next = new_node;
        q->rear = new_node;
    }

    q->size++;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }


    node *temp = q->front;
    int value = temp->data;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    q->size--;
    return value;
}

int peek(queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

void free_queue(queue *q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
    free(q);
}

int main() {
    queue *q = create_queue();

    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    printf("Front of the queue: %d\n", peek(q));

    while (!isEmpty(q)) {
        printf("Dequeued: %d\n", dequeue(q));
    }

    free_queue(q);
    return 0;

}