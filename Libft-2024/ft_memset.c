/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:43:04 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/11 12:21:51 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset (void *dest, int val, size_t len)
{
	unsigned char	*ptr = dest;
	
	while (len-- > 0)
		*ptr++ = val;
	return dest;
}

// Might be broken
