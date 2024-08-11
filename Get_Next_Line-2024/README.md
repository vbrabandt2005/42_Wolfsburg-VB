# Get_Next_Line

## Explanation

A Program which reads a text file line by line efficiently.

## Bonus Explanation

Basically the Bonus version allows multiple **File Descriptors** (in simple terms files) to be read.

### To Run the code

#### Standard version

Compile the code: `gcc -D BUFFER_SIZE=10000 get_next_line.c get_next_line_utils.c main.c`

You can define the `BUFFER_SIZE` here for texting.

To Run it: `./a.out <YourTextFile.txt>`

#### Bonus Version

Compile the code: `gcc -D BUFFER_SIZE=10000 get_next_line_bonus.c get_next_line_utils_bonus.c main_bonus.c`

You can define the `BUFFER_SIZE` here for texting.

To Run it: `./a.out <File1.txt> <File2.txt> ....`

## Understanding the Three Functions

### ft_readfile

This function is responsible for reading chunks of data from a file and building a string containing the contents of the file up to a newline character.

**Reads data:** It reads data from the file in chunks using the read system call.

**Appends data:** It appends the read data to a growing string using `ft_strjoin`.

**Stops at newline:** It stops reading when it encounters a newline character.

### ft_freeline

This function extracts a single line from a larger string.

**Finds newline:** It locates the position of the first newline character in the string.

**Creates substring:** It creates a substring containing the characters after the newline (the next line).

**Modifies original string:** It removes the extracted line from the original string.

### get_next_line

This is the main function that coordinates the reading and extraction of lines.

**Allocates buffer:** It creates a buffer to store data read from the file.
**Calls `ft_readfile:`** It calls ft_readfile to read the file and build a string.
**Extracts line:** It uses ft_freeline to extract the first line from the string.
Handles leftovers: It stores the remaining part of the string for the next call.

#### TLDR

**`ft_readfile`** handles the low-level reading of data from the file.

**`ft_freeline`** processes the read data to extract a single line.

**`get_next_line`** orchestrates the overall process and provides the extracted line to the caller.

If you want to see how the code works step-by-step, I have a rather messy Markdown file [here](https://github.com/vbrabandt2005/42_Wolfsburg-VB/blob/add-GNL/Get_Next_Line-2024/Program_StepByStep.md).
