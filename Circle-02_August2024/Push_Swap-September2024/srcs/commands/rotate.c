#include "push_swap.h"

static void     rotate(t_stack_node **stack) // a function that rotates the stack´s top node to the bottom of the stack
{
    t_stack_node    *last_node; // To Store a pointer to the last node of a Stack

    if (!*stack || !(*stack)->next)
        return;
    last_node = find_last(*stack);
    last_node->next = *stack; // Assign to the last node, it's 'next' attribute as the top node, effectively setting the current top node as the last node
    *stack = (*stack)->next; // Assign to the pointer of the top node, the node after it (second from the top)
    (*stack)->prev = NULL; // Complete setting the current top node by detaching it from its previous top node
    last_node->next->prev = last_node; // Reconnect the second node's prev pointer to point to what was previously the last node in the stack
    last_node->next->next = NULL; // Assign to the 'next' attribute of the current last node, 'NULL' effectively setting it as the current last node, and properly null terminating the stack
}

void    ra(t_stack_node **a, bool print_mode) // Rotate the top `a` node to the bottom of the stack, and print the instruction
{
    rotate(a);
    if (print_mode == PRINT)
        ft_printf("ra\n");
}

void    rb(t_stack_node **b, bool print_mode) // Rotate the top `b` node to the bottom of the stack, and print the instruction
{
    rotate(b);
    if (print_mode == PRINT)
        ft_printf("rb\n");
}

void    rr(t_stack_node **a, t_stack_node **b, bool print_mode) // Simultaneously rotate both the top `a` and `b` nodes to the bottom of the stack, and print the operations
{
    rotate(a);
    rotate(b);
    if (print_mode == PRINT)
        ft_printf("rr\n");
}