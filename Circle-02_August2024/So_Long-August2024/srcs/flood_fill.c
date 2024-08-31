/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:36:49 by vbraband          #+#    #+#             */
/*   Updated: 2024/08/28 17:36:50 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
This is the core of the floodfill algorithm :
	- first, check that the current grid localization exists within map
	- then keep count of exit and items, so as to check they can all be reached
	- finally, check all 4 directions from current 'square', recursively
		-> if next square is not a wall, replace character (filler) with 'F'
*/

void	flooder(t_game *game, t_map size, t_character charpos, char filler)
{
	if ((charpos.y_char < 0 || charpos.y_char >= size.y_map || \
		charpos.x_char < 0 || charpos.x_char >= size.x_map) || \
		((game->map.map[charpos.y_char][charpos.x_char] != filler && \
		game->map.map[charpos.y_char][charpos.x_char] != 'C' && \
		game->map.map[charpos.y_char][charpos.x_char] != 'E')))
		return ;
	if (game->map.map[charpos.y_char][charpos.x_char] == 'C' || \
		game->map.map[charpos.y_char][charpos.x_char] == 'E')
	{
		if (game->map.map[charpos.y_char][charpos.x_char] == 'C')
			game->map.item_count++;
		if (game->map.map[charpos.y_char][charpos.x_char] == 'E')
			game->map.exit_count++;
		game->map.map[charpos.y_char][charpos.x_char] = filler;
	}
	game->map.map[charpos.y_char][charpos.x_char] = 'F';
	flooder(game, size, (t_character){.x_char = charpos.x_char - 1, \
		.y_char = charpos.y_char}, filler);
	flooder(game, size, (t_character){.x_char = charpos.x_char + 1, \
		.y_char = charpos.y_char}, filler);
	flooder(game, size, (t_character){.x_char = charpos.x_char, \
		.y_char = charpos.y_char - 1}, filler);
	flooder(game, size, (t_character){.x_char = charpos.x_char, \
		.y_char = charpos.y_char + 1}, filler);
}

/*
This function wil be a 'dam' to canalize the recursive part of the flood fill
*/

void	dam(t_game *game, t_map size, t_character charpos)
{
	if (game->map.map[charpos.y_char][charpos.x_char] == 'P')
		game->map.map[charpos.y_char][charpos.x_char] = '0';
	if (game->map.map[charpos.y_char][charpos.x_char] == 'C')
		game->map.map[charpos.y_char][charpos.x_char] = '0';
	flooder(game, size, charpos, game->map.map[charpos.y_char][charpos.x_char]);
}

/*
This function is where the reachability of exit/items is checked
*/

int	caught_em_all(t_game *game, int itemy, int exity)
{
	if (itemy != game->map.item_count)
	{
		ft_error(game, "You can't catch'em all ...");
		return (0);
	}
	if (exity != game->map.exit_count)
	{
		ft_error(game, "Were you led here by Iji, Wolf?\n \
		Ce tombeau sera votre tombeau !");
		return (0);
	}
	return (1);
}

/*
This function saves the # of exit and items in variables,
	then re-initilizes the values in structure,
	starts the flood-fill pathfinding
	verifies that the exit and all items and reachable

to check (print) the result of floodfill :
	for (int i = 0; i < size.y; ++i)  // TO BE REMOVED
			ft_printf("%s\n", game->map.map[i]);
*/

int	flood_it(t_game *game)
{
	t_character	charpos;
	t_map		size;
	int			itemy;
	int			exity;

	itemy = game->map.item_count;
	exity = game->map.exit_count;
	game->map.item_count = 0;
	game->map.exit_count = 0;
	charpos = (t_character){.x_char = game->player.x_char, \
		.y_char = game->player.y_char};
	size = (t_map){.x_map = game->map.line_size, .y_map = game->map.col_size};
	dam(game, size, charpos);
	if (!caught_em_all(game, itemy, exity))
		return (0);
	return (1);
}
