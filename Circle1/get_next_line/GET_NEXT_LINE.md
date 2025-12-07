# get_next_line

## Description

get_next_line is a project that challenges you to write a function that reads a line from a file descriptor. This function will be extremely useful for future projects, as reading line by line is a very common operation in programming.

## Project Overview

The goal is to create a function that returns a line read from a file descriptor, one line at a time, no matter how large the file or how long the lines are.

This project teaches you:
- Static variables in C
- File descriptor manipulation
- Buffer management
- Memory allocation strategies
- Edge case handling

## Prototype

```c
char *get_next_line(int fd);
```

## Parameters

- `fd` - File descriptor to read from

## Return Value

- The line that was read (including the terminating `\n` character, except at EOF)
- `NULL` if there is nothing more to read or if an error occurred

## How It Works

1. Reads from the file descriptor using `read()`
2. Stores what has been read in a static buffer
3. Returns one line at a time with each call
4. Keeps track of the position between calls using static variables
5. Handles multiple file descriptors simultaneously (bonus)

## Implementation Files

- `get_next_line.c` - Main function implementation
- `get_next_line_utils.c` - Helper functions
- `get_next_line.h` - Header file with prototypes and definitions

## Buffer Size

The function uses a compile-time defined buffer size:

```bash
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

The function must work with any `BUFFER_SIZE` value (1, 42, 9999, etc.)

## Usage Example

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## Compilation

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

## Key Challenges

- Managing memory efficiently
- Handling different buffer sizes
- Dealing with edge cases (empty files, no newlines, very long lines)
- Using static variables correctly
- Avoiding memory leaks
- Reading from multiple file descriptors (bonus)

## Skills Acquired

- Static variables and their lifetime
- File I/O operations
- Dynamic memory allocation
- Buffer management
- String manipulation
- Edge case handling
- Memory leak prevention

## Circle

**Circle 1** - Second major project at 42 School
