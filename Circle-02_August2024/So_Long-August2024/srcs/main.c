/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 13:42:21 by vbraband          #+#    #+#             */
/*   Updated: 2024/08/21 13:42:23 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
	{
		ft_nomap(game, "Malloc error.");
		game_under();
	}
	if (argc != 2)
	{
		ft_nomap(game, "Syntax error detected !\n\
		Please use as :\n\t\t\t./so_long <map.ber>\n");
		game_under();
		return (2);
	}
	if (init_game_structs(game) && valid_map(argv[1], game))
		start_game(game);
	return (0);
}
