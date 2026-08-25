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

    int current_index = heap->size;
    heap->array[current_index] = value;
    heap->size++;

    while (current_index != 0 && heap->array[get_parent(current_index)] > heap->array[current_index])
    {
        swap(&heap->array[current_index], &heap->array[get_parent(current_index)]);
        current_index = get_parent(current_index);
    }
}

int pop(min_heap* heap)
{
    if (heap->size == 0) return -1;

    int min_value = heap->array[0];

    heap->array[0] = heap->array[heap->size - 1];

    int current_index = 0;

    // Heapify Down: continue as long as there is at least a left child
    while (get_left_child(current_index) < heap->size) {
        int smallest_child_index = get_left_child(current_index);
        int right_child_index = get_right_child(current_index);

        // Check if a right child exists AND is smaller than the left child
        if (right_child_index < heap->size && heap->array[right_child_index] < heap->array[smallest_child_index]) {
            smallest_child_index = right_child_index;
        }

        // If the current node is smaller than its smallest child, the tree is valid
        if (heap->array[current_index] <= heap->array[smallest_child_index]) {
            break;
        }

        // Otherwise, swap and continue down the tree
        swap(&heap->array[current_index], &heap->array[smallest_child_index]);
        current_index = smallest_child_index;
    }


    return min_value;
}

void free_heap(min_heap* heap)
{
    if (heap == NULL) return;
    if (heap->array != NULL) {
        free(heap->array);
    }
    free(heap);
}

int main()
{
    min_heap *heap1 = create_heap(4);

    push(heap1, 1);
    push(heap1, 20);
    push(heap1, 14);
    push(heap1, 12);

    for (int i = 0; i < 4; i++)
    {
        printf("The minimum value of the array is: %d\n", pop(heap1));
    }

    free_heap(heap1);

    return 0;
}