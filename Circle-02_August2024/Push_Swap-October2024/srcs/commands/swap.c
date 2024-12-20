/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 16:56:10 by vbrabandt         #+#    #+#             */
/*   Updated: 2024/10/31 16:56:10 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack_node **head)
{
	if (!*head || !(*head)->next)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_stack_node **a, bool print_mode)
{
	swap(a);
	if (!print_mode)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, bool print_mode)
{
	swap(b);
	if (!print_mode)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, bool print_mode)
{
	swap(a);
	swap(b);
	if (!print_mode)
		ft_printf("ss\n");
}
