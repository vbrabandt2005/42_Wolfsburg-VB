/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: bjbogisc <bjbogisc@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024/10/22 11:56:27 by bjbogisc          #+#    #+#             */
/*   Updated: 2024/10/22 11:56:27 by bjbogisc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool print_mode)
{
	rotate(a);
	if (!print_mode)
		ft_printf("ra\n");
}

void	rb(t_stack_node **b, bool print_mode)
{
	rotate(b);
	if (!print_mode)
		ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b, bool print_mode)
{
	rotate(a);
	rotate(b);
	if (!print_mode)
		ft_printf("rr\n");
}
