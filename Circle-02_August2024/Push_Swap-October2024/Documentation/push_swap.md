# Push_Swap

## Functions used in this Project

### Command Operations

- **push.c**
- **rev_rotate.c**
- **rotate.c**
- **sort_stacks.c**
- **sort_three.c**
- **swap.c**

#### push.c

##### push

Moves the top node from the source stack to the destination stack

This function removes the top node from the source stack and adds it to the top of the destination stack.

It handles the following cases:

1. Empty source stack (no operation)
2. Empty destination stack (node becomes the only element)
3. Non-empty destination stack (node is added to the top)

The function maintains the integrity of both stacks by properly updating next and prev pointers, ensuring the doubly-linked list structure remains intact.

@dst: Pointer to the pointer of the destination stack's top node
@src: Pointer to the pointer of the source stack's top node

##### pa

Pushes the top node from stack B to stack A

this function performs the 'pa' (push to A) operation in the push_swap algorithm. It moves the top node from stack B to the top of stack A. The operation is optionally printed based on the print_mode parameter.

The function:

1. Calls the push function to move the top node from B to A
2. Prints "pa" if print_mode is set to PRINT

>Note: This function assumes that the push function correctly handles
>cases where stack B might be empty.

@a: Pointer to the pointer of stack A's top node
@b: Pointer to the pointer of stack B's top node
@print_mode: Boolean flag to determine if the operation should be printed

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

1. Empty stack or single node stack (no operation)
2. Stack with multiple nodes (bottom node becomes top)

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

#### rotate.c

##### rotate

Rotates the stack's top node to the bottom of the stack

This function moves the top node of the stack to the bottom position, effectively rotating all elements in the stack upwards by one position.

It handles the following cases:

1. Empty stack or single node stack (no operation)
2. Stack with multiple nodes (top node becomes bottom)

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

##### rotate_both

Rotate both stacks simultaneously until target positions are reached

This function rotates both stack A and stack B together until either:

1. The cheapest node in A reaches the top of stack A, or
2. The target node in B reaches the top of stack B
3. After rotation, it updates the indices of nodes in both stacks

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@cheapest_node:** Pointer to the node in A that needs to be moved

##### rev_rotate_both

Reverse rotate both stacks simultaneously until target positions are reached

This function reverse rotates both stack A and stack B together until either:

1. The cheapest node in A reaches the top of stack A, or
2. The target node in B reaches the top of stack B
3. After rotation, it updates the indices of nodes in both stacks.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@cheapest_node:** Pointer to the node in A that needs to be moved

##### move_a_to_b

Move the cheapest node from stack A to stack B

This function identifies and moves the "cheapest" node from stack A to stack B. The "cheapest" node is determined based on a specific criteria, typically related to the number of operations needed to move it to its target position in stack B.

The function performs the following steps:

1. Identifies the cheapest node in stack A using `get_cheapest`.
2. If both the cheapest node in A and its target node in B are above their respective medians,
   it rotates both stacks using `rotate_both`.
3. If both nodes are not above their medians, it reverse rotates both stacks using `rev_rotate_both`.
4. Prepares both stacks for pushing by moving the relevant nodes to the top using `prep_for_push`.
5. Pushes the top node from stack A to stack B using `pb`.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node

##### move_b_to_a

Move the top node from stack B to stack A

This function prepares and moves the top node from stack B to its target position in stack A. It ensures that the target node in stack A is ready to receive the node from stack B.

The function performs the following steps:

1. Prepares stack A by moving the target node to the top using `prep_for_push`.
2. Pushes the top node from stack B to stack A using `pa`.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node

##### min_on_top

Move the smallest number to the top of stack A

This function moves the smallest number in stack A to the top.
It determines whether to perform a rotate or reverse rotate based on the position of the smallest number relative to the median of the stack.

The function performs the following steps:

1. Continues rotating or reverse rotating until the smallest number is at the top.
2. Uses `ra` for rotation if the smallest number is above the median.
3. Uses `rra` for reverse rotation if the smallest number is not above the median.

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

@a: Pointer to the pointer of stack A's top node
@b: Pointer to the pointer of stack B's top node

#### sort_three.c

##### sort_three

Sort a stack of three elements

This function sorts a stack containing exactly three elements. It uses a combination of rotate and swap operations to achieve the correct order.

The algorithm works as follows:

1. Find the biggest node in the stack
2. If the biggest node is at the top, rotate once
3. If the biggest node is in the middle, reverse rotate once
4. If the top two elements are out of order, swap them

**@a:** Pointer to the pointer of stack A's top node

#### swap.c

##### swap

Swap the top two nodes of the stack

This function swaps the top two nodes of the stack. If the stack is empty or contains only one node, no operation is performed.

The function updates the pointers of the involved nodes to ensure that the stack structure remains intact after the swap.

The steps performed by this function are:

1. If the stack is empty or has only one node, return immediately.
2. Update the head pointer to point to the second node.
3. Adjust the previous and next pointers of the swapped nodes to maintain
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

The function calls the `swap` function for both stacks and handles the printing of the operation based on the provided flag.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@print_mode:** Boolean flag to determine if "ss" should be printed

### Stack Handling

#### error_handling.c

##### error_syntax

##### error_duplicate

##### free_stack

##### free_errors

#### init_a_to_b.c

##### current_index

##### set_target_a

##### cost_analysis_a

##### set_cheapest

##### init_nodes_a

#### init_b_to_a.c

##### set_target_b

##### init_nodes_b

#### push_swap.c

##### main

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

1. Skips any leading delimiter characters at the current cursor position.
2. Calculates the length of the next word by counting characters until a delimiter
   or the end of the string is encountered.
3. Allocates memory for the new word, including space for a null terminator.
4. Copies characters from the original string into the new word until a delimiter
   or end of string is reached.
5. Null-terminates the new word and returns it.

**@str:** The input string to be processed
**@c:** The delimiter character separating words
**@return:** A newly allocated string containing the next word, or NULL

##### split

Split a string into an array of substrings based on a delimiter

This function splits the input string into an array of substrings, using the specified delimiter character.
It handles memory allocation and cleanup in case of errors.

The function works as follows:

1. Counts the number of words in the input string.
2. Allocates memory for an array to hold pointers to each substring, plus
   one additional slot for null termination.
3. Extracts each substring using get_next_word and stores it in the array.
4. If any memory allocation fails during the process, it frees all previously
   allocated memory and returns NULL.
5. Null-terminates the array of substrings.

**@str:** The input string to be split
**@c:** The delimiter character
**@return:** An array of strings (char**) containing the substrings, or NULL if memory allocation fails or if there are no words in the input string

#### stack_init.c

##### atol

##### append_node

##### init_stack_a

##### get_cheapest

##### prep_for_push

#### stack_utils.c

##### stack_len

Calculate and return the length of a stack

This function traverses the stack from the given node to the end, counting the number of nodes in the process.
It handles the case of an empty stack (NULL input) by returning 0.

The function works as follows:

1. Checks if the input stack is NULL, returning 0 if it is.
2. Initializes a counter to 0.
3. Traverses the stack using the 'next' pointer until reaching the end.
4. Increments the counter for each node visited.
5. Returns the final count, which represents the stack length.

**@stack:** Pointer to the top node of the stack

**@return:** The number of nodes in the stack, or 0 if the stack is empty

##### find_last

Find and return the pointer to the last node in a stack

This function traverses the stack from the given node to the end, returning a pointer to the last node.
It handles the case of an empty stack (NULL input) by returning NULL.

The function works as follows:

1. Checks if the input stack is NULL, returning NULL if it is.
2. Traverses the stack using the 'next' pointer until reaching a node whose 'next' pointer is NULL (indicating the last node).
3. Returns the pointer to the last node found.

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
