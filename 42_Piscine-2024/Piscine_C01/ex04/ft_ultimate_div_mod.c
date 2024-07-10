/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:52:46 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:48:28 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	div;
	int	mod;

	div = *a;
	mod = *b;
	*a = div / mod;
	*b = div % mod;
}

#include <stdio.h>

// int main()
// {
// 	int a;
// 	int b;
	
// 	a = 5;
// 	b = 2;

// 	printf("a : %d, b : %d\n", a, b);

// 	ft_ultimate_div_mod(&a, &b);

// 	printf("a : %d, b : %d\n", a, b);
// }
