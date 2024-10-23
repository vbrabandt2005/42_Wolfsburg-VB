#include "../includes/push_swap.h"

static void     push(t_stack_node **dst, t_stack_node **src) // a function that pushes a top node, from one stack to another top node
{
    t_stack_node    *push_node; // Used to store the pointer to the node to be pushed

    if (!*src) // The top node of a stack to be pushed must exist
        return;
    push_node = *src; // The top node to push is assigned to the 't_stack_node' variable
    *src = (*src)->next; // Move the pointer of the the stack to the next node, which will become the next 'top node' after the node before is "popped off"
    if (*src) // Check if the current node exists
        (*src)->prev = NULL; // Set the current node as the head of the stack
    push_node->prev = NULL; // Detach the node to push from its stack
    if (!*dst) // Check if the other stack is empty
    {
        *dst = push_node; // If it's empty, assign as the first node of that stack, the node we want pushed
        push_node->next = NULL; // Ensure it is also set as the last node, e.g. properly null terminate the stack
    }
    else
    {
        push_node->next = *dst; // Assign the node to push, to the top of the current top node of the stack
        push_node->next->prev = push_node; // Assign to the "second node" 'prev' attribute, the pushed node as the current top node
        *dst = push_node; // Complete appending the node. The Pointer to the top node of the stack is now pointing to our recent pushed node
    }
}

void    pa(t_stack_node **a, t_stack_node **b, bool print_mode) // Push the top of 'a' on top of 'b' and print the operation
{
    push(a, b);
    if (print_mode == PRINT)
        ft_printf("pa\n");
}

void    pb(t_stack_node **a, t_stack_node **b, bool print_mode) // Push the top of 'b' on top of 'a' and print the operation
{
    push(b, a);
    if (print_mode == PRINT)
        ft_printf("pb\n");
}