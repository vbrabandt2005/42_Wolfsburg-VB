/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:09:50 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/08 15:10:22 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_percent(void)
{
	ft_print_char('%');
	return (1);
}
// %% - literal percent sign

int	ft_print_int(int nbr)
{
	ft_print_nbr(nbr);
	return (1);
}
// %i - print a number (integer)

void	ft_print_nbr(int nbr)
{
	if (nbr < 0)
	{
		ft_print_char('-');
		nbr = -nbr;
	}
	if (nbr >= 10)
	{
		ft_print_nbr(nbr / 10);
		ft_print_nbr(nbr % 10);
	}
	else
		ft_print_char(nbr + '0');
}
// %d - print a number (decimal)

void	ft_print_unsigned(unsigned int nbr)
{
	if (nbr >= 10)
	{
		ft_print_unsigned(nbr / 10);
		ft_print_unsigned(nbr % 10);
	}
	else
		ft_print_char(nbr + '0');
}
// %u - print an unsigned number
