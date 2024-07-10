/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:44:29 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:44:19 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	result;
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
		{
			result = s1[i] - s2[i];
			return (result);
		}
		i++;
	}
	while (i < n)
		i++;
	return (0);
}

/*
int main()
{
	char *s1 = "Capybara";
	char *s2 = "Raccoons";
	unsigned int n = 5; // Choose a desired comparison length

	int result = ft_strncmp(s1, s2, n);

	printf("ft_strncmp(\"%s\", \"%s\", %u): %d\n", s1, s2, n, result);

	return 0;
}
*/