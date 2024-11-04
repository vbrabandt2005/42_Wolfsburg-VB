/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:46:41 by vbrabandt         #+#    #+#             */
/*   Updated: 2024/11/04 13:42:59 by vbrabandt        ###   ########.fr       */
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

/* --- Error Handling --- */
int						error_syntax(char *str_n);
int						error_duplicate(t_stack_node *a, int n);
void					free_stack(t_stack_node **stack);
void					free_errors(t_stack_node **a, char **argv,
							bool is_split);
void					free_split(char **split_argv);

/* --- Stack Inititation --- */
char					**split(char *s, char c);
void					init_stack_a(t_stack_node **a, char **argv,
							bool is_split);

/* --- Node Initiation --- */
t_stack_node			*get_cheapest(t_stack_node *stack);
void					init_nodes_a(t_stack_node *a, t_stack_node *b);
void					init_nodes_b(t_stack_node *a, t_stack_node *b);
void					current_index(t_stack_node *stack);
void					set_cheapest(t_stack_node *stack);
void					prep_for_push(t_stack_node **stack,
							t_stack_node *top_node, char stack_name);

/* --- Stack Utils --- */
int						stack_len(t_stack_node *stack);
bool					stack_sorted(t_stack_node *stack);
t_stack_node			*find_last(t_stack_node *stack);
t_stack_node			*find_max(t_stack_node *stack);
t_stack_node			*find_min(t_stack_node *stack);

/* --- Commands --- */
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
void					rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);
void					rev_rotate_both(t_stack_node **a, t_stack_node **b,
							t_stack_node *cheapest_node);

/* --- Algorithm --- */
void					sort_three(t_stack_node **a);
void					sort_stacks(t_stack_node **a, t_stack_node **b);

#endif