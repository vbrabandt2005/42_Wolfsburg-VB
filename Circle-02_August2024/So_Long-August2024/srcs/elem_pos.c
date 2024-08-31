/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elem_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:36:34 by vbraband          #+#    #+#             */
/*   Updated: 2024/08/28 17:36:35 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*The following function initialize values of struct:
	- s_character : player
	- s_tile : exit position
*/

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

/*
This function runs through the map, in order to 
identify the X/Y position of character and exit
Should I do that for items as well? (apparently not)
*/

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

/*
This function displays a message if there is no P or E or C
If several are missing, the 1st message only is displayed
*/

int	mission_ready(t_game *game)
{
	if (game->map.hero_count == 0)
	{
		ft_error(game, "Can't start mission!\n\tNobody volunteered");
		return (0);
	}
	if (game->map.exit_count == 0)
	{
		ft_error(game, "Can't start mission!\n\tThere's no way out");
		return (0);
	}
	if (game->map.item_count == 0)
	{
		ft_error(game, "Can't start mission!\n\tNo quest available");
		return (0);
	}
	game = elem_pos(game);
	return (1);
}
