#include "push_swap.h"

static void     rev_rotate(t_stack_node **stack) // a function that rotates a stack´s bottom node to the top
{
    t_stack_node    *last_node; // To Store a pointer to the last node of a Stack
    if (!*stack || !(*stack)->next)
        return;
    last_node = find_last(*stack);
    last_node->prev->next = NULL; // Assign to the 'next' attribute of the node before itself, 'NULL' effectively setting it as the current last node
    last_node->next = *stack; // Assign to its own 'next' attribute as ththe top node of the stack
    last_node->prev = NULL; // Detach itself from the node before it
    *stack = last_node; // Complete appending itself to the top of the stack, and now holds the pointer to the top node
    last_node->next->prev = last_node; // Update the current last node of the stack
}

void    rra(t_stack_node **a, bool print_mode) // Rotate the bottom of 'a' to the top of the stack and print the Operation
{
    rev_rotate(a);
    if (print_mode == PRINT)
        ft_printf("rra\n");
}

void    rrb(t_stack_node **b, bool print_mode) // Rotate the bottom of 'b' to the top of the stack and print the Operation
{
    rev_rotate(b);
    if (print_mode == PRINT)
        ft_printf("rrb\n");
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print_mode) // Simultaneously rotate both stacks bottom nodes to the top of their stacks, halving the cost of operations
{
    rev_rotate(a);
    rev_rotate(b);
    if (print_mode == PRINT)
        ft_printf("rrr\n");
}