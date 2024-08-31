/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_tiles_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 17:37:25 by vbraband          #+#    #+#             */
/*   Updated: 2024/08/28 17:37:26 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_tile_hero(t_game *game)
{
	game->hero.x_tile = 0;
	game->hero.y_tile = 0;
	game->hero.img = "";
	game->hero.addr = "";
	game->hero.bits_per_pixel = 0;
	game->hero.size_line = 0;
	game->hero.endian = 0;
	return (1);
}

int	init_tile_item(t_game *game)
{
	game->item.x_tile = 0;
	game->item.y_tile = 0;
	game->item.img = "";
	game->item.addr = "";
	game->item.bits_per_pixel = 0;
	game->item.size_line = 0;
	game->item.endian = 0;
	return (1);
}

int	init_tile_exit(t_game *game)
{
	game->exit.x_tile = 0;
	game->exit.y_tile = 0;
	game->exit.img = "";
	game->exit.addr = "";
	game->exit.bits_per_pixel = 0;
	game->exit.size_line = 0;
	game->exit.endian = 0;
	return (1);
}

int	init_tile_floor(t_game *game)
{
	game->floor.x_tile = 0;
	game->floor.y_tile = 0;
	game->floor.img = "";
	game->floor.addr = "";
	game->floor.bits_per_pixel = 0;
	game->floor.size_line = 0;
	game->floor.endian = 0;
	return (1);
}

int	init_tile_wall(t_game *game)
{
	game->wall.x_tile = 0;
	game->wall.y_tile = 0;
	game->wall.img = "";
	game->wall.addr = "";
	game->wall.bits_per_pixel = 0;
	game->wall.size_line = 0;
	game->wall.endian = 0;
	return (1);
}
