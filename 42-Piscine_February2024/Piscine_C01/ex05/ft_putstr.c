/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:11:26 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:42:54 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	thing;

	thing = 0;
	while (str[thing])
		thing++;
	write(1, str, thing);
}

/*
int main(void)
{
	ft_putstr("Capybaras are the cutest animals in the world!!");
}
*/