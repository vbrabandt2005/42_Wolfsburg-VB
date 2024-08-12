/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 21:25:03 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:44:17 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	result;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main() {
    char *s1 = "Hello";
    char *s2 = "World";
    int result;    result = ft_strcmp(s1, s2);
    printf("Result: '%s' and '%s': %d\n", s1, s2, result);    s1 = "Hello";
    s2 = "Hello";
    result = ft_strcmp(s1, s2);
    printf("Result: '%s' and '%s': %d\n", s1, s2, result);    s1 = "world";
    s2 = "World";
    result = ft_strcmp(s1, s2);
    printf("Result: '%s' and '%s': %d\n", s1, s2, result);    s1 = "apple";
    s2 = "banana";
    result = ft_strcmp(s1, s2);
    printf("Result: '%s' and '%s': %d\n", s1, s2, result);    return  0;
}
*/