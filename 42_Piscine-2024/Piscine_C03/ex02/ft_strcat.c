/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:52:11 by vbrabandt         #+#    #+#             */
/*   Updated: 2024/02/14 12:25:56 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	i;

	i = 0;
	while (dest[i])
		i++;
	while (*src)
		dest[i++] = *src++;
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

char *ft_strcat(char *dest, char *src);

int main() {
    char dest[100] = "Capybaras are ";
    char src[] = "CUTE!";

    printf("Original destination string: %s\n", dest);

    // Append src to dest
    char *modified_dest = ft_strcat(dest, src);

    printf("Modified destination string: %s\n", modified_dest);

    return 0;
}
*/