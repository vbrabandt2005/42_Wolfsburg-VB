/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 12:46:41 by vbrabandt         #+#    #+#             */
/*   Updated: 2024/10/23 12:46:41 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/Libft_Modified-2024/srcs/libft.h"
# include <limits.h>    //To define MIN and MAX macros
# include <stdbool.h>   //To use bool flags, i. e to print or not to print
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <unistd.h>

# define PRINT true     //To print the operations
# define SILENT false   //To not print the operations

typedef struct s_stack_node
{
    int                     num;            // The number to sort
    int                     index;          // The number´s position in the stack
    int                     push_cost;      // How many commands in total
    bool                    above_median;   // Used to calculate 'push_cost
    bool                    cheapest;       // The node that is the cheapes to do commands
    struct s_stack_node    *target_node;   // The target node of a node in the opposite stack
    struct s_stack_node    *next;          // a pointer to the next node
    struct s_stack_node    *prev;          // a pointer to the previous node
}   t_stack_node;                          // the "shortened name"

/* --- Error Handling --- */

/* --- Stack Inititation --- */

/* --- Node Initiation --- */

/* --- Stack Utils --- */

/* --- Commands --- */
void    sa(t_stack_node **a, bool print_mode);
void    sb(t_stack_node **b, bool print_mode);
void    ss(t_stack_node **a, t_stack_node **b, bool print_mode);
void    ra(t_stack_node **a, bool print_mode);
void    rb(t_stack_node **b, bool print_mode);
void    rr(t_stack_node **a, t_stack_node **b, bool print_mode);
void    rra(t_stack_node **a, bool print_mode);
void    rrb(t_stack_node **b, bool print_mode);
void    rrr(t_stack_node **a, t_stack_node **b, bool print_mode);
void    pa(t_stack_node **a, t_stack_node **b, bool print_mode);
void    pb(t_stack_node **a, t_stack_node **b, bool print_mode);

/* --- Algorithm --- */


#endif