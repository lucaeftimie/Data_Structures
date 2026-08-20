#include<cstdlib>
#include<stdio.h>
#include <c++/v1/cstdlib>
/*
 push
 pop
 free_stack
*/

typedef struct node {
    int data;
    struct node *next;
}node;

int create_node(node **stack) {
    (*stack) = (node *)malloc(sizeof(node));

    if (!(*stack)) {
        return -1;
    }

    (*stack)->next = NULL;

    return 1;
}

int push(node **stack) {

    int data;

    printf("Enter value for stack element: ");
    scanf("%d", &data);
    node *new_node;

    if(create_node(&new_node)  == -1)
        return -1;

    new_node->data = data;


    if (*stack == NULL) {
        return -1;
    }

    new_node->next = *stack;
    (*stack) = new_node;

    return 1;

}

int pop(node **stack) {

    if (*stack == NULL)
        return -1;

    int d = (*stack)->data;

    if ((*stack)->next == NULL) {
        free(*stack);
        *stack = NULL;
    }else {
        node *p = (*stack)->next;
        free(*stack);
        *stack = p;
    }


    return d;
}

int free_stack(node **stack) {
    while (*stack != NULL)
        pop(stack);

    return 1;
}

int isEmpty(node **stack) {

    if (*stack == NULL)
        return 0;

    return 1;
}
