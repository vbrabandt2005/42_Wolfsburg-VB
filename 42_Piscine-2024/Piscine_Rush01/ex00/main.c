/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:04:34 by hzakharc          #+#    #+#             */
/*   Updated: 2024/02/18 14:21:11 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		print_error();
	}
	if (checkarg(argv[1]) == 0)
	{
		print_error();
	}
	else
	{
		write(1, "Good\n", 5);
	}
	return (0);
}
