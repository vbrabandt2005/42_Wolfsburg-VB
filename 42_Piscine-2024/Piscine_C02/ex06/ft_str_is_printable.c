/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 00:00:40 by vbraband          #+#    #+#             */
/*   Updated: 2024/02/07 15:36:36 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	unsigned int	sniff_the_printable;
	unsigned int	i;

	sniff_the_printable = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] > 31 && str[i] < 127))
		{
			sniff_the_printable = 0;
		}
		i++;
	}
	return (sniff_the_printable);
}

/*
#include <stdio.h>

int main(void)
{
	char str1[] = "CAPYBARA + Humans = love :)";
	char str2[] = "	";
	char str3[] = "";

	printf("String '%s': %d\n", str1, ft_str_is_printable(str1));
	printf("String '%s': %d\n", str2, ft_str_is_printable(str2));
	printf("String '%s': %d\n", str3, ft_str_is_printable(str3));

	return (0);
}
*/