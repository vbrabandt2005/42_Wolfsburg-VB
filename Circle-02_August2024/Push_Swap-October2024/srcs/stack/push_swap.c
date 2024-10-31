/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:40:31 by bjbogisc          #+#    #+#             */
/*   Updated: 2024/10/31 16:45:30 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	handle_input(t_stack_node **a, int argc, char **argv)
{
	char	**split_argv;
	int		i;

	split_argv = NULL;
	if (argc == 2)
	{
		split_argv = split(argv[1], ' ');
		if (!split_argv)
			exit(1);
		init_stack_a(a, split_argv);
	}
	else
		init_stack_a(a, argv + 1);
	if (split_argv)
	{
		i = 0;
		while (split_argv[i])
		{
			free(split_argv[i]);
			i++;
		}
		free(split_argv);
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
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
