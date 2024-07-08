/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf-char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 14:12:21 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/08 15:10:44 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}
// %c - print a single character

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_print_str("(null)");
		return (1);
	}
	while (str[i])
	{
		ft_print_char(str[i]);
		i++;
	}
	return (i);
}
// %s - print a string

int	ft_put_hex(size_t n, char *hex)
{
	int		i;

	i = 0;
	if (n / 16)
		i += ft_put_hex(n / 16, hex);
	i += ft_printchar(hex[n % 16]);
	return (i);
}
// %x - print a number in hexadecimal

int	ft_print_pointer(void *nbr)
{
	int	i;

	if (nbr == NULL)
		return ("(nil)");
	i += ft_print_str("0x");
	ft_print_hex((unsigned int)nbr);
}
// %p - print a pointer address in hexadecimal