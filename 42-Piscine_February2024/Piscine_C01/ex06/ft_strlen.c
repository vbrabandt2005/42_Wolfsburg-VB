/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 11:29:43 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:42:57 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	thing;

	thing = 0;
	while (str[thing])
		thing++;
	return (thing);
}

/*
#include <stdio.h>
#include <string.h>

int main(void)
{
	printf("%lu\n", strlen("capybara are beutiful"));
}
*/