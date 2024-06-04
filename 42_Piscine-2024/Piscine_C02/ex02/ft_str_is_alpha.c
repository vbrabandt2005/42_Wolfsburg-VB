/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 13:30:42 by vbraband          #+#    #+#             */
/*   Updated: 2024/02/10 09:34:50 by vbraband         ###   ########.fr       */
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
