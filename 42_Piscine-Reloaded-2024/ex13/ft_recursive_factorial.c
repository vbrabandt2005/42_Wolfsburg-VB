/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:18:23 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/05 13:55:36 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
		return (nb * ft_recursive_factorial(nb - 1));
}

// #include<stdio.h>

// int main()  
// {  
//   int number = 10;  
//   long fact;  

//   fact = ft_recursive_factorial(number);  
//   printf("Factorial of %d is %ld\n", number, fact);  
//   return 0;  
// }
