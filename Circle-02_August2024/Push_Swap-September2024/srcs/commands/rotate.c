/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:18:02 by vbrabandt         #+#    #+#             */
/*   Updated: 2024/10/23 15:18:02 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     rotate(t_stack_node **stack)
{
    t_stack_node    *last_node;

    if (!*stack || !(*stack)->next)
        return;
    last_node = find_last(*stack);
    last_node->next = *stack;
    *stack = (*stack)->next;
    (*stack)->prev = NULL;
    last_node->next->prev = last_node;
    last_node->next->next = NULL;
}

void    ra(t_stack_node **a, bool print_mode)
{
    rotate(a);
    if (print_mode == PRINT)
        ft_printf("ra\n");
}

void    rb(t_stack_node **b, bool print_mode)
{
    rotate(b);
    if (print_mode == PRINT)
        ft_printf("rb\n");
}

void    rr(t_stack_node **a, t_stack_node **b, bool print_mode)
{
    rotate(a);
    rotate(b);
    if (print_mode == PRINT)
        ft_printf("rr\n");
}