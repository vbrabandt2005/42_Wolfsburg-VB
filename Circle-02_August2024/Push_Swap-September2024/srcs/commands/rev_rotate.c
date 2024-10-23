/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:18:11 by vbrabandt         #+#    #+#             */
/*   Updated: 2024/10/23 15:18:11 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     rev_rotate(t_stack_node **stack)
{
    t_stack_node    *last_node;
    if (!*stack || !(*stack)->next)
        return;
    last_node = find_last(*stack);
    last_node->prev->next = NULL;
    last_node->next = *stack;
    last_node->prev = NULL;
    *stack = last_node;
    last_node->next->prev = last_node;
}

void    rra(t_stack_node **a, bool print_mode)
{
    rev_rotate(a);
    if (print_mode == PRINT)
        ft_printf("rra\n");
}

void    rrb(t_stack_node **b, bool print_mode)
{
    rev_rotate(b);
    if (print_mode == PRINT)
        ft_printf("rrb\n");
}

void    rrr(t_stack_node **a, t_stack_node **b, bool print_mode)
{
    rev_rotate(a);
    rev_rotate(b);
    if (print_mode == PRINT)
        ft_printf("rrr\n");
}