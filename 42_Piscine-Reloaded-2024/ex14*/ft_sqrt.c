/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:35:30 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/04 17:19:08 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_sqrt(int nb)
{
    float   temp;
    float   sqt;    
    sqt = nb / 2;
    temp = 0;
    while (sqt != temp)
    {
        temp = sqt;
        sqt = (nb / temp + temp) / 2;
    }
    return (sqt);
}

int main(void)
{
    printf("%d", ft_sqrt(10));
}