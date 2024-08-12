/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 09:48:33 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:44:05 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcapitalize(char *str)
{
	unsigned int	i;
	char			c;
	int				new;

	i = 0;
	new = 1;
	while (str[i] != '\0')
	{
		c = str[i];
		if (new == 1 && c >= 'a' && c <= 'z')
			str[i] -= 32;
		else if (new == 0 && c >= 'A' && c <= 'Z')
			str[i] += 32;
		if (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z')
			new = 1;
		else
			new = 0;
		i++;
	}
	return (str);
}

/*
#include <stdio.h>

int main(void)
{
	char str1[] = "capybara are the cutest animal in the world";
	printf(("String: %s"), ft_strcapitalize(str1));
}
*/