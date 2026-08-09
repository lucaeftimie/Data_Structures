#include <iostream>


// alocare celula
// cautare element lista
// inserare in lista
//   1. la inceput
//   2. la sf. listei
//   3. in interior: dupa/inaintea unui element
// eliminare element din lista
// modificarea element
// citire lista
// distrugere lista
// afisare lista
// sortare lista
// inversare lista
// concatenare lista
typedef struct node {
    int data;
    struct  node *next;
}node;


// Create a new node
int create_node(node** list, int data) {
    node *new_node = (node*)malloc(sizeof(node));
    if (!new_node)
        return -1;

    new_node->data = data;
    new_node->next = NULL;
    *list = new_node;
    return 1;
}

//Create a node and add it after the node which contains the data from "ref"
int add_node_after_ref(node** list, int data, int ref) {

    // If list is empty, create_node should be used
    if (list == NULL) {
        return -1;
    }

    node* p;

    for (p = *list; p != NULL; p = p->next)
        if (p->data == ref)
            break;

    // When there is no node with "ref"
    if (p == NULL)
        return -1;

    // Create the node
    node* new_node;
    create_node(&new_node, data);

    // Add the node to the list, after "ref"
    new_node->next = p->next;
    p->next = new_node;

    //Return value for succes
    return 1;
}

int add_node_before_ref(node** list, int data, int ref) {

    // If list is empty, create_node should be used
    if (list == NULL) {
        return -1;
    }

    node* p, *p_prev;

    for (p = *list; p != NULL; p = p->next) {

       if (p->data == ref)
            break;

        p_prev = p;
    }
    // When there is no node with "ref"
    if (p == NULL)
        return -1;

    // Create the node
    node* new_node;
    create_node(&new_node, data);

    // Add the node to the list, before "ref"
    p_prev->next = new_node;
    new_node->next = p;

    //Return value for succes
    return 1;
}


//Create node and insert it at the front of the list
int add_node_at_the_front(node** list, int data) {
    // If the list is empty, create_node should be used
    if (list == NULL)
        return -1;

    // Create new node
    node* new_node;
    create_node(&new_node, data);

    // If memory allocation failed
    if (!new_node)
        return -1;

    // Add the node to the front of the list
    new_node->next = *list;
    *list = new_node;

    //Return value for succes
    return 1;
}

int add_node_at_the_end(node** list, int data) {
    if (list == NULL)
        return -1;

    node *new_node;
    create_node(&new_node, data);

    if (!new_node)
        return -1;

    node *p;

    for (p = *list; p->next != NULL; p = p->next);

    p->next = new_node;
    return 1;
}

// Returns the first node which is equal to "data"
int find_node(node** list, int data) {
    int index = 0;
    int check = -1;
    for (node* p = *list; p != NULL; p = p->next) {
        if (p->data == data) {
            check = 1;
            break;
        }
        else {
            index++;
        }
    }

    if (check == -1)
        return -1;
    else
        return index;
}


void print_list(node** list) {
    node* p;

    for (p = *list; p != NULL; p = p->next)
        printf("%d, ", p->data);

    printf("\n");
}
int main() {

    node* list = NULL;
    create_node(&list, 22);
    print_list(&list);
    add_node_at_the_front(&list, 20);
    print_list(&list);
    add_node_before_ref(&list, 105, 22 );
    print_list(&list);
    add_node_after_ref(&list, 43, 22);
    print_list(&list);

    add_node_at_the_front(&list, 10);
    print_list(&list);

    add_node_at_the_end(&list, 320);
    print_list(&list);

    return 0;
}
