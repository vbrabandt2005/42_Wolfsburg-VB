/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 11:17:35 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/12 00:12:54 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static size_t	str_len(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, str_len(s));
		write(fd, '\n', 1);
	}
}

static size_t	str_len(char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

void	ft_putendl_fd(char *s, int fd)
{
	if (s)
	{
		write(fd, s, str_len(s));
		write(fd, '\n', 1);
	}
}