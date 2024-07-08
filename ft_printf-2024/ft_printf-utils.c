/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:12:21 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/05 15:41:51 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// %c - print a single character
void	ft_print_char(char c)
{
	write(1, &c, 1);
}

// %s - print a string
void	ft_print_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
}
// %i - print a number
void	ft_print_int(int nbr)
{
	ft_print_nbr(nbr);
}

// %d - print a number (decimal)
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
// %u - print an unsigned number
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

// %x - print a number in hexadecimal (lowercase & base 16)
void	ft_print_hex(unsigned int nbr)
{
	if (nbr >= 16)
	{
		ft_print_hex(nbr / 16);
		ft_print_hex(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_print_char(nbr + '0');
		else
			ft_print_char(nbr - 10 + 'a');
	}
}

// could probably combine the two functions

// %X - print a number in hexadecimal (uppercase & base 16)
void	ft_print_hex_upper(unsigned int nbr)
{
	if (nbr >= 16)
	{
		ft_print_hex_upper(nbr / 16);
		ft_print_hex_upper(nbr % 16);
	}
	else
	{
		if (nbr < 10)
			ft_print_char(nbr + '0');
		else
			ft_print_char(nbr - 10 + 'A');
	}
}

// %p - print a pointer address in hexadecimal 
void	ft_print_pointer(void *ptr)
{
	ft_print_str("0x");
	ft_print_hex((unsigned int)ptr);
}

// %%
void	ft_print_percent(void)
{
	ft_print_char('%');
}

