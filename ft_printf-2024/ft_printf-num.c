/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:09:50 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/09 11:12:15 by vbrabandt        ###   ########.fr       */
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
	int	i;

	i = 0;
	if (nbr < 0)
	{
		i += ft_printchar('-');
		nbr = -nbr;
	}
	if (nbr / 10)
		i += ft_printnum(nbr / 10);
	i += ft_printchar((nbr % 10) + '0');
	return (i);
}
// %d - print a number (decimal)

void	ft_print_unsigned(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr / 10)
		i += ft_printunum(nbr / 10);
	i += ft_printchar((nbr % 10) + '0');
	return (i);
}
// %u - print an unsigned number
