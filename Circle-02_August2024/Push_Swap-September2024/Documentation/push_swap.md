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

sort_three - Sort a stack of three elements

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

The function calls the `swap` function for both stacks and handles the printing
of the operation based on the provided flag.

**@a:** Pointer to the pointer of stack A's top node
**@b:** Pointer to the pointer of stack B's top node
**@print_mode:** Boolean flag to determine if "ss" should be printed

### Stack Handling

#### split.c

#### stack_init.c

#### stack_utils.c
