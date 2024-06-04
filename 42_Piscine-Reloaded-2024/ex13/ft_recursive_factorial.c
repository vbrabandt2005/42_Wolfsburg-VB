/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 15:18:23 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/04 16:58:08 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
		return (nb * ft_iterative_factorial(nb - 1));
}

// #include<stdio.h>

// int main()  
// {  
//   int number = 10;  
//   long fact;  

//   fact = ft_iterative_factorial(number);  
//   printf("Factorial of %d is %ld\n", number, fact);  
//   return 0;  
// }
