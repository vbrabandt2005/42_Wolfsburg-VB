/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:11:26 by vbraband          #+#    #+#             */
/*   Updated: 2024/02/05 14:06:32 by vbraband         ###   ########.fr       */
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