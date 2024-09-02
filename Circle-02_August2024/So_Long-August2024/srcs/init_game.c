/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraband <vbraband@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 13:55:18 by vbraband          #+#    #+#             */
/*   Updated: 2024/09/02 14:55:44 by vbraband         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	init_char(t_game *game)
{
	game->player.x_char = 0;
	game->player.y_char = 0;
	game->player.character = "Capybara";
	game->player.current_direction = DOWN;
	game->player.move_count = 0;
	game->player.inventory = 0;
	return (1);
}

int	init_map(t_game *game)
{
	game->map.item_count = 0;
	game->map.exit_count = 0;
	game->map.hero_count = 0;
	game->map.col_size = 0;
	game->map.line_size = 0;
	game->map.x_map = 0;
	game->map.y_map = 0;
	return (1);
}
void	init_enemy(t_game *game)
{
	game->enemy.x_char = 32;
	game->enemy.y_char = 5;
}

int	init_tile(t_game *game)
{
	if (!init_player(game))
		return (0);
	if (!init_item(game))
		return (0);
	if (!init_exit(game))
		return (0);
	if (!init_floor(game))
		return (0);
	if (!init_wall(game))
		return (0);
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
	if (!init_window(game))
		return (0);
	return (1);
}
