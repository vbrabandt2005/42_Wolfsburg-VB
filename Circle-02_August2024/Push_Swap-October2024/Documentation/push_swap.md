# Push_Swap

## Functions used in this Project

### Command Operations

- **push.c**
- **rev_rotate.c**
- **rotate_both.c**
- **rotate.c**
- **sort_stacks.c**
- **sort_three.c**
- **swap.c**

#### push.c

##### push

Moves the top node from the source stack to the destination stack

This function removes the top node from the source stack and adds it to the top of the destination stack.

It handles the following cases:

**1.** Empty source stack (no operation)
**2.** Empty destination stack (node becomes the only element)
**3.** Non-empty destination stack (node is added to the top)

The function maintains the integrity of both stacks by properly updating next and prev pointers, ensuring the doubly-linked list structure remains intact.

**@dst:** Pointer to the pointer of the destination stack's top node
**@src:** Pointer to the pointer of the source stack's top node

##### pa

Pushes the top node from stack B to stack A

this function performs the 'pa' (push to A) operation in the push_swap algorithm. It moves the top node from stack B to the top of stack A. The operation is optionally printed based on the print_mode parameter.

The function:

**1.** Calls the push function to move the top node from B to A
**2.** Prints "pa" if print_mode is set to PRINT

>Note: This function assumes that the push function correctly handles
>cases where stack B might be empty.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@print_mode:** Boolean flag to determine if the operation should be printed

##### pb

Push the top of 'a' on top of 'b' and print the operation

This function moves the top node from stack A to the top of stack B. If print_mode is set to PRINT, it outputs "pb" to indicate the operation.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@print_mode:** Boolean flag to determine if "pb" should be printed

#### rev_rotate.c

##### rev_rotate

Rotates a stack's bottom node to the top

This function moves the bottom node of the stack to the top position.

It handles the following cases:

**1.** Empty stack or single node stack (no operation)
**2.** Stack with multiple nodes (bottom node becomes top)

The function maintains the integrity of the stack by properly updating next and prev pointers of affected nodes.

**@stack:** Pointer to the pointer of the stack's top node

##### rra

Reverse rotate stack A and optionally print the operation

This function performs a reverse rotation on stack A, moving the bottom node to the top. If print_mode is set to PRINT, it outputs "rra" to indicate the operation.

**@a:** Pointer to the pointer of stack A's top node
**@print_mode:** Boolean flag to determine if "rra" should be printed

##### rrb

Reverse rotate stack B and optionally print the operation

This function performs a reverse rotation on stack B, moving the bottom node to the top. If print_mode is set to PRINT, it outputs "rrb" to indicate the operation.

**@b:** Pointer to the pointer of stack B's top node
**@print_mode:** Boolean flag to determine if "rrb" should be printed

##### rrr

Reverse rotate both stacks A and B and optionally print the operation

This function performs a reverse rotation on both stack A and stack B, moving the bottom node to the top in each stack. If print_mode is set to PRINT, it outputs "rrr" to indicate the operation.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@print_mode:** Boolean flag to determine if "rrr" should be printed

#### rotate_both.c

##### rotate_both

Rotate both stacks simultaneously until target positions are reached

This function rotates both stack A and stack B together until either:

**1.** The cheapest node in A reaches the top of stack A, or
**2.** The target node in B reaches the top of stack B
**3.** After rotation, it updates the indices of nodes in both stacks

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@cheapest_node:** Pointer to the node in A that needs to be moved

##### rev_rotate_both

Reverse rotate both stacks simultaneously until target positions are reached

This function reverse rotates both stack A and stack B together until either:

**1.** The cheapest node in A reaches the top of stack A, or
**2.** The target node in B reaches the top of stack B
**3.** After rotation, it updates the indices of nodes in both stacks.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@cheapest_node:** Pointer to the node in A that needs to be moved

#### rotate.c

##### rotate

Rotates the stack's top node to the bottom of the stack

This function moves the top node of the stack to the bottom position, effectively rotating all elements in the stack upwards by one position.

It handles the following cases:

**1.** Empty stack or single node stack (no operation)
**2.** Stack with multiple nodes (top node becomes bottom)

The function maintains the integrity of the stack by properly updating next and prev pointers of affected nodes.

**@stack:** Pointer to the pointer of the stack's top node

##### ra

Rotate stack A and optionally print the operation

This function performs a rotation on stack A, moving the top node to the bottom of the stack. If print_mode is set to PRINT, it outputs "ra" to indicate the operation.

**@a:** Pointer to the pointer of stack A's top node
**@print_mode:** Boolean flag to determine if "ra" should be printed

##### rb

Rotate stack B and optionally print the operation

this function performs a rotation on stack B, moving the top node to the bottom of the stack. If print_mode is set to PRINT, it outputs "rb" to indicate the operation.

**@b:** Pointer to the pointer of stack B's top node
**@print_mode:** Boolean flag to determine if "rb" should be printed

##### rr

Rotate both stacks A and B and optionally print the operation

This function performs a rotation on both stack A and stack B, moving the top node to the bottom in each stack. If print_mode is set to PRINT, it outputs "rr" to indicate the operation.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@print_mode:** Boolean flag to determine if "rr" should be printed

#### sort_stacks.c

##### move_a_to_b

Move the cheapest node from stack A to stack B

This function identifies and moves the "cheapest" node from stack A to stack B. The "cheapest" node is determined based on a specific criteria, typically related to the number of operations needed to move it to its target position in stack B.

The function performs the following steps:

**1.** Identifies the cheapest node in stack A using `get_cheapest`.
**2.** If both the cheapest node in A and its target node in B are above their respective medians, it rotates both stacks using `rotate_both`.
**3.** If both nodes are not above their medians, it reverse rotates both stacks using `rev_rotate_both`.
**4.** Prepares both stacks for pushing by moving the relevant nodes to the top using `prep_for_push`.
**5.** Pushes the top node from stack A to stack B using `pb`.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node

##### move_b_to_a

Move the top node from stack B to stack A

This function prepares and moves the top node from stack B to its target position in stack A. It ensures that the target node in stack A is ready to receive the node from stack B.

The function performs the following steps:

**1.** Prepares stack A by moving the target node to the top using `prep_for_push`.
**2.** Pushes the top node from stack B to stack A using `pa`.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node

##### min_on_top

Move the smallest number to the top of stack A

This function moves the smallest number in stack A to the top.
It determines whether to perform a rotate or reverse rotate based on the position of the smallest number relative to the median of the stack.

The function performs the following steps:

**1.** Continues rotating or reverse rotating until the smallest number is at the top.
**2.** Uses `ra` for rotation if the smallest number is above the median.
**3.** Uses `rra` for reverse rotation if the smallest number is not above the median.

**@a:** Pointer to the pointer of stack A's top node

##### sort_stacks

Sort stack A using stack B as auxiliary

This function implements the main sorting algorithm for stack A when it contains more than 3 elements. It uses stack B as an auxiliary stack to achieve the sorting.

The function performs the following steps:

1. If stack A has more than 3 elements and is not sorted:
   - **a.** Push the top two elements to stack B.
   - **b.** Continue moving elements from A to B until only 3 remain in A.
2. Sort the remaining 3 elements in stack A.
3. Move all elements from B back to A in sorted order.
4. Adjust stack A so that the smallest number is on top.

Throughout the process, the function initializes node data and uses helper functions to determine the most efficient moves.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node

#### sort_three.c

##### sort_three

Sort a stack of three elements

This function sorts a stack containing exactly three elements. It uses a combination of rotate and swap operations to achieve the correct order.

The algorithm works as follows:

**1.** Find the biggest node in the stack
**2.** If the biggest node is at the top, rotate once
**3.** If the biggest node is in the middle, reverse rotate once
**4.** If the top two elements are out of order, swap them

**@a:** Pointer to the pointer of stack A's top node

#### swap.c

##### swap

Swap the top two nodes of the stack

This function swaps the top two nodes of the stack. If the stack is empty or contains only one node, no operation is performed.

The function updates the pointers of the involved nodes to ensure that the stack structure remains intact after the swap.

The steps performed by this function are:

**1.** If the stack is empty or has only one node, return immediately.
**2.** Update the head pointer to point to the second node.
**3.** Adjust the previous and next pointers of the swapped nodes to maintain
   the integrity of the doubly linked list.

**@head:** Pointer to the pointer of the stack's top node

##### sa

Swap the top two nodes of stack A and optionally print the operation

This function swaps the top two nodes of stack A. If the stack is empty or contains only one node, no operation is performed. If print_mode is set to PRINT, it outputs "sa" to indicate the operation.

The function calls the `swap` function to perform the swap operation and handles the printing of the operation based on the provided flag.

**@a:** Pointer to the pointer of stack A's top node
**@print_mode:** Boolean flag to determine if "sa" should be printed

##### sb

Swap the top two nodes of stack B and optionally print the operation

This function swaps the top two nodes of stack B. If the stack is empty or contains only one node, no operation is performed. If print_mode is set to PRINT, it outputs "sb" to indicate the operation.

The function calls the `swap` function to perform the swap operation and handles the printing of the operation based on the provided flag.

**@b:** Pointer to the pointer of stack B's top node
**@print_mode:** Boolean flag to determine if "sb" should be printed

##### ss

Swap the top two nodes of both stacks A and B and optionally print the operation

This function swaps the top two nodes of both stack A and stack B. If either stack is empty or contains only one node, no operation is performed on that stack.

If print_mode is set to PRINT, it outputs "ss" to indicate the operation.

The function calls the `swap` function for both stacks and handles the printing
of the operation based on the provided flag.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@print_mode:** Boolean flag to determine if "ss" should be printed

### Stack Handling

#### error_handling.c

##### error_syntax

Check if a string represents a valid integer

This function validates whether the input string represents a valid integer.
It allows for an optional leading '+' or '-' sign, followed by one or more digits.

The function works as follows:

**1.** If the first character is '+' or '-', move past it.
**2.** Check if the first character (or second, if there was a sign) is a digit.
   If not, return 1 (error).
**3.** Iterate through the rest of the string:
   **a.** If any character is not a digit, return 1 (error).
**4.** If all checks pass, return 0 (no error).

**@str:** The input string to be validated

**@return:** 0 if the string represents a valid integer, 1 otherwise

##### error_duplicate

Check if a number already exists in the stack

This function traverses the stack to determine if the given number 'n' already exists in any node of the stack.
It's used to ensure that all numbers in the stack are unique.

The function works as follows:

1. Iterates through each node in the stack:
   **a.** If the current node's number matches 'n', return 1 (duplicate found).
   **b.** If not, move to the next node.
2. If the entire stack is traversed without finding a match, return 0 (no duplicate).

**@a:** Pointer to the top node of the stack
**@n:** The number to check for duplicates

**@return:** 1 if the number is found in the stack (duplicate), 0 otherwise

##### free_stack

Free all nodes in a stack

This function deallocates all memory associated with the nodes in the given stack.
It iterates through the stack, freeing each node and updating the stack pointer to the next node until the entire stack is deallocated.

The function works as follows:

1. While the stack is not empty:
   **a.** Store the next node in a temporary variable.
   **b.** Free the current node.
   **c.** Update the stack pointer to the next node.
2. After the loop, the stack pointer will be NULL, indicating an empty stack.

**@stack:** Pointer to the pointer of the top node of the stack

>Note: This function modifies the original stack pointer to NULL after freeing all nodes.

##### free_errors

Free the stack, print an error message, and exit the program

This function is called when an error occurs during stack operations.
It performs three main actions:

**1.** Frees all memory associated with the given stack.
**2.** Prints an "Error" message to the standard output.
**3.** Exits the program with a status code of 1.

The function works as follows:

**1.** Calls free_stack to deallocate all nodes in the stack.
**2.** Uses ft_printf to print "Error\n" to the standard output.
**3.** Calls exit(1) to terminate the program with an error status.

@a: Pointer to the pointer of the top node of the stack to be freed

>Note: This function does not return, as it terminates the program.

#### init_a_to_b.c

##### current_index

Assign index and median position to each node in the stack

This function traverses the stack and assigns an index to each node, starting from 0 at the top of the stack.
It also determines whether each node is above or below the median of the stack.

The function works as follows:

1. Check if the stack is empty. If so, return immediately.
2. Calculate the median index of the stack.
3. Traverse the stack, for each node:
   a. Assign the current index.
   b. Set the 'above_median' flag based on the node's position relative to the median.
   c. Move to the next node and increment the index.

**@stack:** Pointer to the top node of the stack

>Note: This function modifies the nodes in place, updating their 'index' and 'above_median' properties.

##### set_target_a

Set target nodes in stack B for each node in stack A

This function determines the optimal target node in stack B for each node in stack A.
The target node is the largest number in stack B that is smaller than the number in stack A.
If no such number exists, it targets the largest number in stack B.

The function works as follows:

1. For each node in stack A:
   a. Initialize best_index to LONG_MIN.
   b. Iterate through stack B:
      - If a node in B is smaller than the A node and larger than the current best_index:
        Update best_index and set this B node as the target.
   c. If no suitable target is found (best_index is still LONG_MIN):
      Set the target to the maximum node in stack B.
   d. Assign the found target node to the current A node.
   e. Move to the next A node.

**@a:** Pointer to the top node of stack A
**@b:** Pointer to the top node of stack B

##### cost_analysis

Calculate the push cost for each node in stack A

This function determines the cost (number of operations) required to push each node in stack A,
to its target position in stack B.
It takes into account the position of both the node in A and its target in B, considering whether
they are above or below the median in their respective stacks.

The function works as follows:

1. Calculate the length of both stacks A and B.
2. For each node in stack A:
   a. Calculate the cost to move the node to the top of A:
      - If above median: cost is its index
      - If below median: cost is stack length minus its index
   b. Add the cost to move its target node to the top of B:
      - If target is above median: add its index
      - If target is below median: add stack length minus its index
   c. Store the total cost in the node's push_cost property
   d. Move to the next node in A

**@a:** Pointer to the top node of stack A
**@b:** Pointer to the top node of stack B

>Note: This function assumes that the nodes have been previously initialized with correct index, above_median, and target_node properties.

##### set_cheapest

Identify and mark the node with the lowest push cost in the stack

This function traverses the stack to find the node with the minimum push_cost and marks it as the cheapest node.
This is typically used after cost_analysis to identify the most efficient node to push in a sorting algorithm.

The function works as follows:

1. Check if the stack is empty. If so, return immediately.
2. Initialize cheapest_value to LONG_MAX as a starting comparison point.
3. Iterate through each node in the stack:
   a. If the current node's push_cost is less than cheapest_value:
      - Update cheapest_value to this push_cost
      - Set cheapest_node to point to this node
4. After the iteration, mark the cheapest_node by setting its 'cheapest' flag to true.

**@stack:** Pointer to the top node of the stack

>Note: This function assumes that push_cost has been previously calculated for all nodes in the stack, typically by the cost_analysis function.

##### init_nodes_a

#### init_b_to_a.c

##### set_target_b

Set target nodes in stack A for each node in stack B

This function determines the optimal target node in stack A for each node in stack B.
The target node is the smallest number in stack A that is larger than the number in stack B.
If no such number exists, it targets the smallest number in stack A.

The function works as follows:

1. For each node in stack B:
   a. Initialize best_index to LONG_MAX.
   b. Iterate through stack A:
      - If a node in A is greater than the B node and smaller than the current best_index:
        Update best_index and set this A node as the target.
   c. If no suitable target is found (best_index is still LONG_MAX):
      Set the target to the minimum node in stack A.
   d. Assign the found target node to the current B node.
   e. Move to the next B node.

**@a:** Pointer to the top node of stack A
**@b:** Pointer to the top node of stack B

##### init_nodes_b

Initialize node properties for stacks A and B

This function prepares both stacks A and B for sorting operations by:

**1.** Assigning current indices to nodes in both stacks
**2.** Setting target nodes in stack A for each node in stack B

The function works as follows:

**1.** Call current_index on stack A to assign indices and determine median positions
**2.** Call current_index on stack B to assign indices and determine median positions
**3.** Call set_target_b to determine the optimal target node in A for each node in B

**@a:** Pointer to the top node of stack A
**@b:** Pointer to the top node of stack B

>Note: It modifies the nodes in both stacks by updating their properties.

#### push_swap.c

##### main

Entry point of the program for stack sorting

This function initializes and sorts a stack of integers. It handles different input formats,
(single string or multiple arguments) and applies appropriate sorting algorithms based on the number of elements.

The function works as follows:

1. Check for valid input (at least one argument).
2. If a single argument is provided, split it into an array of strings.
3. Initialize stack A with the provided numbers.
4. If stack A is not already sorted:
   a. For 2 elements: perform a single swap if needed.
   b. For 3 elements: use a specialized sort_three function.
   c. For more elements: use a general sort_stacks function.
5. Free the memory allocated for stack A.

**@argc:** Number of command-line arguments
**@argv:** Array of command-line argument strings
**@return:** 0 on successful execution, 1 if no arguments are provided

#### split.c

##### count_words

Count the number of substrings in a string separated by a delimiter

This function counts the number of substrings (words) in a given string, where words are separated by a specified delimiter character.

The function works as follows:

1. Initializes a count variable to 0 and a boolean flag 'inside_word'.
2. Iterates through the string:
   - **a.** Skips any consecutive delimiter characters.
   - **b.** When a non-delimiter character is found:
      - If not already inside a word, increments the count and sets 'inside_word' to true.
      - Continues until the next delimiter or end of string is reached.
3. Returns the final count of words.

**@str:** The input string to be analyzed
**@c:** The delimiter character
**@return:** The number of substrings (words) in the input string

##### get_next_Word

Extract the next substring (word) from a string separated by a delimiter

This function extracts and returns the next word from a given string, where words are separated by a specified delimiter character.
It maintains a static cursor to track the position within the string across multiple calls, allowing it to continue processing from where it left off.

The function works as follows:

**1.** Skips any leading delimiter characters at the current cursor position.
**2.** Calculates the length of the next word by counting characters until a delimiter
   or the end of the string is encountered.
**3.** Allocates memory for the new word, including space for a null terminator.
**4.** Copies characters from the original string into the new word until a delimiter
   or end of string is reached.
**5.** Null-terminates the new word and returns it.

**@str:** The input string to be processed
**@c:** The delimiter character separating words
**@return:** A newly allocated string containing the next word, or NULL

##### split

Split a string into an array of substrings based on a delimiter

This function splits the input string into an array of substrings, using the specified delimiter character.
It handles memory allocation and cleanup in case of errors.

The function works as follows:

**1.** Counts the number of words in the input string.
**2.** Allocates memory for an array to hold pointers to each substring, plus
   one additional slot for null termination.
**3.** Extracts each substring using get_next_word and stores it in the array.
**4.** If any memory allocation fails during the process, it frees all previously
   allocated memory and returns NULL.
**5.** Null-terminates the array of substrings.

**@str:** The input string to be split
**@c:** The delimiter character
**@return:** An array of strings (char**) containing the substrings, or NULL if memory allocation fails or if there are no words in the input string

#### stack_init.c

##### atol

Convert a string to a long integer

This function converts the initial portion of the string pointed to by str to a long integer representation.
It handles whitespace, signs, and numeric characters.

The function works as follows:

**1.** Skip leading whitespace characters.
**2.** Handle optional sign (+ or -).
**3.** Convert consecutive numeric characters to a long integer.
**4.** Apply the sign to the result.

**@str:** The string to be converted

**@return:** The converted long integer value

Behavior:

- Ignores leading whitespace (spaces, tabs, newlines, etc.).
- Handles a single optional '+' or '-' sign.
- Stops conversion at the first non-digit character.
- Does not handle overflow or underflow conditions.

##### append_node

Append a new node to the end of a stack

This function creates a new node with the given integer value and appends it to the end of the stack.
If the stack is empty, the new node becomes the first node of the stack.

The function works as follows:

**1.** Check if the stack pointer is valid.
**2.** Allocate memory for a new node.
**3.** Initialize the new node with the given value and default properties.
**4.** If the stack is empty, make the new node the first node.
**5.** If the stack is not empty, append the new node to the end.

**@stack:** Pointer to the pointer of the top node of the stack
**@n:** Integer value to be stored in the new node

##### init_stack_a

Initialize stack A with values from command-line arguments

This function processes command-line arguments to initialize stack A.
It performs various error checks and converts string arguments to integers
before adding them to the stack.

The function works as follows:

1. Iterate through each argument in argv.
2. For each argument:
   a. Check for syntax errors.
   b. Convert the argument to a long integer.
   c. Check if the number is within the range of an int.
   d. Check for duplicate values in the stack.
   e. Append the number to stack A.
3. If any error is encountered, free the stack and exit the program.

**@a:** Pointer to the pointer of the top node of stack A
**@argv:** Array of strings containing the arguments to be processed

##### get_cheapest

Find and return the node marked as cheapest in the stack

This function traverses the stack to find the first node that has been marked as the cheapest
(i.e., where the 'cheapest' flag is set to true).

The function works as follows:

1. Check if the stack is empty. If so, return NULL.
2. Iterate through each node in the stack:
   a. If the current node is marked as cheapest (cheapest flag is true),
      return this node.
   b. If not, move to the next node.
3. If no node is marked as cheapest, return NULL.

**@stack:** Pointer to the top node of the stack

**@return:** Pointer to the first node marked as cheapest, or NULL if no such node exists or if the stack is empty.

##### prep_for_push

Prepare a stack for pushing by rotating to the desired node

This function rotates the stack until the specified node (top_node) is at the top.
It uses either ra/rb (rotate) or rra/rrb (reverse rotate) operations depending on
whether the node is above or below the median of the stack.

The function works as follows:

1. Check if the desired node is already at the top of the stack.
2. If not, rotate the stack based on:
   a. The stack name ('a' or 'b')
   b. Whether the node is above or below the median of the stack
3. Use ra/rb for nodes above the median, rra/rrb for nodes below.

**@stack:** Pointer to the pointer of the top node of the stack
**@top_node:** Pointer to the node that should be moved to the top
**@stack_name:** Character indicating which stack is being operated on ('a' or 'b')

#### stack_utils.c

##### stack_len

Calculate and return the length of a stack

This function traverses the stack from the given node to the end, counting the number of nodes in the process.
It handles the case of an empty stack (NULL input) by returning 0.

The function works as follows:

**1.** Checks if the input stack is NULL, returning 0 if it is.
**2.** Initializes a counter to 0.
**3.** Traverses the stack using the 'next' pointer until reaching the end.
**4.** Increments the counter for each node visited.
**5.** Returns the final count, which represents the stack length.

**@stack:** Pointer to the top node of the stack

**@return:** The number of nodes in the stack, or 0 if the stack is empty

##### find_last

Find and return the pointer to the last node in a stack

This function traverses the stack from the given node to the end, returning a pointer to the last node.
It handles the case of an empty stack (NULL input) by returning NULL.

The function works as follows:

**1.** Checks if the input stack is NULL, returning NULL if it is.
**2.** Traverses the stack using the 'next' pointer until reaching a node whose 'next' pointer is NULL (indicating the last node).
**3.** Returns the pointer to the last node found.

**@stack:** Pointer to the top node of the stack

**@return:** Pointer to the last node in the stack, or NULL if the stack is empty

##### find_min

Find and return the node with the smallest number in a stack

This function traverses the entire stack to find the node containing the smallest number.
It handles the case of an empty stack (NULL input) by returning NULL.

The function works as follows:

1. Checks if the input stack is NULL, returning NULL if it is.
2. Initializes 'min' with LONG_MAX to ensure any number in the stack will be smaller.
3. Traverses the entire stack:
   **a.** Compares each node's number with the current minimum.
   **b.** If a smaller number is found, updates 'min' and 'min_node'.
4. Returns the pointer to the node with the smallest number.

**@stack:** Pointer to the top node of the stack

**@return:** Pointer to the node with the smallest number, or NULL if the stack is empty

##### find_max

Find and return the node with the largest number in a stack

This function traverses the entire stack to find the node containing the largest number.
It handles the case of an empty stack (NULL input) by returning NULL.

The function works as follows:

1. Checks if the input stack is NULL, returning NULL if it is.
2. Initializes 'max' with LONG_MIN to ensure any number in the stack will be larger.
3. Traverses the entire stack:
   **a.** Compares each node's number with the current maximum.
   **b.** If a larger number is found, updates 'max' and 'max_node'.
4. Returns the pointer to the node with the largest number.

**@stack:** Pointer to the top node of the stack

**@return:** Pointer to the node with the largest number, or NULL if the stack is empty

##### stack_sorted

Check if a stack is sorted in ascending order

This function traverses the stack to determine if it is sorted in ascending order. An empty stack is considered sorted.
The function checks each pair of adjacent nodes to ensure that the values are in ascending order.

The function works as follows:

1. Checks if the input stack is NULL, returning true if it is (empty stack is considered sorted).
2. Traverses the stack, comparing each node with its next node:
   **a.** If the current node's value is greater than the next node's value, returns false.
   **b.** If not, moves to the next node.
3. If the entire stack is traversed without finding any out-of-order pairs, returns true.

**@stack:** Pointer to the top node of the stack

**@return:** true if the stack is sorted in ascending order or empty, false otherwise
