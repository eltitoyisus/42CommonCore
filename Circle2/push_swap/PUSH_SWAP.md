# push_swap

## Description

push_swap is an algorithm project that challenges you to sort a stack of integers using a limited set of operations and the smallest number of moves possible. This project introduces you to algorithm complexity and optimization.

## Project Overview

You are given two stacks: **stack a** (containing random integers) and **stack b** (empty). The goal is to sort stack a in ascending order using the smallest number of operations.

This project teaches you:
- Algorithm design and optimization
- Data structure manipulation (stacks)
- Complexity analysis (time and space)
- Problem-solving and optimization strategies
- Understanding of sorting algorithms

## Available Operations

### Swap Operations
- `sa` - Swap the first 2 elements at the top of stack a
- `sb` - Swap the first 2 elements at the top of stack b
- `ss` - `sa` and `sb` at the same time

### Push Operations
- `pa` - Push the top element from stack b to stack a
- `pb` - Push the top element from stack a to stack b

### Rotate Operations
- `ra` - Rotate stack a up (first element becomes last)
- `rb` - Rotate stack b up
- `rr` - `ra` and `rb` at the same time

### Reverse Rotate Operations
- `rra` - Rotate stack a down (last element becomes first)
- `rrb` - Rotate stack b down
- `rrr` - `rra` and `rrb` at the same time

## Implementation Files

- `push_swap.c` - Main program
- `push_swap.h` - Header file
- `ft_lstnew.c`, `ft_lstlast.c`, `ft_lstsize.c`, `ft_lstaddback.c`, `ft_lstclear.c` - Linked list utilities
- `is_push.c`, `is_swap.c`, `is_rotate.c`, `is_reverse.c` - Operation implementations
- `moves.c`, `moves2.c`, `operands.c` - Sorting algorithm logic
- `atoi.c`, `ft_atoll.c` - Number conversion
- `error.c`, `error2.c` - Error handling
- `is_digit.c` - Input validation
- `ft_split.c`, `ft_strlcpy.c`, `split.c` - String utilities
- `Makefile` - Compilation rules

## Usage

```bash
./push_swap [list of integers]
```

**Examples:**
```bash
./push_swap 2 1 3 6 5 8
./push_swap "5 8 2 1 4"
```

The program outputs the list of operations needed to sort the stack.

## Constraints

- No duplicates allowed
- Only integers accepted
- Must handle integer overflow
- Must handle various input formats (multiple arguments or quoted string)

## Performance Requirements

Your algorithm should be efficient:
- **3 numbers**: Maximum 3 operations
- **5 numbers**: Maximum 12 operations
- **100 numbers**: 
  - 5 points for < 700 operations
  - 4 points for < 900 operations
  - 3 points for < 1100 operations
  - 2 points for < 1300 operations
  - 1 point for < 1500 operations
- **500 numbers**:
  - 5 points for < 5500 operations
  - 4 points for < 7000 operations
  - 3 points for < 8500 operations
  - 2 points for < 10000 operations
  - 1 point for < 11500 operations

## Common Algorithms

Popular approaches include:
- **Quick Sort** adaptation for stacks
- **Radix Sort** for larger sets
- **Insertion Sort** for small sets
- **Turk Algorithm** - optimized approach
- **Chunk/Range** sorting methods

## Error Handling

The program must handle:
- Non-numeric arguments
- Numbers outside integer range
- Duplicate numbers
- Empty input

Display "Error\n" to stderr for invalid input.

## Bonus - Checker

The checker program verifies if a list of operations correctly sorts the stack:

```bash
./checker [list of integers]
[operations from stdin]
```

Returns "OK" if sorted, "KO" if not, "Error" if invalid input.

## Skills Acquired

- Algorithm design and optimization
- Complexity analysis (Big O notation)
- Stack data structure manipulation
- Problem decomposition
- Performance optimization
- Sorting algorithm understanding
- Edge case handling

## Circle

**Circle 2** - Algorithm and optimization project at 42 School
