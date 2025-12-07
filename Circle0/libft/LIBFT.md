# Libft

## Description

Libft is your first project at 42 School. The goal is to re-implement a set of standard C library functions from scratch, along with some additional utility functions. This library will serve as a foundation for future projects throughout the curriculum.

## Project Overview

This project teaches you to:
- Understand how standard C library functions work internally
- Write clean, well-documented C code following strict coding standards
- Manage memory allocation and deallocation properly
- Create a reusable static library

## Functions Implemented

### Part 1 - Libc Functions

Standard C library functions reimplemented:

**Character Checks:**
- `ft_isalpha` - Check if character is alphabetic
- `ft_isdigit` - Check if character is a digit
- `ft_isalnum` - Check if character is alphanumeric
- `ft_isascii` - Check if character is ASCII
- `ft_isprint` - Check if character is printable

**String Manipulation:**
- `ft_strlen` - Calculate string length
- `ft_strlcpy` - Copy string with size limit
- `ft_strlcat` - Concatenate strings with size limit
- `ft_strchr` - Locate character in string
- `ft_strrchr` - Locate character in string (from end)
- `ft_strncmp` - Compare strings up to n characters
- `ft_strnstr` - Locate substring in string
- `ft_strdup` - Duplicate string

**Memory Functions:**
- `ft_memset` - Fill memory with constant byte
- `ft_bzero` - Zero out memory
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Copy memory area (handles overlap)
- `ft_memchr` - Scan memory for character
- `ft_memcmp` - Compare memory areas

**Conversion Functions:**
- `ft_atoi` - Convert string to integer
- `ft_tolower` - Convert character to lowercase
- `ft_toupper` - Convert character to uppercase

**Memory Allocation:**
- `ft_calloc` - Allocate and zero memory

### Part 2 - Additional Functions

Functions not in libc or with different prototypes:

- `ft_substr` - Extract substring from string
- `ft_strjoin` - Concatenate two strings (with malloc)
- `ft_strtrim` - Trim characters from beginning and end
- `ft_split` - Split string by delimiter into array
- `ft_itoa` - Convert integer to string
- `ft_strmapi` - Apply function to each character (with index)
- `ft_striteri` - Apply function to each character (with index, in place)
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string with newline to file descriptor
- `ft_putnbr_fd` - Output number to file descriptor

## Compilation

The project includes a `Makefile` with the following rules:

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile everything
```

## Usage

After compilation, link the library with your project:

```bash
gcc -Wall -Wextra -Werror your_program.c -L. -lft -o your_program
```

Include the header in your C files:

```c
#include "libft.h"
```

## Skills Acquired

- Deep understanding of C standard library
- Memory management
- String manipulation
- Makefile creation
- Following coding standards (Norminette)
- Creating and using static libraries

## Circle

**Circle 0** - First project at 42 School
