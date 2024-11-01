/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:40:31 by bjbogisc          #+#    #+#             */
/*   Updated: 2024/11/01 12:00:50 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_input(t_stack_node **a, int argc, char **argv)
{
	char	**split_argv;
	bool	is_split;

	split_argv = NULL;
	is_split = false;
	if (argc == 2)
	{
		split_argv = split(argv[1], ' ');
		if (!split_argv)
			exit(1);
		is_split = true;
		init_stack_a(a, split_argv, is_split);
		free_split(split_argv);
	}
	else
		init_stack_a(a, argv + 1, is_split);

}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	handle_input(&a, argc, argv);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
