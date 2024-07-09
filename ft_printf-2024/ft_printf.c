/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 17:31:05 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/09 11:47:08 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_speci(const char *s, int i, va_list args)
{
	int output;

    output = 0;
	if (s[i] == 'c')
		output += ft_print_char(va_arg(args, int));
    else if (s[i] == 'i')
        output += ft_print_int(va_arg(args, int));
	else if (s[i] == 's')
		output += ft_print_str(va_arg(args, char *));
	else if (s[i] == 'x')
		output += ft_print_hex(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (s[i] == 'X')
		output += ft_print_hex(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (s[i] == 'p')
		output += ft_print_ptr(va_arg(args, void *));
	else if (s[i] == 'd' || s[i] == 'i')
		output += ft_printnum(va_arg(args, int));
	else if (s[i] == 'u')
		output += ft_printunum(va_arg(args, unsigned int));
	else if (s[i] == '%')
		output += ft_print_percent();
	return (output);
}

int	ft_printf(const char *s, ...)
{
    va_list	args;
    int		i;
    int		output;

    i = 0;
    output = 0;
    va_start(args, s);
    while (s[i])
    {
        if (s[i] == '%')
        {
            i++;
            output += get_speci(s, i, args);
        }
        else
        {
            ft_putchar(s[i]);
            output++;
        }
        i++;
    }
    va_end(args);
    return (output);
}