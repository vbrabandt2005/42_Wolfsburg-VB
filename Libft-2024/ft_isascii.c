/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:54:47 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/10 12:15:46 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isascii(int c)
{
	if (((c >= 0 && c <= 127)))
	{
		return (1);
	}
    else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char c = 'c';
// 	printf("%d\n", ft_isascii(c));
// }
