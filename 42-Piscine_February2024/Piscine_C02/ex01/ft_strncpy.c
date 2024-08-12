/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:24:47 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:43:38 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>

int main() 
{
    char source[] = "Capybaras are the cutest animal on earth";
    char destination[100];  // Ensure enough space for the copied string

    ft_strncpy(destination, source, 100);  // Call the function to copy

    printf("Destination string: %s\n", destination);  // Print the result

    return 0;
}
*/