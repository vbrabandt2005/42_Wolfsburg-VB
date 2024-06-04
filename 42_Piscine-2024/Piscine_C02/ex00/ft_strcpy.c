/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 10:01:43 by vbraband          #+#    #+#             */
/*   Updated: 2024/02/07 10:11:57 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
#include <stdio.h>

int main() 
{
    char source[] = "Capybaras are the cutest animal on earth";
    char destination[50];  // Ensure enough space for the copied string

    ft_strcpy(destination, source);  // Call the function to copy

    printf("Destination string: %s\n", destination);  // Print the result

    return 0;
}
*/