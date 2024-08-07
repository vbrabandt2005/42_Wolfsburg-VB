/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 16:35:30 by vbraband          #+#    #+#             */
/*   Updated: 2024/07/10 03:39:33 by vbrabandt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	sqt;
	int	temp;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	sqt = nb / 2;
	temp = 0;
	while (sqt != temp)
	{
		temp = sqt;
		sqt = (nb / temp + temp) / 2;
	}
	if (sqt * sqt == nb)
		return (sqt);
	else
		return (0);
}
