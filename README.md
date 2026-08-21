# Data structures

Small C implementations of classic data structures, built with dynamically allocated linked nodes.

## Contents

| File | Description |
|---|---|
| `linkedlist.c` | A singly linked list supporting insertion (front, end, before/after a reference value, sorted), search, removal, sorting, reversal, and concatenating two lists. |
| `queue.c` | A FIFO queue (`enqueue`/`dequeue`) built on a linked list with `front`/`rear` pointers and O(1) operations. |
| `stack.c` | A LIFO stack (`push`/`pop`) built on a linked list. |

Each file is self-contained and includes its own `main()` with example usage.

## linkedlist.c

Key operations:
- `create_node`, `add_node_at_the_front`, `add_node_at_the_end`
- `add_node_before_ref` / `add_node_after_ref` — insert relative to a value already in the list
- `add_node_sorted`, `create_sorted_list`, `sort_list` — keep or make the list sorted
- `find_node`, `get_length`, `print_list`
- `remove_node`, `modify_node`
- `reverse_list`
- `concatenate_lists` — join two lists at a given position
- `free_list` — releases all nodes and prints a message per deallocation

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
