# This header file, `libft.h`, declares a collection of functions that are part of a custom C library, presumably named `libft`. This library appears to be designed to mimic and extend the functionality of the standard C library, providing basic string manipulation, memory management, and utility functions

## String Functions

- `ft_strlen(char const *str)`: Returns the length of the string `str`.
  
- `ft_strdup(const char *s)`: Duplicates the string `s` and returns a pointer to the new string.

- `ft_strlcat(char *dest, char *src, unsigned int size)`: Appends the string `src` to the end of `dest`, ensuring the total string length does not exceed `size`. Returns the total length of the string it tried to create.

- `ft_strlcpy(char *dest, char const *src, size_t n)`: Copies up to `n - 1` characters from `src` to `dest`, null-terminating the result if `n` is not 0. Returns the length of `src`.

- `ft_strncmp(char const *s1, char const *s2, size_t n)`: Compares up to `n` characters of the strings `s1` and `s2`. Returns an integer less than, equal to, or greater than zero if `s1` is found, respectively, to be less than, to match, or be greater than `s2`.

- `ft_strnstr(const char *s, const char *find, size_t slen)`: Locates the first occurrence of the null-terminated string `find` in the string `s`, where not more than `slen` characters are searched. Returns a pointer to the located string, or `NULL` if the string is not found.

- `ft_strchr(const char *s, int c)`: Locates the first occurrence of `c` (converted to a char) in the string `s`. Returns a pointer to the located character, or `NULL` if the character does not appear in the string.

- `ft_strrchr(const char *s, int c)`: Locates the last occurrence of `c` (converted to a char) in the string `s`. Returns a pointer to the located character, or `NULL` if the character does not appear in the string.

### Memory Functions

- `ft_memchr(void const *str, int c, size_t n)`: Scans the initial `n` bytes of the memory area pointed to by `str` for the first instance of `c`. Returns a pointer to the matching byte or `NULL` if the character does not occur in the given memory area.

- `ft_memcmp(void const *s1, void const *s2, size_t n)`: Compares the first `n` bytes of the memory areas `s1` and `s2`. Returns an integer less than, equal to, or greater than zero if the first `n` bytes of `s1` is found, respectively, to be less than, to match, or be greater than the first `n` bytes of `s2`.

- `ft_memcpy(void *dest, const void *src, size_t len)`: Copies `len` bytes from memory area `src` to memory area `dest`. Returns a pointer to `dest`.

- `ft_memmove(void *dest, const void *src, size_t len)`: Copies `len` bytes from `src` to `dest`. The memory areas may overlap. Returns a pointer to `dest`.

- `ft_memset(void *dest, int val, size_t len)`: Fills the first `len` bytes of the memory area pointed to by `dest` with the constant byte `val`. Returns a pointer to the memory area `dest`.

## Character Functions

- `ft_tolower(int c)`: Converts a given character to lowercase if it is uppercase. Returns the converted character.

- `ft_toupper(int c)`: Converts a given character to uppercase if it is lowercase. Returns the converted character.

- `ft_isprint(int c)`: Checks if the passed character is printable. Returns a non-zero value if true, and zero if false.

- `ft_isalnum(int c)`: Checks if the passed character is alphanumeric. Returns a non-zero value if true, and zero if false.

- `ft_isalpha(int c)`: Checks if the passed character is alphabetic. Returns a non-zero value if true, and zero if false.

- `ft_isascii(int c)`: Checks if the passed character is a valid ASCII character. Returns a non-zero value if true, and zero if false.

- `ft_isdigit(int c)`: Checks if the passed character is a digit. Returns a non-zero value if true, and zero if false.

- `ft_isprint(int c)`: Checks if the passed character is printable. Returns a non-zero value if true, and zero if false.

- `ft_atoi(const char *str)`: Converts the initial portion of the string `str` to an integer representation. Returns the converted integer.

## Additional Utility Functions

- `ft_itoa(int n)`: Converts an integer `n` to a null-terminated string. Returns the string representing the integer.

- `ft_putchar_fd(char c, int fd)`: Outputs the character `c` to the given file descriptor `fd`.

- `ft_putendl_fd(char *s, int fd)`: Outputs the string `s` to the given file descriptor `fd`, followed by a newline.

- `ft_putnbr_fd(int n, int fd)`: Outputs the integer `n` to the given file descriptor `fd`.

- `ft_putstr_fd(char *c, int fd)`: Outputs the string `c` to the given file descriptor `fd`.

- `ft_striteri(char *s, void (*f)(unsigned int, char*))`: Applies the function `f` to each character of the string `s`, passing its index as the first argument. Each character is passed by address to `f` to be modified if necessary.

- `ft_split(char const *s, char c)`: Splits the string `s` into an array of strings using the character `c` as a delimiter. The array ends with a `NULL` pointer.

- `ft_strjoin(char const *s1, char const *s2)`: Allocates and returns a new string, which is the concatenation of `s1` and `s2`.

- `ft_strmapi(char const *s, char (*f)(unsigned int, char))`: Applies the function `f` to each character of the string `s` to create a new string (with `malloc(3)`) resulting from successive applications of `f`.

- `ft_strtrim(char const *s1, char const *set)`: Trims the beginning and end of `s1` with the specified characters in `set`. Returns the trimmed string.

- `ft_substr(char const *s, unsigned int start, size_t len)`: Allocates and returns a substring from the string `s`. The substring begins at index `start` and is of maximum size `len`.

- `ft_calloc(size_t count, size_t size)`: Allocates memory for an array of `count` elements, each of size `size`, and initializes all bytes to zero. Returns a pointer to the allocated memory.
