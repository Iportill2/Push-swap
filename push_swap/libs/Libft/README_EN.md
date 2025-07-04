# Libft

## Table of Contents
- [Overview](#overview)
- [Functions](#functions)
- [Compilation](#compilation)
- [Testing](#testing)
- [Memory Testing with Valgrind](#memory-testing-with-valgrind)

## Overview

The `libft` project is a foundational project that implements a personal C library with various standard functions and additional utilities. The goal is to deeply understand how standard C functions work by implementing them from scratch.

## Functions

The library includes the following categories of functions:

1. Character functions:
   - `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint`
   - `ft_toupper`, `ft_tolower`

2. String functions:
   - `ft_strlen`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`
   - `ft_strnstr`, `ft_strlcpy`, `ft_strlcat`
   - `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`
   - `ft_strmapi`, `ft_striteri`

3. Memory functions:
   - `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`
   - `ft_memchr`, `ft_memcmp`, `ft_calloc`

4. Conversion functions:
   - `ft_atoi`, `ft_itoa`

5. File descriptor functions:
   - `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`



## Compilation

To compile the library, follow these steps:

1. Clone the repository:
   ```bash
   git clone git@github.com:Iportill2/Libft.git
   cd libft
   ```

2. Compile the library:
   ```bash
   make
   ```
   This will create the `libft.a` file.



3. To clean object files:
   ```bash
   make clean
   ```

4. To clean all generated files:
   ```bash
   make fclean
   ```

5. To rebuild the library:
   ```bash
   make re
   ```

## Testing

A comprehensive test file (`test.c`) is provided to test all functions in the library.

1. Make sure you've compiled the library first:
   ```bash
   make
   ```

2. Compile the test file with the library:
   ```bash
   gcc -Wall -Wextra -Werror test.c -L. -lft -o test_libft
   ```
   
   **Important!** Don't forget to include `-L. -lft` to link with your libft.a library.
   - `-L.` tells the compiler to look for libraries in the current directory
   - `-lft` tells it to link with the `libft.a` library

3. Run the test:
   ```bash
   ./test_libft
   ```

4. For testing bonus functions, compile with:
   ```bash
   gcc -Wall -Wextra -Werror -DBONUS test.c -L. -lft -o test_libft
   ```

The test output will be displayed in the terminal, and file descriptor functions will write their output to `test_output.txt`.

### Common Issues

If you get errors like "undefined reference to `ft_isalpha'", it means you're not linking correctly with the library. Make sure to:

1. Compile the library first with `make`
2. Include the `-L. -lft` parameters in your compilation command
3. If you still have issues, verify that `libft.a` exists in your directory

## Memory Testing with Valgrind

To ensure there are no memory leaks, you can use Valgrind:

1. Install Valgrind if not already installed:
   ```bash
   sudo apt-get install valgrind
   ```

2. Run the test program with Valgrind:
   ```bash
   valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./test_libft
   ```

### Specific Valgrind Tests

For targeted memory testing of specific functions:

```bash
gcc -Wall -Wextra -Werror test.c -L. -lft -o test_libft
valgrind --leak-check=full ./test_libft
```

The functions most prone to memory issues are:
- `ft_split` (ensure all allocated strings and the array itself are freed)
- `ft_substr` (check edge cases like empty strings or out-of-bounds requests)
- `ft_strjoin` (verify proper allocation and handling of edge cases)


By thoroughly testing with Valgrind, you can ensure your library functions handle memory correctly and efficiently.
