#include <iostream>

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
    new_node->next = NULL;
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

int get_length(node* list) {
    if (list == NULL) {
        return -1;
    }

    node *p;

    int length = 0;
    for (p = list; p != NULL; p = p->next)
        length++;

    return length;
}

void print_list(node** list) {
    node* p;

    for (p = *list; p != NULL; p = p->next)
        if (p->next == NULL)
            printf("%d ", p->data);
        else
            printf("%d, ", p->data);

    printf("\n");
}


int remove_node(node** list, int index) {

    // If list is empty, there is nothing to remove
    if (*list == NULL)
        return -1;

    // Get the length of the list
    int len = get_length(*list);

    // If length is larger than provided index => error
    if (index > len)
        return -2;

    node *p = *list;
    node *p_prev;

    for (int i = 0; i < index; i++) {
        p_prev = p;
        p = p->next;
    }

    if (index == 0) {
        *list = (*list)->next;
    }

    if (index > 0 && index < len) {
        p_prev->next = p->next;
        free(p);

    }

    if (index == len) {
        p_prev->next = NULL;
        free(p);
    }

    return 1;
}

int modify_node(node** list, int new_data, int index) {

    // If list is empty, there is nothing to remove
    if (*list == NULL)
        return -1;

    // Get the length of the list
    int len = get_length(*list);

    // If length is larger than provided index => error
    if (index > len)
        return -2;

    node *p = *list;

    for (int i = 0; i < index; i++)
        p = p->next;

    p->data = new_data;

    return 1;
}


int read_list(node **new_list, int no_nodes) {
    int data, check = 0;

    if (no_nodes < 1)
        return -1;

    if (*new_list != NULL)
        return -2;


    for (int i = 0; i < no_nodes; i++) {
        printf("Enter node %d:", i);
        scanf(" %d", &data);

        if (check == 0) {
            create_node(new_list, data);
            check = 1;
        } else {
            add_node_at_the_end(new_list, data);
        }
    }

    return 1;
}

int free_list(node **list) {
    node *p = *list, *aux_p;
    int i = 0;
    while (p != NULL){
        aux_p = p->next;
        free(p);
        printf("Deallocated memory for the node %d\n", i++);
        p = aux_p;
    }

    *list = NULL;

    return 1;
}

int create_sorted_list(node** new_list, int no_nodes) {
    int data, check = 0;

    if (no_nodes < 1)
        return -1;

    if (*new_list != NULL)
        return -2;

    for (int i = 0; i < no_nodes; i++) {
        printf("Enter node %d:", i);
        scanf(" %d", &data);

        if (check == 0) {
            create_node(new_list, data);
            check = 1;
        }else {
            node *p = *new_list;


            if (p->data >= data) {
                add_node_at_the_front(new_list, data);
                print_list(new_list);
            }else {
                node *p_prev;
                while (p != NULL && p->data <= data) {
                    p_prev = p;
                    p = p->next;
                }

                node *n;
                create_node(&n, data);
                p_prev->next = n;
                n->next = p;
                print_list(new_list);
            }

        }
    }
    return 1;
}

int add_node_sorted(node **list, int data) {

    // If list is empty, create_node should be used
    if (*list == NULL) {
        return -1;
    }

    node *p = *list;
    if (p->data >= data) {
        add_node_at_the_front(list, data);
    }else {
        node *p_prev;
        while (p != NULL && p->data <= data) {
            p_prev = p;
            p = p->next;
        }

        node *n;
        create_node(&n, data);
        p_prev->next = n;
        n->next = p;
    }

    return 1;
}

int sort_list(node **list) {

    if (*list == NULL) {
        return -1;
    }

    if (get_length(*list) == 1)
        return -2;

    node *p = *list, *p_prev;

    while (p != NULL && p->next != NULL) {

        if (p->data > p->next->data ) {
            if (p == *list) { // daca nodul de modificat este la inceputul listei
                node *aux = p->next;
                p->next = p->next->next;
                aux->next = p;
                *list = aux;
            }else if (p->next->next == NULL) { // daca nodul de modificat este penultimul in lista

                node *aux = p;
                p_prev->next = p->next;
                p->next->next = p;
                p->next = NULL;
            }else { // daca nodul de modificat se afla in interiorul listei
                p_prev->next = p->next;
                p->next = p->next->next;
                p_prev->next->next = p;
            }

            p = *list;
        }else {
            p_prev = p;
            p = p->next;
        }
    }

    return 1;
}

int reverse_list(node **list) {
    if (*list == NULL)
        return -1;

    // if (get_length(list)) {
    //
    // }
    node *p_prev, *p, *p_next;
    p_prev = *list;
    p = (*list)->next;
    p_next = p->next;

    p_prev->next = NULL;
    p->next = p_prev;

    p_prev = p;
    p = p_next;
    p_next = p_next->next;

    while (p != NULL) {

        p->next = p_prev;
        p_prev = p;
        p = p_next;

        if (p_next)
            p_next = p_next->next;

    }
    *list = p_prev;
    return 1;

}


node* concatenate_lists(node **l1, node **l2, int l1_pos) {

    node *head;

    if (l1_pos <= 0 && l1_pos > get_length(l1)) {
        return NULL;
    }


    // at the start of the list
    if (l1_pos == -1) {

        head = *l2;

        while ((*l2)->next != NULL)
            *l2 = (*l2)->next;

        (*l2)->next = *l1;


    }

    if (l1_pos >= 0 && l1_pos < get_length(l1) - 1) {

        head = *l1;

        while (l1_pos > 0) {
            (*l1) = (*l1)->next;
            l1_pos--;
        }

        node *l1_next = (*l1)->next;
        (*l1)->next = *l2;

        while ((*l2)->next != NULL)
            *l2 = (*l2)->next;

        (*l2)->next = l1_next;
    }
    //inside the l2 list
    //at the end of the l2 list
    if (l1_pos == get_length(l1)) {

        head = *l1;

        while ((*l1)->next != NULL)
            *l1 = (*l1)->next;

        (*l1)->next = *l2;
    }

    return head;
}
int main() {
    // 10, 20, 105, 22, 43, 320
    // node* list = NULL;
    // create_node(&list, 22);
    // print_list(&list);
    // add_node_at_the_front(&list, 20);
    // print_list(&list);
    // add_node_before_ref(&list, 105, 22 );
    // print_list(&list);
    // add_node_after_ref(&list, 43, 22);
    // print_list(&list);
    // add_node_at_the_front(&list, 10);
    // print_list(&list);
    // add_node_at_the_end(&list, 320);
    // print_list(&list);
    // remove_node(&list, 2);
    // remove_node(&list, 0);
    // remove_node(&list, 3);
    // print_list(&list);

    // node *list = NULL;
    // //read_list(&list, 6);
    // create_sorted_list(&list, 6);
    // add_node_sorted(&list, 1);
    // add_node_sorted(&list, 0);
    // add_node_sorted(&list, 2);
    // add_node_sorted(&list, 9);
    // add_node_sorted(&list, 7);
    // add_node_sorted(&list, 8);

    node *list = NULL;
    read_list(&list, 9);
    sort_list(&list);

    print_list(&list);
    free_list(&list);

    node* list1 = NULL;
    create_node(&list1, 22);
    add_node_at_the_front(&list1, 20);
    add_node_before_ref(&list1, 105, 22 );
    add_node_after_ref(&list1, 43, 22);
    add_node_at_the_front(&list1, 10);
    add_node_at_the_end(&list1, 320);

    //reverse_list(&list1);
    print_list(&list1);


    node *list2 = NULL;
    create_node(&list2, 1);
    add_node_at_the_end(&list2, 2);
    add_node_at_the_end(&list2, 3);
    add_node_at_the_end(&list2, 4);
    add_node_at_the_end(&list2, 5);
    add_node_at_the_end(&list2, 6);
    print_list(&list2);

    //node * list3 = concatenate_lists(&list1, &list2, -1);
    //node *list3 = concatenate_lists(&list1, &list2, 3);
    node *list3 = concatenate_lists(&list1, &list2, 6);

    print_list(&list3);

    return 0;
}
