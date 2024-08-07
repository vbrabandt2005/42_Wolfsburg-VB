/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:54:54 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:43:49 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')))
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
	char str1[] = "capybara";
	char str2[] = "CAPYBARA";
	char str3[] = "";

	printf("String '%s': %d\n", str1, ft_str_is_lowercase(str1));
	printf("String '%s': %d\n", str2, ft_str_is_lowercase(str2));
	printf("String '%s': %d\n", str3, ft_str_is_lowercase(str3));
	
	return (0);
}
*/