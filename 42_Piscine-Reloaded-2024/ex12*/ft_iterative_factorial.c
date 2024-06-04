/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:15:03 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/04 18:18:10 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_iterative_factorial(int nb)
{
    unsigned long long result;
    unsigned int i;    
    
    result = 1;
    if (nb < 0)
    {
        return (0);
    }
    while (nb > 1)
    {
        result *= nb;
        nb--;
    }
    return (result);
}