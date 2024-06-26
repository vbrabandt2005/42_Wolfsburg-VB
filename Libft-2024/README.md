# Libft

Libft is a reimplementation of the libc liberies (+ a few extra custom functions).

## Simple libc stuff

### ft_isalnum

Return (1) if character inputted is an alphabet or number.

Returns (0) if it's not.

### ft_isalpha

Return (1) if character inputted is an alphabet.

Returns (0) if it's not.

### ft_isascii

Returns (1) if input is in the ascii table (0 to 127).

Returns (0) if it's not.

### ft_isdigit

Returns (1) if input is a digit ('0' to '9').

Returns (0) if it's not.

### ft_isprint

Returns (1) if input is printable (32 to 126).

Returns (0 if it's not).

### ft_tolower

Checks if input is uppercase and if it is, it will turn the input into a lowercase (+= 32).

### ft_toupper

Checks if input is lowercase and if it is, it will turn the input into an uppercase (-= 32).

### ft_strlen

Counts the amount of letters in a string.

**How it works:**

A basic While loop which loops until it reaches the null terminator (the end) and each time it loops it adds 1 to i, then when it reaches the end it returns the vaule of i.

### ft_strncmp

Compares two strings up to the amount set by `n`

### ft

## Hard libc stuff

### ft_atoi

Array to interger (turns Ascii code into actual numbers)

### ft_bzero

Literally turns things into zero (like empty zero)

**How it works:**

A While loop loops through depending on the variable `n` and appoints 0 into the characters in s.

## Custom function

### ft_putchar_fd

outputs a character but does something with the file descriptor

### ft_strjoin

Literally joins two strings together

### ft_strtrim

Trims things of a string

### ft_itoa

Integer to array, basically atoi but reverse, this turns normal numbers back into ascii numbers.