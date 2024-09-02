/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tiles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:58:58 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/02 13:58:59 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_player(t_game *game)
{
	game->hero.x_tile = 0;
	game->hero.y_tile = 0;
	game->sprite_down = "";
	game->hero.addr = "";
	game->hero.bpp = 0;
	game->hero.size_line = 0;
	game->hero.endian = 0;
	return (1);
}

int	init_item(t_game *game)
{
	game->item.x_tile = 0;
	game->item.y_tile = 0;
	game->item.img = "";
	game->item.addr = "";
	game->item.bpp = 0;
	game->item.size_line = 0;
	game->item.endian = 0;
	return (1);
}

int	init_exit(t_game *game)
{
	game->exit.x_tile = 0;
	game->exit.y_tile = 0;
	game->exit.img = "";
	game->exit.addr = "";
	game->exit.bpp = 0;
	game->exit.size_line = 0;
	game->exit.endian = 0;
	return (1);
}

int	init_floor(t_game *game)
{
	game->floor.x_tile = 0;
	game->floor.y_tile = 0;
	game->floor.img = "";
	game->floor.addr = "";
	game->floor.bpp = 0;
	game->floor.size_line = 0;
	game->floor.endian = 0;
	return (1);
}

int	init_wall(t_game *game)
{
	game->wall.x_tile = 0;
	game->wall.y_tile = 0;
	game->wall.img = "";
	game->wall.addr = "";
	game->wall.bpp = 0;
	game->wall.size_line = 0;
	game->wall.endian = 0;
	return (1);
}
