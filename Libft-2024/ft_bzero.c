/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:26:17 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/11 14:21:53 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>


void ft_bzero(void *s, size_t n)
{
    unsigned char *str = (unsigned char *)s;
    
    while (n--)
        *str++ = 0;
}

// int main(void) {
//     char str1[100] = "Capybaras.";
//     char str2[100] = "This is a test string.";

//     printf("Original strings:\n");
//     printf("str1: %s\n", str1);
//     printf("str2: %s\n", str2);

//     // Test ft_bzero
//     ft_bzero(str1, 10);  // Zero out the first 20 bytes of str1

//     printf("\nAfter ft_bzero(str1, 20):\n");
//     printf("str1: %s\n", str1);

//     // Test real bzero
//     bzero(str2, 20);  // Zero out the first 20 bytes of str2 using real bzero

//     printf("\nAfter bzero(str2, 20):\n");
//     printf("str2: %s\n", str2);

//     return (0);
// }
