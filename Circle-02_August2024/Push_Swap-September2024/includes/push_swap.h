/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:46:41 by vbrabandt         #+#    #+#             */
/*   Updated: 2024/10/23 13:19:18 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/Libft_Modified-2024/srcs/libft.h"
# include <limits.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define PRINT true
# define SILENT false

typedef struct s_stack_node
{
	int					num;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;

	struct s_stack_node	*target_node;

	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}						t_stack_node;

void					sa(t_stack_node **a, bool print_mode);
void					sb(t_stack_node **b, bool print_mode);
void					ss(t_stack_node **a, t_stack_node **b, bool print_mode);
void					ra(t_stack_node **a, bool print_mode);
void					rb(t_stack_node **b, bool print_mode);
void					rr(t_stack_node **a, t_stack_node **b, bool print_mode);
void					rra(t_stack_node **a, bool print_mode);
void					rrb(t_stack_node **b, bool print_mode);
void					rrr(t_stack_node **a, t_stack_node **b,
							bool print_mode);
void					pa(t_stack_node **a, t_stack_node **b, bool print_mode);
void					pb(t_stack_node **a, t_stack_node **b, bool print_mode);

#endif