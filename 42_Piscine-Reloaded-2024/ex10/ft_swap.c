/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 14:51:26 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/04 14:57:56 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

// #include <stdio.h>

// int main(void)
// {
// 	int		a;
// 	int		b;
// 	int		*ptra;
// 	int		*ptrb;

// 	a = 1;
// 	b = 2;

// 	ptra = &a;
// 	ptrb = &b;

// 	ft_swap(ptra, ptrb);

// 	printf("a : %d, b : %d\n", a, b);
// }