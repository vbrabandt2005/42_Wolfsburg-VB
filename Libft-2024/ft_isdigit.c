/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:54:50 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/10 12:21:16 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isdigit(int c)
{
	if (((c >= '0' && c <= '9')))
	{
		return (1);
	}
    else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char c = '6';
// 	printf("%d\n", ft_isdigit(c));
// }