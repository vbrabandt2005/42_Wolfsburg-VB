/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:37:19 by vbraband          #+#    #+#             */
/*   Updated: 2024/08/28 17:37:20 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_map(t_game *game)
{
	game->map.item_count = 0;
	game->map.exit_count = 0;
	game->map.hero_count = 0;
	game->map.elder_index = 0;
	game->map.col_size = 0;
	game->map.line_size = 0;
	game->map.x_map = 0;
	game->map.y_map = 0;
	return (1);
}

int	init_tile(t_game *game)
{
	if (!init_tile_hero(game))
		return (0);
	if (!init_tile_item(game))
		return (0);
	if (!init_tile_exit(game))
		return (0);
	if (!init_tile_floor(game))
		return (0);
	if (!init_tile_wall(game))
		return (0);
	return (1);
}

int	init_char(t_game *game)
{
	game->player.x_char = 0;
	game->player.y_char = 0;
	game->player.charac = "player";
	game->player.move_count = 0;
	game->player.inventory = 0;
	return (1);
}

int	init_show(t_game *game)
{
	game->show.mlx_ptr = 0;
	game->show.win_ptr = 0;
	game->show.img = "";
	game->show.addr = "";
	game->show.bits_per_pixel = 0;
	game->show.size_line = 0;
	game->show.endian = 0;
	game->show.x_win = 0;
	game->show.y_win = 0;
	return (1);
}

int	init_game_structs(t_game *game)
{
	if (!init_map(game))
		return (0);
	if (!init_char(game))
		return (0);
	if (!init_tile(game))
		return (0);
	if (!init_show(game))
		return (0);
	return (1);
}
