/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 12:36:40 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:44:34 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dst_size;
	unsigned int	src_size;
	unsigned int	result;

	dst_size = 0;
	while (dest[dst_size] != '\0')
		dst_size++;
	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	result = src_size;
	if (size <= dst_size)
		result += size;
	else
		result += dst_size;
	src_size = 0;
	while (src[src_size] != '\0' && dst_size + 1 < size)
	{
		dest[dst_size] = src[src_size];
		dst_size++;
		src_size++;
	}
	dest[dst_size] = '\0';
	return (result);
}

/*
#include <stdio.h>

unsigned int ft_strlcat(char *dest, char *src, unsigned int size);

int main() {
    char dest[50] = "Capybara are ";
    char src[] = "CUTE";
    unsigned int result;

    result = ft_strlcat(dest, src, sizeof(dest));

    printf("Original destination string: %s\n", dest);
    printf("Modified destination string: %s\n", dest);
    printf("Total combined length (including null terminator): %u\n", result);

    return 0;
}
*/