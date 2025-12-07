# ft_printf

## Description

ft_printf is a project where you recreate the famous C library function `printf`. This project will help you discover variadic functions in C and improve your understanding of formatted output.

## Project Overview

The goal is to implement your own `printf` function that can handle various format specifiers and produce output identical to the original `printf` function.

This project teaches you:
- How to work with variadic functions (`stdarg.h`)
- Parsing and format string interpretation
- Type conversion and formatting
- Building complex functions from smaller components

## Prototype

```c
int ft_printf(const char *format, ...);
```

## Supported Conversions

The function handles the following format specifiers:

- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address in hexadecimal format
- `%d` - Print a decimal (base 10) number
- `%i` - Print an integer in base 10
- `%u` - Print an unsigned decimal number
- `%x` - Print a number in hexadecimal (lowercase)
- `%X` - Print a number in hexadecimal (uppercase)
- `%%` - Print a percent sign

## Implementation Files

- `ft_printf.c` - Main function and format parser
- `ft_printf.h` - Header file with function prototypes
- `ft_putchar_fd.c` - Output single character
- `ft_str.c` - Handle string conversion (%s)
- `ft_nbr.c` - Handle decimal numbers (%d, %i)
- `ft_uns.c` - Handle unsigned numbers (%u)
- `ft_hex.c` - Handle hexadecimal conversions (%x, %X)
- `ft_ptr.c` - Handle pointer addresses (%p)
- `ft_percent.c` - Handle percent sign (%%)
- `ft_itoa.c` - Integer to ASCII conversion
- `Makefile` - Compilation rules

## Compilation

```bash
make        # Compile the library
make clean  # Remove object files
make fclean # Remove object files and library
make re     # Recompile everything
```

## Usage

Include the library in your project:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s!\n", "World");
    ft_printf("Number: %d\n", 42);
    ft_printf("Hex: %x\n", 255);
    ft_printf("Pointer: %p\n", &main);
    return (0);
}
```

Compile with:

```bash
gcc -Wall -Wextra -Werror your_program.c -L. -lftprintf -o your_program
```

## Return Value

Like the original `printf`, the function returns the total number of characters printed (excluding the null terminator).

## Skills Acquired

- Variadic functions in C
- Format string parsing
- Type conversion and casting
- Modular programming
- Understanding of printf internals
- Number base conversions

## Circle

**Circle 1** - Second major project at 42 School
