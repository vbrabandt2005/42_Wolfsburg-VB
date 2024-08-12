/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:30:42 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:43:44 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	unsigned int	a;

	a = 0;
	while (str[a] != '\0')
	{
		if (!((str [a] >= 'A' && str[a] <= 'Z')
				|| (str[a] >= 'a' && str[a] <= 'z')))
		{
			return (0);
		}
		a++;
	}
	return (1);
}
