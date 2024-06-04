/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:06:08 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/04 15:17:01 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

// #include <stdio.h>

// int main(void)
// {
// 	int a;
// 	int b;
// 	int mod;
// 	int div;

// 	a = 5;
// 	b = 2;

// 	ft_div_mod(a, b, &div, &mod);

// 	printf("a : %d, b : %d, div : %d, mod : %d\n", a, b, div, mod);
// }