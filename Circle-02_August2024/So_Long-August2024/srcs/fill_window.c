/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:55:08 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/03 14:32:00 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flooder(t_game *game, t_map size, t_character charpos, char filler)
{
	if ((charpos.y_char < 0 || charpos.y_char >= size.y_map
			|| charpos.x_char < 0 || charpos.x_char >= size.x_map)
		|| ((game->map.map[charpos.y_char][charpos.x_char] != filler
			&& game->map.map[charpos.y_char][charpos.x_char] != 'C'
		&& game->map.map[charpos.y_char][charpos.x_char] != 'E'
				&& game->map.map[charpos.y_char][charpos.x_char] != 'G')))
		return ;
	if (game->map.map[charpos.y_char][charpos.x_char] == 'C'
		|| game->map.map[charpos.y_char][charpos.x_char] == 'E')
	{
		if (game->map.map[charpos.y_char][charpos.x_char] == 'C')
			game->map.item_count++;
		if (game->map.map[charpos.y_char][charpos.x_char] == 'E')
			game->map.exit_count++;
		game->map.map[charpos.y_char][charpos.x_char] = filler;
	}
	else if (game->map.map[charpos.y_char][charpos.x_char] == 'G')
		game->map.map[charpos.y_char][charpos.x_char] = 'G';
	else
		game->map.map[charpos.y_char][charpos.x_char] = 'F';
	game->map.map[charpos.y_char][charpos.x_char] = 'F';
	flooder(game, size, (t_character){.x_char = charpos.x_char - 1,
		.y_char = charpos.y_char}, filler);
	flooder(game, size, (t_character){.x_char = charpos.x_char + 1,
		.y_char = charpos.y_char}, filler);
	flooder(game, size, (t_character){.x_char = charpos.x_char,
		.y_char = charpos.y_char - 1}, filler);
	flooder(game, size, (t_character){.x_char = charpos.x_char,
		.y_char = charpos.y_char + 1}, filler);
}

void	dam(t_game *game, t_map size, t_character charpos)
{
	if (game->map.map[charpos.y_char][charpos.x_char] == 'P')
		game->map.map[charpos.y_char][charpos.x_char] = '0';
	if (game->map.map[charpos.y_char][charpos.x_char] == 'C')
		game->map.map[charpos.y_char][charpos.x_char] = '0';
	flooder(game, size, charpos, game->map.map[charpos.y_char][charpos.x_char]);
}

int	check_collect(t_game *game, int item, int exit)
{
	if (item != game->map.item_count)
	{
		ft_error(game, "No Collectables in reach");
		return (0);
	}
	if (exit != game->map.exit_count)
	{
		ft_error(game, "No Exit in reach");
		return (0);
	}
	return (1);
}

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
	charpos = (t_character){.x_char = game->player.x_char,
		.y_char = game->player.y_char};
	size = (t_map){.x_map = game->map.line_size, .y_map = game->map.col_size};
	dam(game, size, charpos);
	if (!check_collect(game, itemy, exity))
		return (0);
	return (1);
}

int	init_window(t_game *game)
{
	game->window.mlx_ptr = 0;
	game->window.win_ptr = 0;
	game->window.img = "";
	game->window.addr = "";
	game->window.bpp = 0;
	game->window.size_line = 0;
	game->window.endian = 0;
	game->window.x_win = 0;
	game->window.y_win = 0;
	return (1);
}