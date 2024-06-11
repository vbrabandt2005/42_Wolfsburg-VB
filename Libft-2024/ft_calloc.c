/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:14:04 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/11 10:29:51 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>  // For malloc

void *ft_calloc(size_t nmemb, size_t size) {
    void *ptr;

    if (nmemb == 0 || size == 0) {
        return NULL;
    }

    // Handle potential overflow manually (avoiding SIZE_MAX)
    size_t total_size = nmemb * size;
    if (total_size / nmemb != size) {
        return NULL;  // Overflow occurred
    }

    ptr = malloc(total_size);
    if (ptr == NULL) {
        return NULL;
    }

    // Initialize the allocated memory to zero using a loop
    unsigned char *str = (unsigned char *)ptr;
    for (size_t i = 0; i < total_size; i++) {
        str[i] = 0;
    }

    return ptr;
}

// int main(void) {
//     int *arr1, *arr2;
//     int n = 5, size = sizeof(int);

//     printf("Testing ft_calloc:\n");
//     arr1 = (int *)ft_calloc(n, size);
//     if (arr1 == NULL) {
//         printf("ft_calloc failed!\n");
//         return (1);
//     }

//     // Check if memory is initialized to zero
//     for (int i = 0; i < n; i++) {
//         if (arr1[i] != 0) {
//             printf("ft_calloc: Memory not initialized to zero!\n");
//             free(arr1);  // Free memory before returning
//             return (1);
//         }
//     }
//     printf("ft_calloc: Memory allocated and initialized successfully.\n");

//     printf("\nTesting real calloc:\n");
//     arr2 = (int *)calloc(n, size);
//     if (arr2 == NULL) {
//         printf("calloc failed!\n");
//         return (1);
//     }

//     // No need to check initialization for real calloc (already guaranteed)

//     printf("calloc: Memory allocated successfully.\n");

//     // Free the allocated memory
//     free(arr1);
//     free(arr2);

//     return (0);
// }