/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:51:39 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:38:57 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i;
	int		j;
	char	*copy;

	i = 0;
	j = 0;
	if (src == NULL)
		return (NULL);
	while (src[i])
		i++;
	copy = malloc(i + 1);
	while (src[j])
	{
		copy[j] = src[j];
		j++;
	}
	copy[i] = '\0';
	if (!copy)
		return (NULL);
	return (copy);
}
