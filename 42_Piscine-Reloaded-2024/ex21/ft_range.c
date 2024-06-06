/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:39:13 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/06 10:55:51 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*result;

	if (min >= max)
		return (0);
	i = max - min;
	result = (int *)malloc(sizeof(int) * (i));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (max > min)
	{
		result[i] = min;
		min++;
		i++;
	}
	return (result);
}

// #include <stdio.h>

// int main(void)
// {
// 	int	min;
// 	int	max;
// 	int	*tab;
// 	int	i = 0;
// 	int	size;

// 	min = 1;
// 	max = 1000;
// 	size = max - min;
// 	tab = ft_range(min, max);
// 	while(i < size)
// 	{
// 		printf("%d, ", tab[i]);
// 		i++;
// 	}
// }