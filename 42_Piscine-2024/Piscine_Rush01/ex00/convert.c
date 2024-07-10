/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 22:25:48 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/10 03:51:03 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	*char_to_nums(char *str)
{
	int	i;
	int	j;
	int	*nums;

	nums = malloc(16 * 4);
	if (nums == NULL)
		print_error();
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= '1' && str[i] <= '4')
		{
			nums[j] = str[i] - '0';
			j++;
		}
		i++;
	}
	return (nums);
}

void	free_nums(int *nums)
{
	free(nums);
}

void	set_arg(int **map, int *array)
{
	int	i;
	int	j;
	int	num_counter;

	i = 0;
	j = 0;
	num_counter = 0;
	while (i < 4 && num_counter < 16)
	{
		map[i][j] = array[num_counter];
		num_counter++;
		j++;
		if (j == 4)
		{
			j = 0;
			i++;
		}
	}
	free_nums(array);
}
