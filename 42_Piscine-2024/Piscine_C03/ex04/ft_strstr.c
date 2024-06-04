/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:34:07 by vbraband          #+#    #+#             */
/*   Updated: 2024/02/14 12:58:33 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		j = 0;
		while (str[i + j] != '\0' && str[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (&str[i]);
			++j;
		}
		++i;
	}
	return (0);
}

/*
#include <stdio.h>

char *ft_strstr(char *str, char *to_find);

int main() {
    char str[] = "Capybara is the cutest animal in the world";
    char to_find[] = "Capybara";

    char *result = ft_strstr(str, to_find);

    if (result) {
        printf("Found \"%s\" at: %s\n", to_find, result);
    } else {
        printf("Didn't find \"%s\"\n", to_find);
    }

    return 0;
}
*/