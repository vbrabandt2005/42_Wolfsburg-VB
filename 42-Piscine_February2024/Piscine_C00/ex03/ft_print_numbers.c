/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:36:25 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:41:36 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(void)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(i + 48);
		i++;
	}
}

/*
int	main(void)
{
	ft_print_numbers();
	return(0);
}
*/