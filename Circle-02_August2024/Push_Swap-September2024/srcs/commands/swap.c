#include "push_swap.h"

static void     swap(t_stack_node **head) // a function that swaps the positions of the top node and second node of a stack
{
    if (!*head || !(*head)->next) // Check if the start node, or the second node if a stack exists
        return;
    *head = (*head)->next; // Update 'head' to point to the next node, effectively swapping the first and second node
    (*head)->prev->prev = *head; // Update the 'prev' pointer of the node before the 'new head' to point to the 'new head'
    (*head)->prev->next = (*head)->next; // Update the `next` pointer of the node before the `new head` to skip the `old head` and point directly to the `new head`
    if ((*head)->next) // Check if the´s a 'next' node after the 'new head'
        (*head)->next->prev = (*head)->prev; // if so, update its 'prev' pointer to point back to the 'new head'
    (*head)->next = (*head)->prev; // Update the 'next' pointer of the 'new head' to point to the 'old head', effectively reversing their position
    (*head)->prev = NULL; // sets the 'prev' pointer of the 'new head' to NULL completing the swap
}

void    sa(t_stack_node **a, bool print_mode) // Swap the first two nodes of stack `a` and print the Operations
{
	swap(a);
	if (print_mode == PRINT)
		ft_printf("sa\n");
}

void    sb(t_stack_node **b, bool print_mode) // Swap the first two nodes of stack `b` and print the Operations
{
	swap(b);
	if (print_mode == PRINT)
		ft_printf("sb\n");
}

void    ss(t_stack_node **a, t_stack_node **b, bool print_mode) // Simutaneously swap the first two nodes of both stacks and print the Operations
{
	swap(a);
	swap(b);
	if (print_mode == PRINT)
		ft_printf("ss\n");
}
