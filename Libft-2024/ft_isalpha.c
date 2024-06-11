/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:05:32 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/10 11:41:41 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalpha(int c)
{
	if (((c >= 'A' && c <= 'Z')
			|| (c >= 'a' && c <= 'z')))
	{
		return (1);
	}
	else
		return (0);
}

// #include <stdio.h>

// int main(void)
// {
// 	char c = '"';
// 	printf("%d\n", ft_isalpha(c));

// 	return (0);
// }
