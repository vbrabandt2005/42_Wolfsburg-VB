/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 09:38:22 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/05 17:27:00 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// void	ft_putchar(char c)
// {
// 	write (1, &c, 1);
// }

void	ft_print_alphabet(void)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		ft_putchar(i + 97);
		i++;
	}
}

// int	main(void)
// {
// 	ft_print_alphabet();
// 	return	0;
// }