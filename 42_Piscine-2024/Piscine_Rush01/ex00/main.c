/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbrabandt <vbrabandt@proton.me>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:04:34 by hzakharc          #+#    #+#             */
/*   Updated: 2024/07/10 03:51:08 by vbrabandt        ###   ########.fr       */
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
