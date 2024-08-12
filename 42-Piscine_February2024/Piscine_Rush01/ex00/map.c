/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hzakharc <hzakharc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 18:52:00 by hzakharc          #+#    #+#             */
/*   Updated: 2024/02/11 09:58:00 by hzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	set_zero(int **array)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			array[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	**create_map(void)
{
	int	**array;
	int	i;

	array = (int **)malloc(4 * 8);
	if (array == NULL)
		print_error();
	i = 0;
	while (i < 4)
	{
		array[i] = malloc(4 * 4);
		i++;
		if (array[i] == NULL)
			print_error();
	}
	set_zero(array);
	return (array);
}

void	free_map(int **array)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
