/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 15:18:18 by vbrabandt         #+#    #+#             */
/*   Updated: 2024/10/23 15:18:18 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void     push(t_stack_node **dst, t_stack_node **src)
{
    t_stack_node    *push_node;

    if (!*src)
        return;
    push_node = *src;
    *src = (*src)->next;
    if (*src)
        (*src)->prev = NULL;
    push_node->prev = NULL;
    if (!*dst)
    {
        *dst = push_node;
        push_node->next = NULL;
    }
    else
    {
        push_node->next = *dst;
        push_node->next->prev = push_node;
        *dst = push_node;
    }
}

void    pa(t_stack_node **a, t_stack_node **b, bool print_mode)
{
    push(a, b);
    if (print_mode == PRINT)
        ft_printf("pa\n");
}

void    pb(t_stack_node **a, t_stack_node **b, bool print_mode)
{
    push(b, a);
    if (print_mode == PRINT)
        ft_printf("pb\n");
}