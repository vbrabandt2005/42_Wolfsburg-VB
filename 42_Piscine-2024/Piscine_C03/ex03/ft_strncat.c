/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:28:00 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:44:27 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	j;
	unsigned int	i;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && j < nb)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int main() {
    char dest[100] = "Capybaras are ";
    char src[] = "CUTE!";

    printf("Original destination string: %s\n", dest);

    // Append src to dest
    char *modified_dest = ft_strncat(dest, src, 2);

    printf("Modified destination string: %s\n", modified_dest);

    return 0;
}
*/