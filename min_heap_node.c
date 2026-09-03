#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int character;
    double frequency;
    struct node *left;
    struct node *right;
}node;

typedef struct min_heap
{
    node **array;
    int size;
    int capacity;
}min_heap;


int get_parent(int i)
{
    return (i - 1) /2;
}

int get_left_child(int i)
{
    return (2 * i) + 1;
}

int get_right_child(int i)
{
    return (2 * i) + 2;
}

void swap(node **a, node **b)
{
    node *temp = *a;
    *a = *b;
    *b = temp;
}

min_heap* create_heap(int capacity)
{
    min_heap *new_heap = (min_heap*)malloc(sizeof(min_heap));
    new_heap->array = (node**)malloc(sizeof(node*)*capacity);
    for (int i = 0; i < capacity; i++)
    {
        new_heap->array[i] = (node*)malloc(sizeof(node));
        new_heap->array[i]->left = NULL;
        new_heap->array[i]->right = NULL;
        new_heap->array[i]->character = -1;
        new_heap->array[i]->frequency = 0;

    }

    new_heap->size = 0;
    new_heap->capacity = capacity;

    return new_heap;
}

void push(min_heap* heap, node n) // heapify up method
{
    if (heap->size == heap->capacity)
    {
        printf("Min heap is full.");
        return;
    }

    int index = heap->size;
    heap->array[index]->character = n.character;
    heap->array[index]->frequency = n.frequency;
    heap->array[index]->left = n.left;
    heap->array[index]->right = n.right;

    heap->size++;

    while (index != 0 && heap->array[get_parent(index)]->frequency > heap->array[index]->frequency)
    {
        swap(&heap->array[index], &heap->array[get_parent(index)]);
        index = get_parent(index);
    }
}

node* pop(min_heap* heap) // heapify down method
{
    if (heap->size == 0)
        return NULL;

    node* root = heap->array[0];
    swap(&heap->array[0], &heap->array[heap->size - 1]);
    heap->size--;

    int index = 0;

    while (get_left_child(index) < heap->size)
    {
        int smallest;
        int l = get_left_child(index);
        int r = get_right_child(index);

        if (r < heap->size && heap->array[r]->frequency < heap->array[l]->frequency)
            smallest = r;
        else
            smallest = l;

        if (heap->array[index]->frequency <= heap->array[smallest]->frequency)
            break;

        swap(&heap->array[index], &heap->array[smallest]);
        index = smallest;
    }

    return root;
}

void heapify(node **arr, int i, int n)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l]->frequency < arr[smallest]->frequency)
        smallest = l;

    if (r < n && arr[r]->frequency < arr[smallest]->frequency)
        smallest = r;

    if (smallest != i)
        swap(&arr[i], &arr[smallest]);

    heapify(arr, smallest, n);
}


void free_heap(min_heap* heap)
{
    if (heap == NULL) return;
    if (heap->array != NULL)
        free(heap->array);

    free(heap);
}

// int main()
// {
//     min_heap *heap1 = create_heap(4);
//     node *node1 = (node*)malloc(sizeof(node));
//     node1->frequency = 3;
//     node *node2 = (node*)malloc(sizeof(node));
//     node2->frequency = 5;
//     push(heap1, *node1);
//     push(heap1, *node2);
//     free(node1);
//     free(node2);
//     for (int i = 0; i < 2; i++)
//     {
//         printf("The minimum value of the array is: %f\n", pop(heap1).frequency);
//     }
//
//     free_heap(heap1);
//
//     return 0;
// }