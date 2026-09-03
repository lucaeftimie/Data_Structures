# Data structures

 C implementations of data structures, built with dynamically allocated memory.

## Contents

| File                                 | Time Complexity                                   | Space Complexity | Description                                                                                                 | 
|--------------------------------------|---------------------------------------------------|------------------|-------------------------------------------------------------------------------------------------------------|
| [`linked_list.c`](linkedlist.c)      | O(1) - insert<br/>O(1) - delete<br/>O(n) - search | O(n)             | A singly linked list supporting insertion, search, removal, sorting, reversal, and concatenating two lists. |
| [`queue.c`](queue.c)                 | O(1) - enqueue<br/>O(1) - dequeue                 | O(n)             | A FIFO queue (`enqueue`/`dequeue`) built on a linked list with `front`/`rear` pointers                      |
| [`stack.c`](stack.c)                 | O(1) - push<br/>O(1) - pop                        | O(n)             | A LIFO stack (`push`/`pop`) built on a linked list.                                                         |
| [`min_heap_int.c`](min_heap_int.c)   | O(log n) - push<br/>O(log n) - pop                | O(n)             | A priority queue (Min-Heap) flat array implementation (int datatype)                                        |
| [`min_heap_node.c`](min_heap_node.c) | O(log n) - push<br/>O(log n) - pop                | O(n)             | A priority queue (Min-Heap) flat array implementation (node datatype)                                       |


## linkedlist.c

- `create_node`, `free_list`
- `add_node_at_the_front`, `add_node_at_the_end`
- `add_node_before_ref` / `add_node_after_ref` — insert relative to a value already in the list
- `add_node_sorted`, `create_sorted_list`, `sort_list` — keep or make the list sorted
- `find_node`, `get_length`, `print_list`
- `remove_node`, `modify_node`
- `reverse_list`
- `concatenate_lists` — join two lists at a given position

## queue.c

- `create_queue` / `free_queue`
- `enqueue` — adds to the rear
- `dequeue` — removes from the front
- `peek`, `isEmpty`

## stack.c

- `create_node` / `free_stack`
- `push` — adds to the top
- `pop` — removes from the top
- `isEmpty`

## min_heap_int.c / min_heap_node.c

- `create_heap` / `free_heap`
- `push` — inserts 
- `pop` — removes the smallest number from the heap
- `heapify` - moves a node downwards in tree until the min heap condition is satisfied

## Build & run

Each file can be compiled and run independently:

```bash
gcc -o linkedlist linkedlist.c && ./linkedlist
gcc -o queue queue.c && ./queue
gcc -o stack stack.c && ./stack
```

## Notes

- All structures use dynamic memory allocation (`malloc`/`free`) rather than fixed-size arrays.
- `queue.c` and `stack.c` include basic checks for allocation failure and empty-structure errors.
