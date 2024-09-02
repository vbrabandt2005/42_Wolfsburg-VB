/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:54:27 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/02 17:58:51 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_pos(int i, int j, t_game *game)
{
	game->player.x_char = j;
	game->player.y_char = i;
}

void	exit_pos(int i, int j, t_game *game)
{
	game->exit.x_tile = j;
	game->exit.y_tile = i;
}

t_game	*elem_pos(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.col_size - 1)
	{
		j = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (game->map.map[i][j] == 'P')
				player_pos(i, j, game);
			if (game->map.map[i][j] == 'E')
				exit_pos(i, j, game);
			j++;
		}
		i++;
	}
	return (game);
}

int	mission_ready(t_game *game)
{
	if (game->map.hero_count == 0)
	{
		ft_error(game, "Can't start mission! Capy is missing");
		return (0);
	}
	if (game->map.exit_count == 0)
	{
		ft_error(game, "Can't start mission! There is no Exit");
		return (0);
	}
	if (game->map.item_count == 0)
	{
		ft_error(game, "Can't start mission! There are no keys to grant Capy's freedom");
		return (0);
	}
	game = elem_pos(game);
	return (1);
}
