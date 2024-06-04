/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:57:54 by vbraband          #+#    #+#             */
/*   Updated: 2024/02/07 15:25:44 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str)
{
	unsigned int	sniff_the_uppercase;
	unsigned int	i;

	sniff_the_uppercase = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
#include <stdio.h>

int main(void)
{
	char str1[] = "CAPYBARA";
	char str2[] = "capybara";
	char str3[] = "";

	printf("String '%s': %d\n", str1, ft_str_is_uppercase(str1));
	printf("String '%s': %d\n", str2, ft_str_is_uppercase(str2));
	printf("String '%s': %d\n", str3, ft_str_is_uppercase(str3));
	
	return (0);
}
*/