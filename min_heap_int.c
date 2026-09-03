#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int *array;
    int size;
    int capacity;
}min_heap;


min_heap* create_heap(int capacity)
{
    min_heap *new_heap = (min_heap*)malloc(sizeof(min_heap));
    new_heap->array = (int*)malloc(sizeof(int)*capacity);
    new_heap->size = 0;
    new_heap->capacity = capacity;

    return new_heap;
}

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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void push(min_heap* heap, int value)
{
    if (heap->size > heap->capacity)
    {
        printf("Min heap is full.");
        return;
    }

    int index= heap->size;
    heap->array[index] = value;
    heap->size++;

    while (index != 0 && heap->array[index] < heap->array[get_parent(index)])
    {
        swap(&heap->array[index], &heap->array[get_parent(index)]);
        index = get_parent(index);
    }
}

int pop(min_heap* heap)
{
    if (heap->size == 0)
        return -1;

    int min_value = heap->array[0];

    heap->array[0] = heap->array[heap->size - 1];

    int index = 0;


    while (get_left_child(index) < heap->size) {
        int smallest;
        int l = get_left_child(index);
        int r = get_right_child(index);


        if (r < heap->size && l < heap->size && heap->array[r] < heap->array[l])
            smallest = r;
        else
            smallest = l;

        if (heap->array[index] <= heap->array[smallest])
            break;


        swap(&heap->array[index], &heap->array[smallest]);
        index = smallest;
    }


    return min_value;
}

void heapify(int *arr, int i, int n)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] < arr[smallest])
        smallest = l;

    if (r < n && arr[r] < arr[smallest])
        smallest = r;

    if (smallest != i)
        swap(&arr[i], &arr[smallest]);

    heapify(arr, smallest, n);
}

void free_heap(min_heap* heap)
{
    if (heap == NULL) return;
    if (heap->array != NULL) {
        free(heap->array);
    }
    free(heap);
}

// int main()
// {
//     min_heap *heap1 = create_heap(4);
//
//     push(heap1, 1);
//     push(heap1, 20);
//     push(heap1, 14);
//     push(heap1, 12);
//
//     for (int i = 0; i < 4; i++)
//     {
//         printf("The minimum value of the array is: %d\n", pop(heap1));
//     }
//
//     free_heap(heap1);
//
//     return 0;
// }