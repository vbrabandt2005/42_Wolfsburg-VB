# Get_Next_Line

1. The program includes the header file get_next_line.h, which likely contains function prototypes and necessary definitions.

2. The ft_readfile function is defined. It takes three parameters: fd (file descriptor), str (a string to store the file content), and buffer (a temporary buffer to read data from the file).

3. Inside the ft_readfile function, a loop is used to read the file in chunks until there is no more data to read (buff_read becomes 0).

4. If there is an error while reading the file (buff_read is -1), the function frees the memory allocated for str and returns NULL.

5. If there is no error and there is data to read (buff_read is greater than 0), the buffer is null-terminated and appended to the str string using the ft_strjoin function. The previous value of str is freed to avoid memory leaks.

6. If a newline character ('\n') is found in the buffer, the loop breaks, indicating that a complete line has been read.

7. The ft_readfile function returns the str string.

8. The ft_freeline function is defined. It takes a single parameter, str, which represents the string containing the file content.

9. Inside the ft_freeline function, it searches for the first occurrence of a newline character ('\n') in the str string. If it doesn't find a newline character or the string is empty, it returns NULL.

10. If a newline character is found, it creates a new string (line) using the ft_substr function, which extracts the substring starting from the character after the newline character until the end of the string.

11. If the line string is empty, it frees the memory allocated for line and sets it to NULL.

12. The newline character in the str string is replaced with a null character ('\0'), effectively removing the line that has been read.

13. The ft_freeline function returns the line string.

14. The get_next_line function is defined. It takes a single parameter, fd, which represents the file descriptor of the file to read.

15. Inside the get_next_line function, a buffer of size BUFFER_SIZE + 1 is allocated using malloc. If the allocation fails, it returns NULL.

16. It performs some checks to ensure that the BUFFER_SIZE is valid and that the file descriptor is valid. If any of these checks fail, it frees the memory allocated for str and buffer, sets them to NULL, and returns NULL.

17. The ft_readfile function is called to read the file and store its content in the str string.

18. The buffer memory is freed to avoid memory leaks.

19. If the line string is NULL, indicating that there are no more lines to read, it returns NULL.

20. The str string is updated by calling the ft_freeline function, which removes the line that has been read from the str string.

21. Finally, the line string is returned, containing the next line of the file.
