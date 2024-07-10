/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 23:54:44 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:43:47 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str [i] >= '0' && str[i] <= '9')))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

// #include <stdio.h>

// int main(void)
// {
// 	char str1[] = "Hello world";
// 	char str2[] = "123";
// 	char str3[] = "";

// 	printf("String '%s': %d\n", str1, ft_str_is_numeric(str1));
// 	printf("String '%s': %d\n", str2, ft_str_is_numeric(str2));
// 	printf("String '%s': %d\n", str3, ft_str_is_numeric(str3));
// 	return (0);
// }