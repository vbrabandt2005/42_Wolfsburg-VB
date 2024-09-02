/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:58:51 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/02 14:08:01 by vbraband         ###   ########.fr       */
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
		game_over();
	}
	if (argc != 2)
	{
		ft_nomap(game, "Please do: ./so_long maps/<map.ber>");
		free(game); // Free game before exiting
		game_over();
		return (2);
	}
	if (init_game_structs(game) && valid_map(argv[1], game))
		start_game(game);
	free(game);
	return (0);
}
