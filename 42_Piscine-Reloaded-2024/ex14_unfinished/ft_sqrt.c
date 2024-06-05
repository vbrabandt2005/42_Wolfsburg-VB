/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:35:30 by vbraband          #+#    #+#             */
/*   Updated: 2024/06/05 12:38:55 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int	sqt;
	int	temp;

	if (nb < 0)
	{
		return (-1);
	}
	if (nb == 0 || nb == 1)
	{
		return (nb);
	}

	sqt = nb / 2;
	temp = 0;

	while (sqt != temp)
	{
		temp = sqt;
		sqt = (nb / temp + temp) / 2;
	}
	if (sqt * sqt == nb)
	{
		return (sqt);
	}
	else
	{
		return (0);
	}
}


int main(void)
{
  int test_cases[] = {0, 1, 4, 16, 25, -1};
  int expected_results[] = {0, 1, 2, 4, 5, -1}; // Adjust expected results for negative inputs

  int i;

  for (i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
    int result = ft_sqrt(test_cases[i]);
    printf("ft_sqrt(%d) = %d (expected: %d)\n", test_cases[i], result, expected_results[i]);

    // Check if the result matches the expected value
    if (result != expected_results[i]) {
      printf("Error: Incorrect result for input %d\n", test_cases[i]);
    }
  }

  return (0);
}