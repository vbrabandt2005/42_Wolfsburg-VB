/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:02:06 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/10 12:16:52 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalnum(int c)
{
	if (((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || \
			(c >= '0' && c <= '9')))
	{
		return (1);
	}
	else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char c = '9';
// 	printf("%d\n", ft_isalnum(c));

// 	return (0);
// }
